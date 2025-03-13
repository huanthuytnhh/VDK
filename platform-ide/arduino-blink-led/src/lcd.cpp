#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Khai báo LCD (địa chỉ 0x27, 16 cột, 2 hàng)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setupLCD()
{
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Hello, I2C LCD!");
}

void updateLCD(const String &message)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
}
