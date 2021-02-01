/*
 * PWM
 * Controle de luminosidade do Led pelo potenciometro
 */
  int ledPin = 3;        // pino do led 
  int analogPin = 0;     // pino para leitura do potenciometro
  int val = 0;           // variavel para armazenar o valor lido

void setup() {
 pinMode(ledPin, OUTPUT); // configura pino como saida
}

void loop() {
 val = analogRead(analogPin);      //le o valor analogico
 analogWrite(ledPin, val / 4);    // aciona led com o valor analogico lido dividido por 4 para ajustar ao valor
}
