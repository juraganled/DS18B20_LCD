#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define ONE_WIRE_BUS 15
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.clear();                      // make sure the LCD is clean
  lcd.backlight();                  // turn on LCD backlight
  sensors.begin();
}


void loop()
{
  // Send the command to get temperatures
  sensors.requestTemperatures();
  
  // We use the function ByIndex to get the temperature from the first sensor
  float tempC = sensors.getTempCByIndex(0);

  lcd.setCursor(0,0);         // set position to column 0, row 0
  lcd.print("Temp = ");       
  lcd.print(tempC);           // print temperature value
  lcd.write(0x0DF);           // print degree symbol
  lcd.print("C");
  delay(1000);                // wait a little while
}
