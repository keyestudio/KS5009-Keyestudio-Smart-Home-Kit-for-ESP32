#define btn1 16
#define led_y 12
int btn_count = 0; //用于计算点击按钮的次数

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(led_y, OUTPUT);
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
    if(value == 1)
    {
      digitalWrite(led_y, HIGH);
    }
    else{
      digitalWrite(led_y, LOW);
    }
  }
}                                                                                                                                                            
