#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd(0x27,16,2);
#include <dht11.h>

// Define the pin constants
const int DHT11PIN = 17; // Temperature and humidity sensor pin
dht11 DHT11; // Initialize dht11

void setup() {
  Serial.begin(9600);//Start the serial monitor and set the baud rate to 9600
  mylcd.init();
  mylcd.backlight();
  mylcd.clear();
}

void loop() {
   //Define two temperature and humidity values
   int Temperature;
   int Humidity;
   //Obtain data
   int chk = DHT11.read(DHT11PIN); 
   Temperature = DHT11.temperature;
   Humidity = DHT11.humidity;
   // Display the temperature information at the corresponding position on the LCD
   mylcd.setCursor(0, 0);
   mylcd.print("Temp:");
   mylcd.setCursor(5, 0);
   mylcd.print(Temperature); 
   mylcd.setCursor(8, 0);
   mylcd.print("C");
   // Display humidity information at the corresponding position on the LCD
   mylcd.setCursor(0, 1);
   mylcd.print("Hum:");
   mylcd.setCursor(5, 1);
   mylcd.print(Humidity);
   mylcd.setCursor(8, 1);
   mylcd.print("%RH");
   delay(500);
}
