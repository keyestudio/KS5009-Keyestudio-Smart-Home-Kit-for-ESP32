#include <musicESP32_home.h>   
music Music(25);  // Initialize music player on GPIO25
#define btn1 16    // Button pin
int btn_count = 0; // Counter for button presses
boolean music_flag = 0; // Flag to trigger music playback

void setup() 
{
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  // Available music options:
  // Music.tetris();
  // Music.birthday();
  // Music.Ode_to_Joy();
  // Music.christmas();
  // Music.star_war_tone();
}

void loop() 
{
  boolean btn1_val = digitalRead(btn1);
  
  if(btn1_val == 0) // If button is pressed
  {
    delay(10);  // 10ms delay for debouncing
    
    if(btn1_val == 0) // Confirm button is still pressed
    {
      boolean btn_state = 1;
      
      while(btn_state == 1) // Wait until button is released
      {
        boolean btn_val = digitalRead(btn1);
        
        if(btn_val == 1)  // If button is released
        {
          music_flag = 1;
          btn_count++;    // Increment press counter
          Serial.println(btn_count);
          
          // Cycle through 1-3 count
          if(btn_count == 4)
          {
            btn_count = 1;
          }
          
          // Play different song based on press count
          switch(btn_count)
          {
            case 1: 
              if(music_flag == 1)
              {
                Music.Ode_to_Joy();
                music_flag=0;
              } 
              break;
              
            case 2: 
              if(music_flag == 1)
              {
                Music.christmas();
                music_flag=0;
              } 
              break;
              
            case 3: 
              if(music_flag == 1)
              {
                Music.tetris();
                music_flag=0;
              } 
              break;
          }
          
          btn_state = 0;  // Exit wait loop
        }
      }
    }
  }
}