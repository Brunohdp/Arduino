int led[9] = {2,3,4,5,6,7,8,9,10};
int x;
int nLed;
int t = 50;


void setup() {

  for (x = 0; x <= 8; x = x + 1){
    pinMode (led[x], OUTPUT);
  }
 
}

void loop() {

   for (nLed = 0; nLed <= 8; nLed = nLed + 1) {
      digitalWrite (led[nLed], 1);
      delay (t);
    }

   for (nLed = 8; nLed >= 0; nLed = nLed - 1) {
      digitalWrite (led[nLed], 0);
      delay (t);
    }
}
