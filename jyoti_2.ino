/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int enter = 2;     // the number of the pushbutton pin
const int back = 3;  
int potPin = A0;    // select the input pin for the potentiometer
const int ledPin =  13;      // the number of the LED pin
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13

// variables will change:
#include <TimerOne.h>
int enterState = 0;         // variable for reading the pushbutton status
int backState = 0;         // variable for reading the pushbutton status
int potValue = 0;  // variable to store the value coming from the sensor
int wnum = 0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(enter, INPUT);     
  pinMode(back, INPUT);     
  pinMode(potPin, INPUT);     
  Serial.begin(9600);
  //Timer1.initialize(100000);
  //Timer1.attachInterrupt(button_press); // blinkLED to run every 0.15 seconds
attachInterrupt(enter, button_press, HIGH); // blinkLED to run every 0.15 seconds

}

void button_press()
{

  Serial.println(11);
}
  
  


void loop(){
  // read the state of the pushbutton value:
  enterState = digitalRead(enter);
  backState = digitalRead(back);
  potValue = analogRead(potPin);    
  //potValue = map(potValue, 0, 1023, 0, 255);
//Serial.write(potValue);


if(potValue>100 && potValue<150)
{
Serial.println(1);
wnum = 1;
}
else if(potValue>250 && potValue<300)
{
Serial.println(2);
wnum = 2;
}
else if(potValue>400 && potValue<450)
{
Serial.println(3);
wnum = 3;
}
else if(potValue>550 && potValue<600)
{
Serial.println(4);
wnum = 4;
}


  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (enterState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }


  if (backState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
  //wnum = 0;
}
