#include <analogWrite.h>
#define fanPin1 19
#define fanPin2 18
#define btn1 16
int btn_count = 0; //用于计算点击按钮的次数
#define btn2 27
int btn_count2 = 0;
int speed_val = 130; //定义速度的变量

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
}

void loop() {
  boolean btn1_val = digitalRead(btn1);
  if(btn1_val == 0) //如果按钮被按下了
  {
    delay(10);  //延时10ms，起到消除按钮抖动作用
    if(btn1_val == 0) //再次确定按钮被按下了
    {
      boolean btn_state = 1;
      while(btn_state == 1) //无限循环，直到按钮被松开
      {
        boolean btn_val = digitalRead(btn1);
        if(btn_val == 1)  //如果按钮被松开了
        {
          btn_count++;    //自动加1，计算按钮被点击的次数
          Serial.println(btn_count);
          btn_state = 0;  //按钮松开了，退出循环
        }
      }
    }
    boolean value = btn_count % 2; //对值求余数，得到0或1
    while(value == 1)
    {
      //Serial.println("on");
      digitalWrite(fanPin1, LOW); //pwm = 0
      analogWrite(fanPin2, speed_val);
      
      boolean btn2_val = digitalRead(btn2);
      if(btn2_val == 0)
      {
        delay(10);
        if(btn2_val == 0)
        {
          boolean btn_state2 = 1;
          while(btn_state2 == 1)
          {
            boolean btn2_val = digitalRead(btn2);
            if(btn2_val == 1)
            {
              btn_count2++;
              if(btn_count2 > 3)
              {
                btn_count2 = 1;
              }
              switch(btn_count2)
              {
                case 1: speed_val = 130; Serial.println(speed_val);break;  //调速
                case 2: speed_val = 180; Serial.println(speed_val);break;
                case 3: speed_val = 230; Serial.println(speed_val);break;
              }
              btn_state2 = 0;
            }
          }
        }
      }
      boolean btn1_val = digitalRead(btn1);
      if(btn1_val == 0) //如果按钮被按下了
      {
        digitalWrite(fanPin1, LOW); //pwm = 0
        analogWrite(fanPin2, 0);
        value = 0;  //退出循环
      }
      
    }
  }
}                                                                                                                                                       
