//Ngô Nguyễn Tấn Quân
#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int DHTPIN = 8;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);

byte degree[8] = {
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000
};

void setup() {
  lcd.init();  
  lcd.backlight();
  
  lcd.print("Nhiet do: ");
  lcd.setCursor(0,1);
  lcd.print("Do am: ");
  
  lcd.createChar(1, degree);

  dht.begin();  
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) { // Ki?m tra xem th? vi?c d?c gi� tr? c� b? th?t b?i hay kh�ng. H�m isnan b?n xem t?i d�y http://arduino.vn/reference/isnan
  } 
  else {
    lcd.setCursor(10,0);
    lcd.print(round(t));
    lcd.print(" ");
    lcd.write(1);
    lcd.print("C");

    lcd.setCursor(10,1);
    lcd.print(round(h));
    lcd.print(" %");    
  }
}