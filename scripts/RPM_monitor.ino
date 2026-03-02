#include <LiquidCrystal.h>

// --- Pin Definitions ---
LiquidCrystal lcd(5, 4, 8, 9, 10, 11);
const int backlightPin = 12;
const int contrastPin = 6;
const int hallPin = 2;

volatile unsigned long lastPulseTime = 0;
volatile unsigned long pulseInterval = 0;
volatile bool firstPulse = true; 

float lastValidRPM = 0;

void countPulse() {
  unsigned long currentTime = millis();

  if (firstPulse) {
    firstPulse = false;     
    lastPulseTime = currentTime;
    return;
  }

  pulseInterval = currentTime - lastPulseTime;
  lastPulseTime = currentTime;
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(hallPin), countPulse, FALLING);

  pinMode(backlightPin, OUTPUT);
  digitalWrite(backlightPin, HIGH);
  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, 75);

  lcd.begin(16, 2);

  // Top row with solid bars
  lcd.setCursor(0, 0);
  lcd.write(byte(255)); 
  lcd.print(" RPM  Monitor ");
  lcd.write(byte(255));  
}

void loop() {
  float rpm = lastValidRPM;
  bool showBlank = false;

  noInterrupts();
  unsigned long interval = pulseInterval;
  interrupts();

  if (!firstPulse && interval > 0) {
    rpm = 60000.0 / interval; 
    lastValidRPM = rpm;      
  }

  // Timeout check: no pulse received for ~1.5x interval
  if (!firstPulse && (millis() - lastPulseTime > 1500 * interval / 1000UL)) {
    showBlank = true;  
  }

  Serial.println(showBlank ? 0 : rpm);

  // Clear second row
  lcd.setCursor(0, 1);
  lcd.print("                "); // 16 spaces

  // Display RPM if valid, else show message
  if (!showBlank && !firstPulse) {
    char buffer[10];
    dtostrf(rpm, 0, 1, buffer); 
    int len = strlen(buffer);
    int startCol = (16 - len) / 2; 
    lcd.setCursor(startCol, 1);
    lcd.print(buffer);
  } else if (firstPulse || showBlank) {
    lcd.setCursor(0, 1);
    lcd.print("Wait for Reading");
  }

  delay(500);
}
