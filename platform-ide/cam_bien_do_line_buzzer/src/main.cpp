#include <Arduino.h>

#define SENSOR_PIN A0 // Chân OUT của TCRT5000 vào A0
#define BUZZER_PIN 3  // Chân điều khiển buzzer

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(SENSOR_PIN); // Đọc giá trị cảm biến (0 - 1023)
  Serial.println(sensorValue);              // In giá trị ra Serial Monitor

  if (sensorValue < 100)
  {                                 // Nếu phát hiện vạch đen (giá trị thấp)
    digitalWrite(BUZZER_PIN, HIGH); // Bật buzzer
    Serial.println("Vạch đen - Cảnh báo!");
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW); // Tắt buzzer
    Serial.println("Không có vạch đen.");
  }

  delay(100);
}
