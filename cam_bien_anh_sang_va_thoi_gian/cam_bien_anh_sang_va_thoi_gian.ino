int lsen = A0;
int led = 6;
unsigned long previousMillis = 0;
int hour = 20;   // Đặt giờ thủ công khi bật Arduino
int minute = 21;
int second = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Cập nhật thời gian mỗi giây
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    second++;

    // Xử lý giây, phút, giờ
    if (second >= 60) {
      second = 0;
      minute++;
    }
    if (minute >= 60) {
      minute = 0;
      hour++;
    }
    if (hour >= 24) {
      hour = 0;
    }

    // In ra thời gian
    Serial.print("Thời gian hiện tại: ");
    if (hour < 10) Serial.print("0"); // Định dạng 2 chữ số
    Serial.print(hour);
    Serial.print(":");
    
    if (minute < 10) Serial.print("0");
    Serial.print(minute);
    Serial.print(":");

    if (second < 10) Serial.print("0");
    Serial.println(second);
  }

  if (hour == 20 && minute >= 22) {
    analogWrite(led, 0);  // Tắt đèn
  } else {
    int status = analogRead(lsen);
    
    // Sửa lại phép map để ánh sáng yếu thì LED sáng hơn
    int data = map(status, 100, 800, 0, 255);
    data = constrain(data, 0, 255);  // Giới hạn giá trị trong khoảng 0-255
    analogWrite(led, data); 
  }
}
