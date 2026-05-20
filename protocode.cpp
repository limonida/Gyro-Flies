#include <Arduino.h>
#include <Servo.h>



//  DONT FORGET TO MAKE WIRING SECURE!!!!!!!!!!!

// red to red
// black to orange
// white to yellow
// green to green

// put function declarations here:
Servo aservo;
Servo bservo;



void setup() {
  // put your setup code here, to run once:
  aservo.attach(7);
  aservo.write(0);
  bservo.attach(2);
  bservo.write(0);

  delay(1000); // maybe run some movement code before the loop 
              // to synchronize the servos?
}

void servo() {
  aservo.write(180);
  bservo.write(180);
  delay(1750);
  aservo.write(90);
  bservo.write(90);
  delay(750);
  aservo.write(0);
  bservo.write(0);
  delay(750);
}


void loop() {
  servo();

}


//  DONT FORGET TO MAKE WIRING SECURE!!!!!!!!!!!!


////// !!! remember for adc to use pull-up resistors !!!
//    - might be worth it to get dedicated ones if data is too noisy
