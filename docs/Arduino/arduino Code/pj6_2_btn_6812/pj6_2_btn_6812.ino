#define btn1 16    // Button 1 pin
#define btn2 27    // Button 2 pin

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN    26    // NeoPixel data pin
#define LED_COUNT 4      // Number of NeoPixels
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int btn_count = 0; // Counter for button presses

void setup() 
{
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif

  strip.begin();           // Initialize NeoPixel strip
  strip.show();            // Turn off all pixels
  strip.setBrightness(50); // Set brightness (max 255)
}

void loop() 
{
  boolean btn1_val = digitalRead(btn1);
  boolean btn2_val = digitalRead(btn2);
  
  // Button 1 (Decrement) handling
  if(btn1_val == 0) // If button is pressed
  {
    delay(10);  // Debounce delay
    if(btn1_val == 0) // Confirm button press
    {
      boolean btn_state = 1;
      while(btn_state == 1) // Wait for button release
      {
        boolean btn_val = digitalRead(btn1);
        if(btn_val == 1)  // If button released
        {
          btn_count--;    // Decrement counter
          if(btn_count <= 0) // Limit minimum value
          {
            btn_count = 0;
          }
          Serial.println(btn_count);
          btn_state = 0;  // Exit loop
        }
      }
    }
  }
    
  // Button 2 (Increment) handling  
  if(btn2_val == 0) // If button is pressed
  {
    delay(10);  // Debounce delay
    if(btn2_val == 0) // Confirm button press
    {
      boolean btn_state2 = 1;
      while(btn_state2 == 1) // Wait for button release
      {
        boolean btn2_val = digitalRead(btn2);
        if(btn2_val == 1)  // If button released
        {
          btn_count++;    // Increment counter
          if(btn_count >= 6) // Limit maximum value
          {
            btn_count = 6;
          }
          Serial.println(btn_count);
          btn_state2 = 0;  // Exit loop
        }
      }
    }
  }

  // Change LED color based on button count
  switch(btn_count)
  {
    case 0: colorWipe(strip.Color(0,   0,   0), 50); break;    // Off
    case 1: colorWipe(strip.Color(255,  0,   0), 50); break;   // Red
    case 2: colorWipe(strip.Color(0,   255,   0), 50); break;  // Green
    case 3: colorWipe(strip.Color(0,   0,   255), 50); break;  // Blue
    case 4: colorWipe(strip.Color(255, 255,   0), 50); break;  // Yellow
    case 5: colorWipe(strip.Color(255, 0,   255), 50); break;  // Magenta
    case 6: colorWipe(strip.Color(255, 255, 255), 50); break;  // White
  }
}

// Fill strip with one color
void colorWipe(uint32_t color, int wait) 
{
  for(int i=0; i<strip.numPixels(); i++) 
  { 
    strip.setPixelColor(i, color); // Set pixel color
    strip.show();                  // Update strip
    delay(wait);                   // Pause
  }
}