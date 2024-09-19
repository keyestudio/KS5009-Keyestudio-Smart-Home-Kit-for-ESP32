#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd(0x27,16,2);
#define gasPin 23
#define buzPin 25
boolean i = 1;
boolean j = 1;

void setup(){
  Serial.begin(9600);
  mylcd.init();
  mylcd.backlight();
  pinMode(buzPin, OUTPUT);
  pinMode(gasPin, INPUT);
  mylcd.setCursor(0, 0);
  mylcd.print("safety");
}

void loop(){
  boolean gasVal = digitalRead(gasPin);  //读取气体传感器检测到的值
  Serial.println(gasVal);
  if(gasVal == 0)  //如果测到危险气体，LCD显示dangerous，蜂鸣器发出警报声
  {
    while(i == 1)
    {
      mylcd.clear();
      mylcd.setCursor(0, 0);
      mylcd.print("dangerous");
      i = 0;
      j = 1;
    }
    digitalWrite(buzPin,HIGH);
    delay(1);
    digitalWrite(buzPin,LOW);
    delay(1);
  }
  else{
    digitalWrite(buzPin,LOW);
    while(j == 1)
    {
      mylcd.clear();
      mylcd.setCursor(0, 0);
      mylcd.print("safety");
      i = 1;
      j = 0;
    }
  }
}
