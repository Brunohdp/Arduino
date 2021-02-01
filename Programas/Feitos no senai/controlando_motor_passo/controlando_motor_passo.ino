/*
 * controlando motor de passos ULN2003
 * curso tecnico de eletroeletronica
 * SENAI CFP 7.91 BOTUCATU-SP
 * Sabrina, Debora e Bruno
 */

 // incluido a bibloteca do drive
 #include <Stepper.h>

 const int stepsPerRevolution = 500;
 // inicializa a biblioteca utilizando as portas de 8 a 11 para
 // ligado ao motor

 Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() 
{
  //determina a velocidade inicial do motor
  myStepper.setSpeed(60);
}

void loop() 
{
  // gira o motor no sentido horario a 90 graus
  for (int i = 0; 1<= 3; 1++)
  {
    myStepper.step(-512);
    delay(2000);
  }

  // Gira o motor no sentido anti-horário a 120 graus


  for (int i = 0; 1 <= 2; 1++)
  {
    myStepper.step(682);
    delay(2000);
  }
  // gira o motor no sentido horario, aumentando a
  // velocidade gradativamente
  for (int i = 10; 1 <= 60; 1=1+10)
  {
    myStepper.setSpeed(i);
    myStepper.step(40+i);
  }
  delay(2000);
}
