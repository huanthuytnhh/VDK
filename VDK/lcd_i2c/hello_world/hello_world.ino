#include <LiquidCrystal.h>

#include <LiquidCrystal_I2C.h>

// Khởi tạo LCD với địa chỉ I2C (thường là 0x27 hoặc 0x3F, tùy board)
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD 16x2

void setup() {
  lcd.init();       // Khởi động LCD
  lcd.backlight();  // Bật đèn nền
  lcd.setCursor(0, 0); // Đặt con trỏ dòng 1, cột 0
  lcd.print("Hello, World!"); // In dòng chữ
}

void loop() {
  // Không cần làm gì trong loop
}