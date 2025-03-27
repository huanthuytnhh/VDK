int colA = 3;
int colB = 4;
int colC = 5;
int colD = 6;
int colE = 7;

int row1 = A4;
int row2 = A3;
int row3 = A2;
int row4 = A1;
int row5 = A0;
int cols[5] = {colA, colB, colC, colD, colE};
int rows[5] = {row1, row2, row3, row4, row5};

void setup() {
    for (int i = 0; i < 5; i++) {
        pinMode(rows[i], OUTPUT);
        pinMode(cols[i], OUTPUT);
    }
    clearMatrix();
}

void lightUp(int x, int y) {
    digitalWrite(rows[x], LOW);  // Đổi HIGH thành LOW
    digitalWrite(cols[y], HIGH); // Đổi LOW thành HIGH
}

void lightOff(int x, int y) {
    digitalWrite(rows[x], HIGH);
    digitalWrite(cols[y], LOW);
}

void clearMatrix() {
    for (int i = 0; i < 5; i++) {
        digitalWrite(rows[i], HIGH);
        digitalWrite(cols[i], LOW);
    }
}

void lightUpSquare(int level) {
    for (int i = 2 - level; i <= 2 + level; i++) {
        digitalWrite(rows[2 - level], LOW);
        digitalWrite(cols[i], HIGH);
        digitalWrite(rows[2 + level], LOW);
        digitalWrite(cols[i], HIGH);
    }
    for (int i = 2 - level; i <= 2 + level; i++) {
        digitalWrite(rows[i], LOW);
        digitalWrite(cols[2 - level], HIGH);
        digitalWrite(rows[i], LOW);
        digitalWrite(cols[2 + level], HIGH);
    }
  delay(200);
  clearMatrix();
    //delay(500);
}

void lightUpDiagonals() {
  	for (int i = 0; i <= 4; i++) {
    	lightUp(i,i);
      	delay(200);
      	lightOff(i,i);
      	delay(100);
    }
  	for (int i = 0; i <= 4; i++) {
    	lightUp(i,4-i);
      	delay(200);
      	lightOff(i,4-i);
      	delay(100);
    }
    clearMatrix();
  delay(200);
}
void loop() {
  
    for (int level = 0; level <= 2; level++) {
        lightUpSquare(level);
        delay(200);
    }
  	for (int level = 2 - 1; level >= 0; level--) {
        lightUpSquare(level);
        delay(200);
    }
    clearMatrix();
  	delay(200);
  	lightUpDiagonals();
  	delay(200);
}