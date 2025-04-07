#define fanPin1 19    // Fan control pin 1
#define fanPin2 18    // Fan control pin 2
#define btn1 16       // Button 1 pin
#define btn2 27       // Button 2 pin

int btn_count = 0;    // Counter for button 1 presses
int btn_count2 = 0;   // Counter for button 2 presses
int speed_val = 130;  // Initial fan speed (PWM value)

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
}

void loop() {
  boolean btn1_val = digitalRead(btn1);
  
  // Button 1 (Power/Speed Control) handling
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
          btn_count++;    // Increment press counter
          Serial.println(btn_count);
          btn_state = 0;  // Exit loop
        }
      }
    }
    
    boolean power_state = btn_count % 2; // Toggle power state (0 or 1)
    
    while(power_state == 1) // While fan is on
    {
      digitalWrite(fanPin1, LOW);  // Set direction
      analogWrite(fanPin2, speed_val); // Set speed
      
      // Button 2 (Speed Adjustment) handling
      boolean btn2_val = digitalRead(btn2);
      if(btn2_val == 0) // If speed button pressed
      {
        delay(10); // Debounce delay
        if(btn2_val == 0) // Confirm press
        {
          boolean btn_state2 = 1;
          while(btn_state2 == 1) // Wait for release
          {
            boolean btn2_val = digitalRead(btn2);
            if(btn2_val == 1) // If released
            {
              btn_count2++; // Increment speed level
              if(btn_count2 > 3) // Cycle through 1-3
              {
                btn_count2 = 1;
              }
              
              // Set speed based on count
              switch(btn_count2)
              {
                case 1: 
                  speed_val = 130; // Low speed
                  Serial.println(speed_val);
                  break;
                case 2: 
                  speed_val = 180; // Medium speed
                  Serial.println(speed_val);
                  break;
                case 3: 
                  speed_val = 230; // High speed
                  Serial.println(speed_val);
                  break;
              }
              btn_state2 = 0;
            }
          }
        }
      }
      
      // Check for power off
      btn1_val = digitalRead(btn1);
      if(btn1_val == 0) // If power button pressed
      {
        delay(10); // Debounce delay
        if(btn1_val == 0) // Confirm press
        {
          digitalWrite(fanPin1, LOW); // Stop fan
          analogWrite(fanPin2, 0);
          power_state = 0;  // Exit fan control loop
        }
      }
    }
  }
}