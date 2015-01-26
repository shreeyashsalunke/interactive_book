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
int pbIn = 0;   
int back = 0;// Interrupt 0 is on DIGITAL PIN 2!
int word_num = 0;  
int potPin = A0;    // select the input pin for the potentiometer
const int ledPin =  13;      // the number of the LED pin
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13

// variables will change:
int enterState = 0;         // variable for reading the pushbutton status
int backState = 0;         // variable for reading the pushbutton status
int potValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(pbIn, INPUT);     
  pinMode(back, INPUT);     
  pinMode(potPin, INPUT);     
  Serial.begin(9600);
  attachInterrupt(pbIn, stateChange, RISING);

}

void stateChange()
{
Serial.println("In Interrupt Loop");
  switch (word_num) {
  case 1:    // your hand is close to the sensor
    Serial.write(11);
    break;
  case 2:    // your hand is a few inches from the sensor
    Serial.write(21);
    break;
  case 3:    // your hand is nowhere near the sensor
    Serial.write(31);
    break;
  case 4:    // your hand is nowhere near the sensor
    Serial.write(41);
    break;   
  } 

}

void loop(){
  // read the state of the pushbutton value:
  enterState = digitalRead(pbIn);
  backState = digitalRead(back);
  potValue = analogRead(potPin);    
//  potValue = map(potValue, 0, 1023, 0, 255);
//Serial.write(potValue);

delay(100);

if(potValue>100 && potValue<150)
{
Serial.write(1);
word_num = 1;
}
else if(potValue>250 && potValue<300)
{
Serial.write(2);
word_num = 2;
}
else if(potValue>400 && potValue<450)
{
Serial.write(3);
word_num = 3;
}
else if(potValue>550 && potValue<600)
{
Serial.write(4);
word_num = 4;
}

}
