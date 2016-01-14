/* Turn an LED on/off based on a command send via BlueTooth
**
** Credit: The following example was used as a reference
** Rui Santos: http://randomnerdtutorials.wordpress.com
*/
#include <Servo.h>
int pos = 0;
int ledPin = 13;  // use the built in LED on pin 13 of the Uno
int state = 0;
int flag = 0;        // make sure that you return the state only once
Servo myServo;
void setup() {
    // sets the pins as outputs:
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    myServo.attach(9,0,360);
    Serial.begin(9600); // Default connection rate for my BT module
}

void loop() {
    //if some data is sent, read it and save it in the state variable
    if(Serial.available() > 0){
      state = Serial.read();
      flag=0;
    }
    // if the state is 0 the led will turn off
    if (state == '0') {
      myServo.detach();

      if(flag == 0){
          Serial.println("Servo: Off");
          flag = 1;
        }
    }
    
    // if the state is 1 the led will turn on
    else if (state == '1') {
        myServo.attach(9);
        myServo.write(0);
        
        if(flag == 0){
          Serial.println("Servo: On & Closing Blinds");
          flag = 1;
        }
    }
    else if(state == '5'){
        myServo.attach(9);
        myServo.write(180);

        if(flag == 0){
          Serial.println("Servo: On & Opening Blinds");
          flag = 1;
       }
    }
}
