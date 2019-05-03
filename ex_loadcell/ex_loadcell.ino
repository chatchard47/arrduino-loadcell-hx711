#include "HX711.h"

float calibration_factor =335186.00; 
#define zero_factor 0
#define DOUT  A3
#define CLK   A2
#define DEC_POINT  2

float offset=0;
float get_units_kg();

HX711 scale;

void setup() 
{
  Serial.begin(115200);
  Serial.println("Load Cell");
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); 
  scale.set_offset(zero_factor);   
}
void loop() 
{ 
  Serial.print("Reading: ");
  if((get_units_kg()+offset)-0.23 > 0){
    String data = String(0);
    Serial.print(data);
    Serial.println(" kg");
  } else if((get_units_kg()+offset)-0.23 < 5){
    String data = String((get_units_kg()+offset)-0.23, DEC_POINT);
    Serial.print(data);
    Serial.println(" kg");
  }
}
float get_units_kg()
{
  return(scale.get_units()*0.453592);
}
