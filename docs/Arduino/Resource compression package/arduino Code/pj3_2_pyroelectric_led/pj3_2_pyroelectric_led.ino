#define pyroelectric 14
#define led_y 12  // Yellow LED pin definition

void setup() 
{
  Serial.begin(9600);
  pinMode(pyroelectric, INPUT);
  pinMode(led_y, OUTPUT);  // Set pin as output mode
}

void loop() 
{
  boolean pyroelectric_val = digitalRead(pyroelectric);
  
  Serial.print("pyroelectric value = ");
  Serial.println(pyroelectric_val);
  
  delay(200);
  
  if(pyroelectric_val == 1)
  {
    digitalWrite(led_y, HIGH);  // Turn LED on when motion detected
  }
  else
  {
    digitalWrite(led_y, LOW);   // Turn LED off when no motion
  }
}