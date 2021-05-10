# Import libraries
import RPi.GPIO as GPIO
import time
import requests
import pickle

GPIO.setmode(GPIO.BOARD)

#loading pre filtered feature vectors as lists
cl = [0, -14, -14, -14, -15, -11]
op = [-19, -8, -17, -20, -10, -15]

def init(pin):
	GPIO.setup(pin,GPIO.OUT)
	servo1 = GPIO.PWM(pin,50)
	servo1.start(0)
	time.sleep(2)
	return servo1
def openit(servo):
	duty = 2
	while duty <= 7:
		servo1.ChangeDutyCycle(duty)
		time.sleep(0.3)
		servo1.ChangeDutyCycle(0)
		time.sleep(0.7)
		duty = duty + 1
def closeit(servo):
	duty = 7
	while duty >= 2:
		servo.ChangeDutyCycle(duty)
		time.sleep(0.3)
		servo.ChangeDutyCycle(0)
		time.sleep(0.7)
		duty = duty - 1

def rec():
    	response = requests.get(url)
    	res = response.json()
    	return res

def matchit(one, two):
    	diff = [x-y for (x, y) in zip(one, two)]
    	s=0
    	for x in diff:
        	s=s+(x*x)
    	return s

#main loop
servo1 = init(11)
servo1.ChangeDutyCycle(2)
url = "https://fv-transport.herokuapp.com/fv"
while True:
    r = rec()
    if r!=None:
        s1 = matchit(r, op)
		s2 = matchit(r, cl)
		if s1>s2:
			print "closing"
			closeit(servo1)
		else:
			print "opening"
			openit(servo1)
    	else:
        	pass
servo1.stop()
GPIO.cleanup()
