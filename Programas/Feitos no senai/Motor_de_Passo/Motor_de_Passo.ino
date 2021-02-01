//  Motor de passo
#include<Stepper.h> //Incluindo a biblioteca do Motor Passo
const int stepsPerRevolution = 65;  //Numero de passo por volt
Stepper myStepper(stepsPerRevolution,8,9,10,11);//Faz a inicialização da Biblioteca usando as portas 8,9,10,11
void setup() {
  myStepper.setSpeed(300);//velocidade do motor definida em 300

}

void loop() {
//Estrutura de repetição usada para limitar o tempo que o motor definida em 300
for (int i = 0;i<50;i++){
  myStepper.step(stepsPerRevolution);//sentido anti-horario

}
for (int i = 0;i<50;i++){
  myStepper.step(stepsPerRevolution);//sentido horario
   
}
}
 
