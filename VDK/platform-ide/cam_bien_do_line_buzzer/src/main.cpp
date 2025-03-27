#include <Arduino.h>
         // Thư viện I2C
#include <LiquidCrystal_I2C.h> // Thư viện cho LCD I2C

#define SENSOR_PIN A0 // Chân OUT của TCRT5000 vào A0
#define BUZZER_PIN 3  // Chân điều khiển buzzer

// Khởi tạo LCD I2C (địa chỉ I2C thường là 0x27 hoặc 0x3F, 16 cột, 2 dòng)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600); // Vẫn giữ Serial để debug nếu cần

  // Khởi động LCD
  lcd.init();
  lcd.backlight();          // Bật đèn nền
  lcd.setCursor(0, 0);      // Đặt con trỏ dòng 0, cột 0
  lcd.print("Starting..."); // Hiển thị thông báo khởi động
  delay(2000);              // Chờ 2 giây
  lcd.clear();              // Xóa màn hình
}

void loop()
{
  int sensorValue = analogRead(SENSOR_PIN); // Đọc giá trị cảm biến (0 - 1023)

  // Hiển thị giá trị cảm biến lên LCD
  lcd.setCursor(0, 0); // Dòng 0
  lcd.print("Sensor: ");
  lcd.print(sensorValue);
  lcd.print("   "); // Thêm khoảng trắng để xóa ký tự thừa

  if (sensorValue < 100)
  {
    digitalWrite(BUZZER_PIN, HIGH); // Bật buzzer
    lcd.setCursor(0, 1);            // Dòng 1
    lcd.print("Vach den!    ");     // Hiển thị cảnh báo
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW); // Tắt buzzer
    lcd.setCursor(0, 1);           // Dòng 1
    lcd.print("Khong vach den");   // Hiển thị trạng thái bình thường
  }

  delay(100); // Delay 100ms
}