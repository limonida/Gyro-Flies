#include <Arduino.h>

#include <Servo.h>

#include <HX711.h>

#include <SD.h>
#include <SPI.h>



//  DONT FORGET TO MAKE WIRING SECURE!!!!!!!!!!!

// red to red
// black to orange
// white to yellow
// green to green


// miso = gray
// mosi = mauve
// sck = blue
// cs = green

// put function declarations here:
// servo
Servo aservo;
Servo bservo;
// sd
const int chipSelect = 5;
// hx711
const int dout711 = 14;
const int sck711 = 15;

HX711 scale; 

void setup() {
  // put your setup code here, to run once:
  /*aservo.attach(12);
  aservo.write(0);
  bservo.attach(13);
  bservo.write(0);
  */
  Serial.begin(57600); delay(10);
  scale.begin(dout711, sck711);
  

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

}


//  DONT FORGET TO MAKE WIRING SECURE!!!!!!!!!!!!


////// !!! remember for adc to use pull-up resistors !!!
//    - might be worth it to get dedicated ones if data is too noisy

/* things that should happen
- test
  - sd write data goes into two categories
    - one labeled drag, one labeled lift
  - tells operator when lift cancels weight
  - warns operator of going too fast (100gf lift increments)
- lift
  - both servos detach at the same time
   - calibration/syncronization sequence for servos ON STARTUP
  - failsafe: dont allow launch past certain speed
  - failsafe: allow for reattachment of servo arms and horrid screaming if it doesnt go right
    - auto detect failure to detach
*/
