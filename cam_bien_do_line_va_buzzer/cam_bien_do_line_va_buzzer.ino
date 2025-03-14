#include <Arduino.h>

#define SENSOR_PIN A0  // Chân OUT của TCRT5000 vào A0
#define BUZZER_PIN 3   // Chân điều khiển buzzer

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(SENSOR_PIN);  // Đọc giá trị cảm biến (0 - 1023)
  Serial.println(sensorValue);               // In giá trị ra Serial Monitor

  if (sensorValue < 100) {  // Nếu phát hiện vạch đen
    tone(BUZZER_PIN, 100);  // Bật buzzer với tần số 1000Hz
    delay(300);  // Bíp trong 300ms
    noTone(BUZZER_PIN);  // Tắt buzzer
    delay(300);  // Nghỉ 300ms
  } else {
    noTone(BUZZER_PIN);  // Tắt buzzer hoàn toàn nếu không có vạch đen
  }
}
