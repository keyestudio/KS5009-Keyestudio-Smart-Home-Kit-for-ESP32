#define led_y 12  //定义黄色led引脚为12

void setup() {    //setup函数里面的代码只运行一次
  pinMode(led_y, OUTPUT);  //设置引脚为输出模式
}

void loop() {     //loop函数里面的代码会一直循环运行
  digitalWrite(led_y, HIGH);  //控制led_w引脚输出高电平，也就是点亮LED灯
  delay(200);     //延时语句,单位为ms
  digitalWrite(led_y, LOW);   //控制led_w引脚输出低电平，也就是关闭LED灯
  delay(200);
}
