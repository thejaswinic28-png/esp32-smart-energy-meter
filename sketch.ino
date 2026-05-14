#include <WiFi.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WiFiClient client;

unsigned long channelID = 3382306;
const char* writeAPIKey = "4C2BJBREN77UO9IV";

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Potentiometer pin
const int sensorPin = 34;

void setup() {

  Serial.begin(115200);

  // LCD
  lcd.init();
  lcd.backlight();

  // WiFi
  WiFi.begin(ssid, password);

  lcd.setCursor(0,0);
  lcd.print("Connecting WiFi");

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WiFi Connected");

  // ThingSpeak
  ThingSpeak.begin(client);

  delay(2000);
}

void loop() {

  // Read potentiometer
  int sensorValue = analogRead(sensorPin);

  // Simulated current (0–10A)
  float current = map(sensorValue, 0, 4095, 0, 10);

  // Simulated voltage
  float voltage = 230.0;

  // Power calculation
  float power = voltage * current;

  // Serial Output
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  Serial.print("Power: ");
  Serial.print(power);
  Serial.println(" W");

  // LCD Display
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("I:");
  lcd.print(current);
  lcd.print("A");

  lcd.setCursor(0,1);
  lcd.print("P:");
  lcd.print(power);
  lcd.print("W");

  // ThingSpeak Upload
  ThingSpeak.setField(1, current);
  ThingSpeak.setField(2, power);

  int response = ThingSpeak.writeFields(channelID, writeAPIKey);

  if(response == 200) {
    Serial.println("Upload Successful");
  } else {
    Serial.print("Upload Failed: ");
    Serial.println(response);
  }

  Serial.println("----------------------");

  delay(15000);
}