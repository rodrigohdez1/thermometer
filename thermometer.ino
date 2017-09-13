/*
  Electronic thermometer.

  Tested with Arduino Uno using a simple LCD 16x2 display.
*/
#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
// 2: RS
// 3: E
// 4: DB4
// 5: DB5
// 6: DB6
// 7: DB7
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int sensorPin = A0;    // Select the input pin for the potentiometer
int ledPin = 13;      // Select the pin for the LED
int sensorValue = 0;  // Variable to store the value coming from the sensor


byte degree[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
};

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("TEMP. AMBIENTE");
}

void loop() {

  // read the value from the sensor:
  //Handle Temperature

  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  // Scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }

  // Scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  int cvalue = analogRead(sensorPin);
  float voltage = cvalue * 5.0;
  Serial.println(voltage);
  int fvalue = (voltage - 0.5) * 100;

  lcd.setCursor(0, 1);
  lcd.print(cvalue);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(6, 1);
  lcd.print(fvalue);
  lcd.print((char)223);
  lcd.print("F");
  delay(5000);
}

