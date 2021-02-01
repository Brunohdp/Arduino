// Lê a biblioteca do servomotor
#include <Servo.h>

// Define o nome do swervomotor
Servo servo_2;

void setup()
{
  // Define o pino analógico A0 como entrada
  pinMode(A0, INPUT);
  
  // Inicia o monitor serial para que a gente possa ver o que o LDR está lendo.
  Serial.begin(9600);

  // Liga o servo no pino 2 digital
  servo_2.attach(2);

  // Coloca o servo na posição inicial (0 grau)
  servo_2.write(0);  

}

void loop()
{
  // Imprime no monitor serial o valor lido pelo LDR
  Serial.println(analogRead(A0));
  
  // Se o valor lido estiver abaixo de certo valor...
  if (analogRead(A0) < 690) {
    
    // Mova o servomotor 20 graus.
    servo_2.write(20);
    
    // Espere um tempo
    delay(150);

  // Caso contrário (se o valor lido estiver alto)...  
  } else {

          //Coloque o swervomotor na posição inicial.
          servo_2.write(0); 
          
          // Espere um tempo. 
          delay(50);
  }
}

