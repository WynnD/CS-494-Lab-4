#include <CapacitiveSensor.h>
#include <Mouse.h>

const int LEFT = 0;
const int TOP = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int MOVE_SPEED = 20;
long total0, total1, total2, total3, start;

CapacitiveSensor   cs_5_10 = CapacitiveSensor(5,10);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_5_11 = CapacitiveSensor(5,11);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_5_12 = CapacitiveSensor(5,12);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_5_13 = CapacitiveSensor(5,13);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
   cs_5_10.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   Mouse.begin();
   start = millis();
}

void loop()                    
{
   total0 =  cs_5_10.capacitiveSensor(30);
   total1 =  cs_5_11.capacitiveSensor(30);
   total2 =  cs_5_12.capacitiveSensor(30);
   total3 =  cs_5_13.capacitiveSensor(30);

    /*  
    total 0 is up
    total 1 is right
    total 2 is down
    total 3 is left
    */

    if (total0 > 1000) {
      Serial.println("moving up");
      Mouse.move(0, -MOVE_SPEED, 0);
    }
    if (total1 > 1000) {
      Serial.println("moving right");
      Mouse.move(MOVE_SPEED, 0, 0);
    }
    if (total2 > 2000) {
      Serial.println("moving down");
      Mouse.move(0, MOVE_SPEED, 0);
    }
    if (total3 > 1500) {
      Serial.println("moving left");
      Mouse.move(-MOVE_SPEED, 0, 0);
    }

}
