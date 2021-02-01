#define LEDSOBRECARGA     12           // LED SOBRECARGA
#define LED     13                     // LED LIGADO AO PINO 13
#define BOTAOLIGA 2                    // CHAVE ligada ao pino 2 digital
#define BOTAODESLIGA 3                 // CHAVE ligada ao pino 3 digital
#define SOBRECARGA 4
void setup() {

   pinMode(LED, OUTPUT);                //define LED como pino de saída 
   pinMode(LEDSOBRECARGA, OUTPUT);
   pinMode(BOTAOLIGA, INPUT);          //define chave como pino de entrada
   pinMode(BOTAODESLIGA, INPUT);
   pinMode(SOBRECARGA, INPUT);
   
}

void loop() {
   
   int ligado = 0;                   // int = memoria
   ligado = digitalRead(BOTAOLIGA);    // lê o valor do pino
   if (ligado == HIGH)     {             
       digitalWrite(LEDSOBRECARGA, LOW);
       digitalWrite(LED, HIGH);        // liga o LED  
      } 

   int desligado = 0;
   desligado = digitalRead(BOTAODESLIGA);  // lê o valor do pino
   if (desligado == HIGH)     {             
       digitalWrite(LED, LOW);        // Apaga o LED 
      }
 
   int termico = 0;
   termico = digitalRead(SOBRECARGA);  // lê o valor do pino
   if (termico == HIGH)     {             
       digitalWrite(LED, LOW);        // Apaga o LED
       digitalWrite(LEDSOBRECARGA, HIGH); 
   }
}
