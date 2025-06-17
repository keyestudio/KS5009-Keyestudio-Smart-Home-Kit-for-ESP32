#include <Arduino.h>
#define led_y 12    // Define LED pin

void setup()
{
  pinMode(led_y, OUTPUT);  // Set pin as output mode
}

void loop()
{
  for(int i = 0; i < 255; i++)  // For loop: increment variable i until it reaches 255
  {
    analogWrite(led_y, i);  // PWM output to control LED brightness
    delay(3);
  }
  
  for(int i = 255; i > 0; i--)  // For loop: decrement variable i until it reaches 0
  {
    analogWrite(led_y, i);
    delay(3);
  }
}