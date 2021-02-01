/*
 * ALARME COM SENSOR DE MOVIMENTO PIR DYP-ME003
 * SENAI CFP 7.91 BOTUCATU SP
 * CURSO TECNICO DE ELETROELETRONICA
 * ALUNO MICAELISON PIRES
 */

 //Declaração das variaveis referentes aos pinos digitais
  int pinBuzzer = 7;
  int pinSensorPIR = 11;
  int pinLed = 9;
  int valorSensorPIR = 0;
void setup() {
  Serial.begin(9600);   //Iniciando o serial motor

   //Definido pinos como de entrada ou de saída
  pinMode(pinBuzzer,OUTPUT);
  pinMode(pinSensorPIR,INPUT);
  pinMode(pinLed,OUTPUT);

}

void loop() {
  //Lendo o valor do sensor PIR. Este sensor pode assumir 2 valores, sendo 1 quando detecta algum movimento e 0 quando não detecta
  valorSensorPIR = digitalRead(pinSensorPIR);

 Serial.print("Valor do sensor PIR: ");
 Serial.println(valorSensorPIR == 1);

 //Verificando se ocorreu detecção de movimentos
 if (valorSensorPIR == 1) {
  

  
   ligarAlarme();
 } else {
  desligaAlarme();
  
 }

}

void ligarAlarme() {
  //Ligando o led
  digitalWrite(pinLed, HIGH);

   //Ligando o buzzer com uma frequencia de 1500 hz.
   tone(pinBuzzer,1500);

   delay(4000); //tempo que o led fica aceso e o buzzer toca

   desligaAlarme();
}

void desligaAlarme() {
  // Desligando o led
  digitalWrite(pinLed, LOW);

  //Desligando o buzzer
  noTone(pinBuzzer);
}

