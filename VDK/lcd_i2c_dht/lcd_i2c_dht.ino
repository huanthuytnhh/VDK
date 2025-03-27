#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Khai báo LCD I2C (địa chỉ 0x27, loại LCD 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Khai báo cảm biến DHT11 ở chân số 8
#define DHTPIN 8      
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  
  // Khởi động LCD
  lcd.init();       
  lcd.backlight();  

  // Khởi động cảm biến DHT11
  dht.begin();

  // Hiển thị thông báo ban đầu
  lcd.setCursor(0, 0);
  lcd.print("DHT11 Sensor");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Đọc nhiệt độ và độ ẩm
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Kiểm tra nếu đọc lỗi
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Lỗi cảm biến DHT11!");
    lcd.setCursor(0, 0);
    lcd.print("DHT11 Error!");
    return;
  }

  // In ra Serial Monitor
  Serial.print("Nhiet do: ");
  Serial.print(temperature);
  Serial.print("°C - Do am: ");
  Serial.print(humidity);
  Serial.println("%");

  // Hiển thị lên LCD
  lcd.setCursor(0, 0);
  lcd.print("Nhiet do: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Do am: ");
  lcd.print(humidity);
  lcd.print(" %");

  // Chờ 2 giây rồi đọc lại
  delay(2000);
}
