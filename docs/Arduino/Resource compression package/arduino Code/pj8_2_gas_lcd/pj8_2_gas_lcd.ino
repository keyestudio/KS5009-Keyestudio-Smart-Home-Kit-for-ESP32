#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD with I2C address 0x27, 16 columns and 2 rows
LiquidCrystal_I2C mylcd(0x27, 16, 2);

#define gasPin 23    // Gas sensor input pin
#define buzPin 25    // Buzzer output pin

// State flags for LCD display updates
boolean dangerDisplayed = 1;
boolean safetyDisplayed = 1;

void setup() {
  Serial.begin(9600);
  
  // Initialize LCD
  mylcd.init();
  mylcd.backlight();
  
  // Set pin modes
  pinMode(buzPin, OUTPUT);
  pinMode(gasPin, INPUT);
  
  // Display initial message
  mylcd.setCursor(0, 0);
  mylcd.print("safety");
}

void loop() {
  boolean gasVal = digitalRead(gasPin);  // Read gas sensor value
  Serial.println(gasVal);
  
  if(gasVal == 0)  // If dangerous gas detected
  {
    while(dangerDisplayed == 1)  // Update display if needed
    {
      mylcd.clear();
      mylcd.setCursor(0, 0);
      mylcd.print("dangerous");
      dangerDisplayed = 0;
      safetyDisplayed = 1;
    }
    
    // Sound alarm buzzer (short pulses)
    digitalWrite(buzPin, HIGH);
    delay(1);
    digitalWrite(buzPin, LOW);
    delay(1);
  }
  else  // No dangerous gas detected
  {
    digitalWrite(buzPin, LOW);  // Ensure buzzer is off
    
    while(safetyDisplayed == 1)  // Update display if needed
    {
      mylcd.clear();
      mylcd.setCursor(0, 0);
      mylcd.print("safety");
      dangerDisplayed = 1;
      safetyDisplayed = 0;
    }
  }
}