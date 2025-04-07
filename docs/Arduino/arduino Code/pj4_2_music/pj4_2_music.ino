#include <ESP32Tone.h>
#include <musicESP32_home.h>   
music Music(25);
#define btn1 16
int btn_count = 0; //用于计算点击按钮的次数
boolean music_flag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(25, OUTPUT);
//  Music.tetris();
//  Music.birthday();
//  Music.Ode_to_Joy();
//  Music.christmas();
//  Music.super_mario();
//  Music.star_war_tone();
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
          music_flag = 1;
          btn_count++;    //自动加1，计算按钮被点击的次数
          Serial.println(btn_count);
          if(btn_count == 4)
          {
            btn_count = 1;
          }
          switch(btn_count)
          {
            case 1: if(music_flag == 1){Music.Ode_to_Joy();music_flag=0;} break;
            case 2: if(music_flag == 1){Music.christmas();music_flag=0;} break;
            case 3: if(music_flag == 1){Music.tetris();music_flag=0;} break;
          }
          btn_state = 0;  //按钮松开了，退出循环
        }
      }
    }
  }
}
