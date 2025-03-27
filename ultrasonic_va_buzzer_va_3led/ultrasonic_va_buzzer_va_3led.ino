Ngô Nguyễn Tấn Quân
int trigger = 7; //KUNING TRIG
int echo = 6; //PIN 13 ECHO
int green = 4;
int yellow = 3;
int red = 2;
int buzzer = 9;
long duration = 0;
int distance = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigger,0);   // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trigger,1);   // phát xung từ chân trig
  delayMicroseconds(5);   // xung có độ dài 5 microSeconds
  digitalWrite(trigger,0);   // tắt chân trig
    
  /* Tính toán thời gian */
  // Đo độ rộng xung HIGH ở chân echo. 
  duration = pulseIn(echo,HIGH);  
  // Tính khoảng cách đến vật.
  distance = int(duration/2/29.412);
  if (distance < 5) {
    digitalWrite(green,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
    tone(buzzer, 300);
    delay(100);
    noTone(buzzer);
  }
  else if (distance < 10){
    digitalWrite(green,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
    noTone(buzzer);
  }
  else {
    noTone(buzzer);
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
    delay(200);
    digitalWrite(red,LOW);
    delay(200);
  }
}