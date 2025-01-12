#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// display screen size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA 21 // SDA pin
#define OLED_SCL 22 // SCL pin

// create the display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  delay(1000); 

  // initialize I2C communication
  Wire.begin(OLED_SDA, OLED_SCL);

  // initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);  // stop execution if display fails
  }

  display.clearDisplay();
  
  // display line
  display.drawLine(0, 16, 128, 16, WHITE);

  // display text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello ESP32!");
  display.display();
}

void loop() {
  Serial.println("Hello ESP32!");
  delay(1000);
}


// from code given on lab instructions: https://github.com/GIXLabs/TECHIN514_W25/blob/main/Lab%201%20-%20Intro%20to%20PlatformIO/Lab1%20Intro%20to%20PlatformIO.md
// and adapted for the ESP32 with help from ChatGPT 
