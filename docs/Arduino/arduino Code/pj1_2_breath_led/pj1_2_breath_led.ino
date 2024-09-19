#include <analogWrite.h>  //导入PWM输出的库文件
#define led_y 12    //定义LED引脚

void setup(){
  pinMode(led_y, OUTPUT);  //设置引脚为输出模式
}

void loop(){
  for(int i=0; i<255; i++)  //for循环语句,不断增加变量i的值，直到最大255时退出循环
  {
    analogWrite(led_y, i);  //PWM输出，控制LED灯亮度
    delay(3);
  }
  for(int i=255; i>0; i--)  //for循环语句,不断减少变量i的值，直到最小0时退出循环
  {
    analogWrite(led_y, i);
    delay(3);
  }
}
