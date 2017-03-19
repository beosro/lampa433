#define LAMPOUT D2

void setup() {
  pinMode(LAMPOUT, OUTPUT);
  analogWriteFreq(31300);
}

void loop() {
  for (int i = 0; i < PWMRANGE; i++) {
    analogWrite(LAMPOUT, i);
    delay(3);
  }
  for (int i = PWMRANGE - 1; i >= 1; i--) {
    analogWrite(LAMPOUT, i);
    delay(3);
  }
}
