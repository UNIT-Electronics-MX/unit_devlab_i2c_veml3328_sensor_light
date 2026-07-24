#include <Wire.h>
#include <DevLab_VEML3328.h>

#define SDA_PIN 6
#define SCL_PIN 7
#define VEML3328_ADDR 0x10

void setup()
{
   Serial.begin(115200);
   delay(500);
   Wire.begin(SDA_PIN, SCL_PIN);
   Wire.setClock(100000);

   uint8_t estado = DevLab_VEML3328.begin(VEML3328_ADDR, &Wire);

   if (estado != 0)
   {
       Serial.println("Error: VEML3328 not detected");
       while (1)
       {
           delay(1000);
       }
   }
   Serial.println("VEML3328 detected");
   Serial.print("Device ID: 0x");
   Serial.println(DevLab_VEML3328.deviceID(), HEX);
}


void loop()
{
   Serial.println("------------------------");

   Serial.print("Red   : ");
   Serial.println(DevLab_VEML3328.getRed());
   
   Serial.print("Green : ");
   Serial.println(DevLab_VEML3328.getGreen());
   
   Serial.print("Blue  : ");
   Serial.println(DevLab_VEML3328.getBlue());
   
   Serial.print("IR    : ");
   Serial.println(DevLab_VEML3328.getIR());
   
   Serial.print("Clear : ");
   Serial.println(DevLab_VEML3328.getClear());
   
   Serial.println();
   delay(2000);
}
