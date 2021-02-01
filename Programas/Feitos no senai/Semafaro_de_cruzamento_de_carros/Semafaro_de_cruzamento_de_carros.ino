/*

 Blink

 Semafaro de cruzamento de carros
 */

//Função de inicialização
void setup() {
  // inicializa o pino digital como saida
  pinMode(5, OUTPUT);     // vermelho1
  pinMode(6, OUTPUT);     // amarelo 1
  pinMode(7, OUTPUT);     // verde 1
  pinMode(8, OUTPUT);     // vermelho 2
  pinMode(9, OUTPUT);     // amarelo 2
  pinMode(10, OUTPUT);    // verde 2
}

void loop() {
  digitalWrite(5, HIGH);    // acende o led conectado no pino 5 - VERMELHO 1       V
  digitalWrite(10, HIGH);   // acende o led conectado no pino 10 - VERDE 2         V
  delay(5000);              // espera 5 segundo (5000 mS) - VERMELHO 1             V
  delay(5000);              // espera 5 segundo (5000 mS) - VERDE 3                V
  digitalWrite(9, HIGH);    // acende o led conectado no pino 9 - AMARELO 2        V
  digitalWrite(10, LOW);    // apaga o led  - VERDE 2                              V
  delay(3000);              // espera um segundo (5000 mS) - AMARELO 2 
  digitalWrite(9, LOW);     // apaga o led - AMARELO 2
   digitalWrite(5, LOW);    // apaga o led  - VERMELHO 2 
  digitalWrite(8, HIGH);    // acende o led conectado no pino 8 - VERMELHO 2
  digitalWrite(7, HIGH);    // acende o led conectado no pino 7 - VERDE 1
  delay(5000);              // espera um segundo (5000 mS)  - VEMELHO 2
  delay(5000);              // espera um segundo (5000 mS) - VERDE 1
  digitalWrite(6, HIGH);    // acende o led conectado no pino 6 - AMARELO 1
  digitalWrite(7, LOW);     // apaga o led - VERDE 1
  delay(5000);              // espera um segundo (5000 mS) - VERDE 1
  digitalWrite(6, LOW);     // apaga o led  - AMARELO 2 
  digitalWrite(8, LOW);     // apaga o led  - VERMELHO 1
}
