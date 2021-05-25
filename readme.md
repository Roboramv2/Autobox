![Badge](https://img.shields.io/badge/V1-Proximity-blue)
![Badge](https://img.shields.io/badge/V2-Mobile%20BT-blue)
![Badge](https://img.shields.io/badge/V3-Voice%20command-blue)

### Automated box opening with servo motor:
This model serves as a prototype to implement the concept of servo actuation for closing and opening boxes/dustbins/containers of any kind.
***

# Ultrasonic box:
This version uses an ultrasonic sensor to detect proximity. It opens the box if anyone comes within 10cm and closes it after 6 seconds.

# Bluetooth box:
This version uses a bluetooth module to reeive commands from a mobile phone. It waits for the command ON to open the lid, and closes the lid on the OF command. commands are sent using bluetooth terminal, app found on playstore.

# Voice activated box:
This version uses the simple voice command recognition discussed in [my other repository](https://github.com/Roboramv2/Voice-actuation-for-projects-without-ML). Saying "open" in my voice and intonation will make it open. Similarly for "close". Actuation through api here because necessary drivers in my RPi seem to be corrupted. Results are [posted on youtube](https://www.youtube.com/watch?v=KV4Y6AG7pcw)

# Components used:
1. HC-06: 
    * Bluetooth module for arduino.
    * Works on 3.3 voltage so must use a 2/3 voltage divider for the RX terminal (1kohm, 2kohm)
    * Slave only, so pairing can only be initiated by mobile phone.
    * 4-pin module is used here, as opposed to the 6-pin version.

2. HC-SR04:
    * Measure distance using reflection of sound.
    * No special usage, traditional distance triggered actuation.

3. SG-90:
    * Servo motor for controlled rotation.
    * Extending the horns using screws to provide foothold for the cardboard lid.
    * Said screws are also used to apply force on the cardboard lid.