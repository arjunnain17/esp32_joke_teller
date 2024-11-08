#include <SPI.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <HTTPClient.h>
#include <ArduinoJson.h>

#define OLED_RESET 1
Adafruit_SSD1306 display(OLED_RESET);
// Filename: kirbyn(1).gif
// Filesize: 2505 Bytes

// Size bitmap: 1024 bytes
const unsigned char kirby [] PROGMEM=
{
// 'Kirby_Nintendo', 128x64px
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xf0, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xf8, 0x03, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xc0, 0x00, 0x3f, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x03, 0xf8, 0x07, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xff, 
0xfe, 0x1f, 0xff, 0x81, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 
0xf8, 0x3f, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 
0xf8, 0x7f, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 
0xf0, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 
0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xff, 
0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0x03, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 
0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0x7f, 0xfe, 0x79, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 
0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x3f, 0xfc, 0xfd, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 
0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x3f, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 
0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 
0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 
0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0e, 0x1f, 0xf8, 0x78, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 
0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 
0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 
0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 
0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 
0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 
0xff, 0x83, 0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 
0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 
0xff, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0xc0, 0x7f, 0xfe, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 
0xff, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0xfe, 0x7f, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 
0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x7f, 
0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 
0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 
0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 
0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 
0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 
0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 
0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 
0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 
0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x07, 0xff, 
0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 
0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0xff, 0xff, 
0xff, 0xfc, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x3f, 0xff, 
0xff, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x07, 0xff, 
0xff, 0xc0, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x03, 0xff, 
0xff, 0x00, 0x80, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 
0xfe, 0x07, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xf0, 0x7f, 
0xfc, 0x1f, 0xe0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x07, 0xf8, 0x1f, 
0xf8, 0x1f, 0xc0, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x03, 0xfc, 0x0f, 
0xf0, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0xf8, 0x0f, 
0xf0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 
0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 
0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 
0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 
0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 
0xff, 0xff, 0xff, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
int count =0;
JsonDocument doc;
String json;

void setup() 
{
  Serial.begin(115200);
  pinMode(4 , INPUT_PULLDOWN);
  pinMode(2 , INPUT_PULLDOWN);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // here the 0x3c is the I2C address, check your i2c address if u have multiple devices.
  display.clearDisplay();
  display.display();
  display.setCursor(0,0);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  WiFi.begin("Kamlesh’s iPhone", "12345678");
  display.println("Connecting");
  display.display();
  while(WiFi.status() != WL_CONNECTED) {
    delay(250);
    display.print(".");
    display.display();
  }
  display.clearDisplay();
  display.display();
  display.println("");
  display.display();
  display.clearDisplay();
  display.display();
  display.setCursor(0,0);
  display.print("Connected to WiFi network with IP Address: ");
  display.println(WiFi.localIP());
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();
  display.setCursor(0,0);
  display.println("Initialized");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
  display.drawBitmap(0 , 0 , kirby , 128 , 64 , WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
}

void loop() 
{
    HTTPClient http;
    http.begin("https://official-joke-api.appspot.com/random_joke");
    if (digitalRead(2) == HIGH){
      http.GET();
      json = http.getString();
      DeserializationError error = deserializeJson(doc, json);
      String setup = doc["setup"];
      display.clearDisplay();
      display.setCursor(0,0);
      display.println(setup);
      display.display();
      delay(200);
    }

    if (digitalRead(4) == HIGH){
      String punch = doc["punchline"];
      display.clearDisplay();
      display.setCursor(0,0);
      display.println(punch);
      display.display();
      delay(200);
    }

}