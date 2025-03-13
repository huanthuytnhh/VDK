int lsen = A0;
int led = 6;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int status = analogRead(lsen);
  Serial.println(status);

  if (status < 1) {
    analogWrite(led, 0);  // Tắt đèn nếu giá trị nhỏ hơn 50
  } else {
    int data = map(status, 100, 1000, 0, 255);
    analogWrite(led, data);
  }

  delay(100);
}
