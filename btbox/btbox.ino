#include <Servo.h>
#include <SoftwareSerial.h>
Servo servo;
SoftwareSerial BTserial(2,3);
int angle;
int distance;
long duration;
int d;
boolean debug = true;
const byte numChars = 20;
char receivedChars[numChars];
boolean newData = false; 

void parseData()
{  
        newData = false;    
        if (debug) {  Serial.println( receivedChars ); }
        if (receivedChars[0] == 'O'  && receivedChars[1] == 'N' )  { openlid(); delay(5000);  }
        if (receivedChars[0] == 'O'  && receivedChars[1] == 'F' )  { closelid(); delay(1000);   }       
}

void recvWithStartEndMarkers() 
{ 
     static boolean recvInProgress = false;
     static byte ndx = 0;
     char startMarker = '<';
     char endMarker = '>';
     char rc;
 
     if (BTserial.available() > 0) 
     {
          rc = BTserial.read();
          if (recvInProgress == true) 
          {
               if (rc != endMarker) 
               {
                    receivedChars[ndx] = rc;
                    ndx++;
                    if (ndx >= numChars) { ndx = numChars - 1; }
               }
               else 
               {
                     receivedChars[ndx] = '\0'; // terminate the string
                     recvInProgress = false;
                     ndx = 0;
                     newData = true;
               }
          }
 
          else if (rc == startMarker) { recvInProgress = true; }
     }
}

void closelid() {
  servo.write(0);
  delay(2000);
}

void openlid() {
  servo.write(20);
  delay(500);
  servo.write(40);
  delay(500);
  servo.write(60);
  delay(500);
}

void setup() {
  servo.attach(12);
  Serial.begin(9600);
  BTserial.begin(9600); 
}

void loop() {
  if (BTserial.available() > 0)     {  recvWithStartEndMarkers(); }
  if (newData) { parseData(); }
}
