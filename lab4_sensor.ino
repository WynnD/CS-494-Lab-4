#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_5_10 = CapacitiveSensor(5,10);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_5_11 = CapacitiveSensor(5,11);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_5_12 = CapacitiveSensor(5,12);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_5_13 = CapacitiveSensor(5,13);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
   cs_5_10.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total0 =  cs_5_10.capacitiveSensor(30);
    long total1 =  cs_5_11.capacitiveSensor(30);
    long total2 =  cs_5_12.capacitiveSensor(30);
    long total3 =  cs_5_13.capacitiveSensor(30);

    Serial.print("Time:");
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing
    Serial.print("Sensor10 ");
    Serial.print(total0);                  // print sensor output 1
    Serial.print("\t");
    Serial.print("Sensor11 ");
    Serial.print(total1);                  // print sensor output 2
    Serial.print("\t");
    Serial.print("Sensor12 ");
    Serial.print(total2);                // print sensor output 3
    Serial.print("\t");
    Serial.print("Sensor13 ");
    Serial.println(total3); 

    delay(100);                             // arbitrary delay to limit data to serial port 
}