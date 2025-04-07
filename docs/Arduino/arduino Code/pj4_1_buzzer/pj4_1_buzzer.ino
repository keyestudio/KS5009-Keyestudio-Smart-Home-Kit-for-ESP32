#include <BuzzerESP32.h>

BuzzerESP32 buzzer(25); // Initialize buzzer on GPIO25

void setup() 
{
  buzzer.setTimbre(30); // Set timbre (sound quality)
  birthday();          // Play birthday melody
}

void loop() 
{
  // Empty loop as melody plays only once at startup
}

void birthday() 
{
  // Play birthday melody - parameters are (frequency, duration)
  buzzer.playTone(294, 250);  // D4
  buzzer.playTone(440, 250);  // A4
  buzzer.playTone(392, 250);  // G4
  buzzer.playTone(532, 250);  // C5 (slightly sharp)
  buzzer.playTone(494, 250);  // B4
  buzzer.playTone(392, 250);  // G4
  buzzer.playTone(440, 250);  // A4
  buzzer.playTone(392, 250);  // G4
  buzzer.playTone(587, 250);  // D5
  buzzer.playTone(532, 250);  // C5 (slightly sharp)
  buzzer.playTone(392, 250);  // G4
  buzzer.playTone(784, 250);  // G5
  buzzer.playTone(659, 250);  // E5
  buzzer.playTone(532, 250);  // C5 (slightly sharp)
  buzzer.playTone(494, 250);  // B4
  buzzer.playTone(440, 250);  // A4
  buzzer.playTone(698, 250);  // F5
  buzzer.playTone(659, 250);  // E5
  buzzer.playTone(532, 250);  // C5 (slightly sharp)
  buzzer.playTone(587, 250);  // D5
  buzzer.playTone(532, 500);  // C5 (slightly sharp) - longer duration
  buzzer.playTone(0, 0);      // Turn off buzzer
}