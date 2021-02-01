int ldr = A0;
int led[9] = {2,3,4,5,6,7,8,9,10};
int pinLed;

float valorLDR;
float minimo = 85;
float maximo = 1020;
float luminosidade;

void setup() {

  Serial.begin(9600);
  
  for (pinLed = 0; pinLed <=8; pinLed ++) {
    pinMode (led[pinLed], OUTPUT);
  }

  pinMode(ldr, INPUT);
}

void loop() {
 valorLDR = digitalRead(ldr);
  Serial.print("Luminosidade: ");
  Serial.println(valorLDR);
  
  valorLDR = analogRead(ldr);
  luminosidade = ((valorLDR - minimo) / (maximo - minimo)) * 10;
  luminosidade = (luminosidade - 10)* -1;

  for (pinLed = 0; pinLed <=8; pinLed ++) {
       if (pinLed < luminosidade) {
        digitalWrite (led[pinLed], 1);
       } else {
        digitalWrite (led[pinLed], 0);
       }
  }

  delay(500);
}
