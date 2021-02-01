int sensor = 0;           // Pino analogico em que o sensor esta conectado.
int valorSensor = 0;      // Usada para ler o valor do sensor em tempo real.  
int buzzer = 6;


const int ledVerde = 8; 
const int ledAmarelo = 9;
const int ledVermelho = 10;
int valor = 0;

void setup() {
// Ativando os serial monitor que exibira os valores lidos no sensor.
Serial.begin(9600);

   //Definindo pinos digitais dos leds como de saida.
   pinMode(ledVerde, OUTPUT); 
   pinMode(ledAmarelo, OUTPUT);
   pinMode(ledVermelho,OUTPUT);
   pinMode(buzzer,OUTPUT);
}
   void loop() {
 //Lendo o valor do sensor.
 int valorSensor = analogRead(sensor);
 valor = map(valorSensor,0,1023,0,100);

 //Valores da luminosidade podem ser alternado conforme necessidade.

 //Luminosidade baixa.
 if(valor < 50) {
  apagaLeds();
  digitalWrite(ledVerde, HIGH);
  digitalWrite(buzzer,HIGH);
  delay (500);
  digitalWrite(buzzer,LOW);
  delay (500);
  
  
  

 }

  //Luminosidade médida.
  if(valor >= 65 && valor  <=79) {
    apagaLeds();
     digitalWrite(ledAmarelo,HIGH);
     digitalWrite(buzzer,HIGH);
     delay (500);
     digitalWrite(buzzer,LOW);
     delay (500);
     digitalWrite(buzzer,HIGH);
     delay (500);
     digitalWrite(buzzer,LOW);
     delay (500);
  }

   //luminosidade alta.
   if (valor > 80) {
    apagaLeds();

     digitalWrite(ledVermelho,HIGH);
     digitalWrite(buzzer,HIGH);
     delay (500);
     digitalWrite(buzzer,LOW);
     delay (500);
     digitalWrite(buzzer,HIGH);
     delay (500);
     digitalWrite(buzzer,LOW);
     delay (500);
     digitalWrite(buzzer,HIGH);
     delay (500);
     digitalWrite(buzzer,LOW);
     delay (500);
   }
    
    //Exibindo o valor do sensor no serial monitor.
   Serial.println(valor);
   delay(50);
}

 //Função criada para apagar todos os leds de uma vez
void apagaLeds(){
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledAmarelo,LOW);
  digitalWrite(ledVermelho,LOW);

}

