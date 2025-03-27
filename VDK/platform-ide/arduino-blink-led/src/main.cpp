#include <Arduino.h>

// Khai báo các hàm từ lcd.cpp
void setupLCD();
void updateLCD(const String &message);

void setup()
{
  setupLCD();
  delay(2000); // Đợi 2 giây trước khi cập nhật
}

void loop()
{
  updateLCD("Counter: " + String(millis() / 1000));
  delay(1000);
}
