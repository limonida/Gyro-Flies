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
const int Bdout711 = 3;
const int Bsck711 = 2;

const int Rdout711 = 6;
const int Rsck711 = 5;

HX711 Rscale; 
HX711 Bscale;

void setup() {
  // put your setup code here, to run once:
  /*aservo.attach(12);
  aservo.write(0);
  bservo.attach(13);
  bservo.write(0);
  */
  Serial.begin(57600); delay(10);
  Rscale.begin(Rdout711, Rsck711);
  Bscale.begin(Bdout711, Bsck711);


  
  if (Rscale.is_ready(), Bscale.is_ready()) {
    Rscale.set_scale(-409.0174);   
    Bscale.set_scale(-458.0696);
    Serial.println("Tare...");
    delay(5000);
    Rscale.tare();
    Bscale.tare();
    Serial.println("Tare done, read in 5 seconds...");
    delay(5000);
  } else {
    Serial.println("hx711 not found");
  }
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
  
    Serial.print("Rcell result: ");
    Serial.print(Rscale.get_units(5), 1);
    Serial.print(" | Bcell result: ");
    Serial.println(Bscale.get_units(5), 1);
  
}


// pixel 10 pro full weight: 242g
// redcell: 99700 for 242g, cal fac = -411.9835

//  DONT FORGET TO MAKE WIRING SECURE!!!!!!!!!!!!

// bcell run 1: 110650 (normal down)
// bcell: 110852 for 242g, cal fac = -458.0696

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
