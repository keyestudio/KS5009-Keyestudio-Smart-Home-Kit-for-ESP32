#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiClient.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN    26
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 4
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

String item = "0";
const char* ssid = "ChinaNet-2.4G-0DF0";
const char* password = "ChinaNet@233";
WiFiServer server(80);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd(0x27,16,2);
#include <analogWrite.h>
#include "xht11.h"
xht11 xht(17);
//#include <ESP32_Servo.h>
//Servo Wservo;
//Servo Dservo;
#include <ESP32Tone.h>
#define buzzer_pin 25
//#define windowServo 5
//#define doorServo 13
#define waterPin 34
#define fanPin1 19
#define fanPin2 18
#define led_y 12  //定义黄色led引脚为12
#define waterPin 34
#define gasPin 23
#define pyroelectric 14

unsigned char dht[4] = {0, 0, 0, 0};//Only the first 32 bits of data are received, not the parity bits

// 舵机通道 
int channel_PWM = 13;
int channel_PWM2 = 10;
int freq_PWM = 50; 
int resolution_PWM = 10;
const int PWM_Pin1 = 5;
const int PWM_Pin2 = 13;




void setup() {
  Serial.begin(115200);
  mylcd.init();
  mylcd.backlight();
  pinMode(led_y, OUTPUT);
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
  ledcSetup(5, 1200, 8);//设置LEDC通道1频率为1200，PWM分辨率为8，即占空比256.
  ledcAttachPin(fanPin2, 5);  //将LEDC通道1绑定到指定的左电机引脚gpio26上以实现输出.
  pinMode(waterPin, INPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(gasPin, INPUT);
  pinMode(pyroelectric, INPUT);
  ledcSetup(channel_PWM, freq_PWM, resolution_PWM); // 设置舵机通道,舵机频率,PWM分辨率.
  ledcSetup(channel_PWM2, freq_PWM, resolution_PWM);
  ledcAttachPin(PWM_Pin1, channel_PWM);  //将LEDC通道绑定到指定 IO 口上以实现输出
  ledcAttachPin(PWM_Pin2, channel_PWM2);  //将LEDC通道绑定到指定 IO 口上以实现输出
//  Wservo.attach(windowServo);
//  Dservo.attach(doorServo);
//  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
//    clock_prescale_set(clock_div_1);
//  #endif
//    // END of Trinket-specific code.
//  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
//  strip.show();            // Turn OFF all pixels ASAP
//  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println("TCP server started");
  MDNS.addService("http", "tcp", 80);
  mylcd.setCursor(0, 0);
  mylcd.print("ip:");
  mylcd.setCursor(0, 1);
  mylcd.print(WiFi.localIP());  //LCD显示ip地址
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
      return;
  }
  while(client.connected() && !client.available()){
      delay(1);
  }
  String req = client.readStringUntil('\r');
  int addr_start = req.indexOf(' ');
  int addr_end = req.indexOf(' ', addr_start + 1);
  if (addr_start == -1 || addr_end == -1) {
      Serial.print("Invalid request: ");
      Serial.println(req);
      return;
  }
  req = req.substring(addr_start + 1, addr_end);
  item=req;
  Serial.println(item);
  String s;
  if (req == "/")  //浏览器访问地址就能读取到client.println(s);发送的信息
  {
      IPAddress ip = WiFi.localIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>ESP32 ip:";
      s += ipStr;
      s += "</html>\r\n\r\n";
      Serial.println("Sending 200");
      client.println(s);  //将字符串S的内容发送出去，使用浏览器访问E智能家居的地址时，就能读取到信息。
  }
  if(req == "/led/on") //浏览器访问ip地址/led/on
  {
    client.println("turn on the LED");
    digitalWrite(led_y, HIGH);
  }
  if(req == "/led/off") //浏览器访问ip地址/led/off
  {
    client.println("turn off the LED");
    digitalWrite(led_y, LOW);
  }
  if(req == "/window/on")
  {
    client.println("open the window");
    ledcWrite(channel_PWM, 100);  //20ms高电平为2.5ms左右 ，也就是2.5/20*1024，此时舵机角度为180°.
    //Wservo.write(175);
  }
  if(req == "/window/off")
  {
    client.println("close the window");
    ledcWrite(channel_PWM, 60);  //20ms高电平为0.5ms左右 ，也就是0.5/20*1024，此时舵机角度为0°.
    //Wservo.write(0);
  }
  if(req == "/music/on")
  {
    //client.println("play music");
  }
  if(req == "/music/off")
  {
    client.println("play music");
    birthday();
    noTone(buzzer_pin,0);
  }
  if(req == "/buz/on")
  {
    client.println("buzzer");
    tone(buzzer_pin,392,250,0);
    Serial.println("1");
  }
  if(req == "/buz/off")
  {
    client.println("off");
    noTone(buzzer_pin,0);
  }
  if(req == "/door/on")
  {
    client.println("open the door");
    ledcWrite(channel_PWM2, 120);
//    Dservo.write(180);
  }
  if(req == "/door/off")
  {
    client.println("close the door");
     ledcWrite(channel_PWM2, 20);
//    Dservo.write(0);
  }
  if(req == "/fan/on")
  {
    client.println("turn on the fan");
    digitalWrite(fanPin1, LOW); //pwm = 0
    ledcWrite(5, 100); //LEDC通道1绑定到指定的左电机输出PWM值为100.
  }
  if(req == "/fan/off")
  {
    client.println("turn off the fan");
    digitalWrite(fanPin1, LOW); //pwm = 0
    ledcWrite(5, 0); //LEDC通道1绑定到指定的左电机输出PWM值为0.
  }
  if(req == "/red/on")
  {
    client.println("red on");
    colorWipe(strip.Color(255,   0,   0), 50);
  }
  if(req == "/red/off")
  {
    client.println("red off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }
  if(req == "/oringe/on")
  {
    client.println("oringe on");
    colorWipe(strip.Color(200,   100,   0), 50);
  }
  if(req == "/oringe/off")
  {
    client.println("oringe off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }
  if(req == "/yellow/on")
  {
    client.println("yellow on");
    colorWipe(strip.Color(200,   200,   0), 50);
  }
  if(req == "/yellow/off")
  {
    client.println("yellow off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }
  if(req == "/green/on")
  {
    client.println("green on");
    colorWipe(strip.Color(0,   255,   0), 50);
  }
  if(req == "/green/off")
  {
    client.println("green off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }
  if(req == "/cyan/on")
  {
    client.println("cyan on");
    colorWipe(strip.Color(0,   100,   255), 50);
  }
  if(req == "/cyan/off")
  {
    client.println("cyan off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }
  if(req == "/blue/on")
  {
    client.println("blue on");
    colorWipe(strip.Color(0,   0,   255), 50);
  }
  if(req == "/blue/off")
  {
    client.println("blue off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }
  if(req == "/purple/on")
  {
    client.println("purple on");
    colorWipe(strip.Color(100,   0,   255), 50);
  }
  if(req == "/purple/off")
  {
    client.println("purple off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }
  if(req == "/white/on")
  {
    client.println("white on");
    colorWipe(strip.Color(255,   255,   255), 50);
  }
  if(req == "/white/off")
  {
    client.println("white off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }
  if(req == "/sfx1/on")
  {
    client.println("sfx1 on");
    rainbow(10);
  }
  if(req == "/sfx1/off")
  {
    client.println("sfx1 off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }
  if(req == "/sfx2/on")
  {
    client.println("sfx2 on");
    theaterChaseRainbow(50);
  }
  if(req == "/sfx2/off")
  {
    client.println("sfx2 off");
    colorWipe(strip.Color(0,   0,   0), 50);
  }


  if(req == "/rain/on")
  {
    int rainVal = analogRead(waterPin);
    client.println(rainVal);
  }
  if(req == "/rain/off")
  {
    client.println("off");
  }
  if(req == "/gas/on")
  {
    boolean gasVal = analogRead(gasPin);
    if(gasVal == 0)
    {
      client.println("safety");
    }
    else
    {
      client.println("dangerous");
    }
  }
  if(req == "/gas/off")
  {
    client.println("off");
  }
  if(req == "/body/on")
  {
    boolean pyroelectric_val = digitalRead(pyroelectric);
    if(pyroelectric_val == 1)
    {
      client.println("someone");
    }
    else
    {
      client.println("no one");
    }
  }
  if(req == "/body/off")
  {
    client.println("off");
  }
  if(req == "/temp/on")
  {
    if (xht.receive(dht)) { //Returns true when checked correctly
      Serial.print("Temp:");
      Serial.print(dht[2]); //The integral part of temperature, DHT [3] is the fractional part
      Serial.println("C");
      delay(200);
    } else {    //Read error
      Serial.println("sensor error");
    }
    client.println(dht[2]);
    delay(1000);  //It takes 1000ms to wait for the device to read
  }
  if(req == "/temp/off")
  {
    client.println("off");
  }
  if(req == "/humidity/on")
  {
    if (xht.receive(dht)) { //Returns true when checked correctly
      Serial.print("Temp:");
      Serial.print(dht[0]); //The integral part of temperature, DHT [3] is the fractional part
      Serial.println("%");
      delay(200);
    } else {    //Read error
      Serial.println("sensor error");
    }
    client.println(dht[0]);
    delay(1000);  //It takes 1000ms to wait for the device to read
  }
  if(req == "/humidity/off")
  {
    client.println("off");
  }

  
  //client.stop();
}


void birthday()
{
  tone(buzzer_pin,294,250,0);  //4个参数分别为，引脚，频率，延时，通道
  tone(buzzer_pin,440,250,0);
  tone(buzzer_pin,392,250,0);
  tone(buzzer_pin,532,250,0);
  tone(buzzer_pin,494,250,0);
  tone(buzzer_pin,392,250,0);
  tone(buzzer_pin,440,250,0);
  tone(buzzer_pin,392,250,0);
  tone(buzzer_pin,587,250,0);
  tone(buzzer_pin,532,250,0);
  tone(buzzer_pin,392,250,0);
  tone(buzzer_pin,784,250,0);
  tone(buzzer_pin,659,250,0);
  tone(buzzer_pin,532,250,0);
  tone(buzzer_pin,494,250,0);
  tone(buzzer_pin,440,250,0);
  tone(buzzer_pin,698,250,0);
  tone(buzzer_pin,659,250,0);
  tone(buzzer_pin,532,250,0);
  tone(buzzer_pin,587,250,0);
  tone(buzzer_pin,532,500,0);
  noTone(buzzer_pin,0);  //关闭
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}
