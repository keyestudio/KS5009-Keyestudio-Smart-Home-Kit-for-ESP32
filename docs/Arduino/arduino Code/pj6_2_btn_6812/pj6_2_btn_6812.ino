#define btn1 16
#define btn2 27
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    26
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 4
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int btn_count = 0; //用于计算点击按钮的次数

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
    // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

}

void loop() {
  boolean btn1_val = digitalRead(btn1);
  boolean btn2_val = digitalRead(btn2);
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
          btn_count--;    //自动加1，计算按钮被点击的次数
          if(btn_count <= 0)
          {
            btn_count = 0;
          }
          Serial.println(btn_count);
          btn_state = 0;  //按钮松开了，退出循环
        }
      }
    }
  }
    
  if(btn2_val == 0) //如果按钮被按下了
  {
    delay(10);  //延时10ms，起到消除按钮抖动作用
    if(btn2_val == 0) //再次确定按钮被按下了
    {
      boolean btn_state2 = 1;
      while(btn_state2 == 1) //无限循环，直到按钮被松开
      {
        boolean btn2_val = digitalRead(btn2);
        if(btn2_val == 1)  //如果按钮被松开了
        {
          btn_count++;    //自动加1，计算按钮被点击的次数
          if(btn_count >= 6)
          {
            btn_count = 6;
          }
          Serial.println(btn_count);
          btn_state2 = 0;  //按钮松开了，退出循环
        }
      }
    }
  }

  switch(btn_count)
  {
    case 0: colorWipe(strip.Color(0,   0,   0), 50); break;
    case 1: colorWipe(strip.Color(255,  0,   0), 50); break;
    case 2: colorWipe(strip.Color(0,   255,   0), 50); break;
    case 3: colorWipe(strip.Color(0,   0,   255), 50); break;
    case 4: colorWipe(strip.Color(255,   255,   0), 50); break;
    case 5: colorWipe(strip.Color(255,   0,   255), 50); break;
    case 6: colorWipe(strip.Color(255,   255,   255), 50); break;
  }
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
