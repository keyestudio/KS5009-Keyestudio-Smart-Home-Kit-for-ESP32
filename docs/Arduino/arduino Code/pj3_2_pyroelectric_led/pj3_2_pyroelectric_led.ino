#define pyroelectric 14
#define led_y 12  //定义黄色led引脚为12

void setup() {
  Serial.begin(9600);
  pinMode(pyroelectric, INPUT);
  pinMode(led_y, OUTPUT);  //设置引脚为输出模式
}

void loop() {
  boolean pyroelectric_val = digitalRead(pyroelectric);
  Serial.print("pyroelectric value = ");
  Serial.println(pyroelectric_val);
  delay(200);
  if(pyroelectric_val == 1)
  {
    digitalWrite(led_y, HIGH);
  }else{
    digitalWrite(led_y, LOW);
  }
}
