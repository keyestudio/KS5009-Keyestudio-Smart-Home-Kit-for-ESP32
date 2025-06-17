#define btn1 16
#define btn2 27

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() {
  boolean btn1_val = digitalRead(btn1);
  boolean btn2_val = digitalRead(btn2);
  Serial.print("button1 = ");
  Serial.print(btn1_val);
  Serial.print("   ");
  Serial.print("button2 = ");
  Serial.println(btn2_val);
  delay(100);
}
