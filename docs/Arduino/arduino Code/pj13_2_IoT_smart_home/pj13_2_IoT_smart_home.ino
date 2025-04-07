#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiClient.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN    26
#define LED_COUNT 4                                      // Number of NeoPixels attached
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

String item = "0";
const char* ssid = "LieBaoWiFi359";
const char* password = "wmbd315931";
WiFiServer server(80);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd(0x27,16,2);
#include "xht11.h"
xht11 xht(17);

#include <BuzzerESP32.h>
#define buzzer_pin 25
BuzzerESP32 buzzer(buzzer_pin);                          // GPIO25

#define waterPin 34
#define fanPin1 19
#define fanPin2 18
#define led_y 12                                         // Yellow LED pin definition
#define gasPin 23
#define pyroelectric 14

unsigned char dht[4] = {0, 0, 0, 0};                    // Only first 32 bits received (no parity bits)

// Servo channels
int channel_PWM = 13;
int channel_PWM2 = 10;
int freq_PWM = 50; 
int resolution_PWM = 10;
const int PWM_Pin1 = 5;
const int PWM_Pin2 = 13;

void setup() 
{
  Serial.begin(115200);
  mylcd.init();
  mylcd.backlight();
  pinMode(led_y, OUTPUT);
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
  pinMode(waterPin, INPUT);

  buzzer.setTimbre(30);                                  // Set timbre
  buzzer.playTone(0,0);                                  // Turn off buzzer

  pinMode(gasPin, INPUT);
  pinMode(pyroelectric, INPUT);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
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
  mylcd.print(WiFi.localIP());                           // Display IP on LCD
}

void loop() 
{
  WiFiClient client = server.available();
  if (!client) 
  {
      return;
  }
  while(client.connected() && !client.available())
  {
      delay(1);
  }
  String req = client.readStringUntil('\r');
  int addr_start = req.indexOf(' ');
  int addr_end = req.indexOf(' ', addr_start + 1);
  if (addr_start == -1 || addr_end == -1) 
  {
      Serial.print("Invalid request: ");
      Serial.println(req);
      return;
  }
  req = req.substring(addr_start + 1, addr_end);
  item=req;
  Serial.println(item);
  String s;
  if (req == "/")                                       // Browser can read information sent by client.println(s)
  {
      IPAddress ip = WiFi.localIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>ESP32 ip:";
      s += ipStr;
      s += "</html>\r\n\r\n";
      Serial.println("Sending 200");
      client.println(s);                                // Send string content - readable when accessing smart home address
  }
  if(req == "/led/on")                                  // IP address/led/on
  {
    client.println("turn on the LED");
    digitalWrite(led_y, HIGH);
  }
  if(req == "/led/off")                                 // IP address/led/off
  {
    client.println("turn off the LED");
    digitalWrite(led_y, LOW);
  }
  if(req == "/window/on")
  {
    client.println("open the window");
    ledcWrite(channel_PWM, 100);                        // 2.5ms high pulse (2.5/20*1024) = 180° servo angle
  }
  if(req == "/window/off")
  {
    client.println("close the window");
    ledcWrite(channel_PWM, 60);                         // 0.5ms high pulse = 0° servo angle
  }
  if(req == "/music/on")
  {
    //client.println("play music");
  }
  if(req == "/music/off")
  {
    client.println("play music");
    birthday();
    buzzer.playTone(0,0);
  }
  if(req == "/buz/on")
  {
    client.println("buzzer");
    buzzer.playTone(392,250);
    Serial.println("1");
  }
  if(req == "/buz/off")
  {
    client.println("off");
    buzzer.playTone(0,0);
  }
  if(req == "/door/on")
  {
    client.println("open the door");
    ledcWrite(channel_PWM2, 120);
  }
  if(req == "/door/off")
  {
    client.println("close the door");
    ledcWrite(channel_PWM2, 20);
  }
  if(req == "/fan/on")
  {
    client.println("turn on the fan");
    digitalWrite(fanPin1, LOW);                         // pwm = 0
    ledcWrite(5, 100);                                  // LEDC channel 1 PWM output = 100
  }
  if(req == "/fan/off")
  {
    client.println("turn off the fan");
    digitalWrite(fanPin1, LOW);                         // pwm = 0
    ledcWrite(5, 0);                                    // LEDC channel 1 PWM output = 0
  }
  // Color control endpoints follow same pattern...
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
    if (xht.receive(dht))                               // Returns true on successful read
    { 
      Serial.print("Temp:");
      Serial.print(dht[2]);                             // Integer part of temperature
      Serial.println("C");
      delay(200);
    } 
    else                                                // Read error
    {    
      Serial.println("sensor error");
    }
    client.println(dht[2]);
    delay(1000);                                        // Wait 1000ms for device read
  }
  if(req == "/temp/off")
  {
    client.println("off");
  }
  if(req == "/humidity/on")
  {
    if (xht.receive(dht))                               // Returns true on successful read
    { 
      Serial.print("Humidity:");
      Serial.print(dht[0]);                             // Integer part of humidity
      Serial.println("%");
      delay(200);
    } 
    else                                                // Read error
    {    
      Serial.println("sensor error");
    }
    client.println(dht[0]);
    delay(1000);                                        // Wait 1000ms for device read
  }
  if(req == "/humidity/off")
  {
    client.println("off");
  }
}

// Birthday melody function
void birthday() 
{
  buzzer.playTone(294,250);                             // Parameters: frequency, duration
  buzzer.playTone(440,250);
  buzzer.playTone(392,250);
  buzzer.playTone(532,250);
  buzzer.playTone(494,250);
  buzzer.playTone(392,250);
  buzzer.playTone(440,250);
  buzzer.playTone(392,250);
  buzzer.playTone(587,250);
  buzzer.playTone(532,250);
  buzzer.playTone(392,250);
  buzzer.playTone(784,250);
  buzzer.playTone(659,250);
  buzzer.playTone(532,250);
  buzzer.playTone(494,250);
  buzzer.playTone(440,250);
  buzzer.playTone(698,250);
  buzzer.playTone(659,250);
  buzzer.playTone(532,250);
  buzzer.playTone(587,250);
  buzzer.playTone(532,500);
  buzzer.playTone(0,0);                                 // Turn off
}

// NeoPixel effect functions (colorWipe, rainbow, theaterChaseRainbow remain unchanged)