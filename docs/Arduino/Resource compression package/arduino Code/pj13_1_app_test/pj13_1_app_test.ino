#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <LiquidCrystal_I2C.h>

#define fanPin1 19 //IN+ pin
#define fanPin2 18 //IN- pin
#define led_y 12  //Define the yellow led pin as 12

const char* ssid = "ChinaNet-2.4G-0DF0";
const char* pwd = "ChinaNet@233";

#include <Wire.h>
//Initialize the LCD address, columns and rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

WiFiServer server(80);  //Initialize the WiFi service

//Define the variable as the detected value
String request;

unsigned long prevTask = 0;

void setup() {
  Serial.begin(9600);
  //Connect to wifi
  WiFi.begin(ssid, pwd);
  //Determine whether it is connected
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  delay(1000);
  //The serial monitor will display the name and IP address of the wireless network
  Serial.println("Connected to WiFi");
  Serial.print("WiFi NAME:");
  Serial.println(ssid);
  Serial.print("IP:");
  Serial.println(WiFi.localIP());

  //Initialize the LCD
  lcd.init();
  //Turn on the LCD backlight
  lcd.backlight();
  //lcd.noBacklight();
  lcd.clear();
  //Set the position of the cursor
  lcd.setCursor(0, 0);
  //LCD printing
  lcd.print("IP:");
  //Set the position of the cursor
  lcd.setCursor(0, 1);
  //LCD printing
  lcd.print(WiFi.localIP());

  //Set pin modes
  pinMode(led_y, OUTPUT);
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
  //Start the service
  server.begin();
}

void loop() {
  //Check whether the client has been connected to the network server
  //When the client establishes a connection with the server, the "server.available()" function returns a WiFiClient object for client-side communication.
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected");
    while (client.connected()) {
      //Determine whether the server sends data
      if (client.available()) {
        request = client.readStringUntil('s');
        Serial.print("Received message: ");
        Serial.println(request);
      }

      //LED
      if (request == "a") {
        digitalWrite(led_y, HIGH);
      } else if (request == "A") {
        digitalWrite(led_y, LOW);
      }

      //fan
      if (request == "f") {
        digitalWrite(fanPin1, LOW); //pwm = 0
        analogWrite(fanPin2, 100); //LEDC channel 5 is bound to the specified left motor output PWM value as 100.
      } else if (request == "F") {
        digitalWrite(fanPin1, LOW); //pwm = 0
        analogWrite(fanPin2, 0); //LEDC channel 5 is bound to the specified left motor output PWM value as 0.
      }

      request = "";
    }
    Serial.println("Client disconnected");
  }
}

