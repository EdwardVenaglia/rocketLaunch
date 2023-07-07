#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int buttonPin1 = 2;  // the number of the pushbutton pin
const int buttonPin2 = 3;  // the number of the pushbutton pin

int buttonState1 = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;  // variable for reading the pushbutton status
int incomingdata;

void setup() {
  myservo.attach(9);  //servo on pin 9 
  
  // pushbutton pins as inputs:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  
  Serial.begin(9600);  // Starts the serial communication only for remote control (via COM port)
}

void loop(){
  if(Serial.available() > 0){  // Check if data is available to read
    incomingdata = Serial.read();  // Read the incoming data
  }
  
  // read the state of the pushbuttons:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed or if signal has been received through COMS:
  if (buttonState1 == HIGH || incomingdata == '1') {
    // turn servo to 190 degrees slowly:
    for (int pos = 90; pos <= 170; pos += 1) {
      myservo.write(pos);
      delay(1500 / 100);  // delay 1.5 seconds for effect
    }
  } 
  if(buttonState2 == HIGH || incomingdata == '2') {
    // turn servo to 90 degrees slowly:
    for (int pos = 170; pos >= 90; pos -= 1) {
      myservo.write(pos);
      delay(1500 / 100);
    }
  }
}

