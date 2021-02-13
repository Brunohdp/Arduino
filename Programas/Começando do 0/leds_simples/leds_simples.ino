int bto = 2;
int ld1 = 3;
int ld2 = 4;
int ld3 = 5;
int ld4 = 6;
int ld5 = 7;
int t = 5000;
int estbto;

void setup() {
  pinMode(bto, INPUT);
  pinMode(ld1, OUTPUT);
  pinMode(ld2, OUTPUT);
  pinMode(ld3, OUTPUT);
  pinMode(ld4, OUTPUT);
  pinMode(ld5, OUTPUT);
}

void loop() {
  estbto = digitalRead(bto);
  if (estbto == 1) {
    delay(t);
    digitalWrite(ld1, 0);
    digitalWrite(ld2, 1);
    digitalWrite(ld3, 0);
    digitalWrite(ld4, 0);
    digitalWrite(ld5, 1);
    delay(t);
    digitalWrite(ld1, 0);
    digitalWrite(ld2, 0);
    digitalWrite(ld3, 1);
    digitalWrite(ld4, 1);
    digitalWrite(ld5, 0);
    delay(t);
  }
  else {
    digitalWrite(ld1, 1);
    digitalWrite(ld2, 0);
    digitalWrite(ld3, 0);
    digitalWrite(ld4, 0);
    digitalWrite(ld5, 1);
    delay(t);
    digitalWrite(ld1, 0);
    digitalWrite(ld2, 1);
    digitalWrite(ld3, 0);
    digitalWrite(ld4, 0);
    digitalWrite(ld5, 1);
    delay(t);
    digitalWrite(ld1, 0);
    digitalWrite(ld2, 0);
    digitalWrite(ld3, 1);
    digitalWrite(ld4, 0);
    digitalWrite(ld5, 1);
    delay(t);
  }
}
