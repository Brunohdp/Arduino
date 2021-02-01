int led1 = 2;                      //define pino 2 como led 1
int led2 = 3;
int led3 = 4;
int led4 = 5;
int t = 200;                       /*define t como tempo. Para mudar 
                                   todos os delays é só alterar o valor*/


void setup() {
  
  pinMode (led1, OUTPUT);         //define que os leds são saídas
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);

}

void loop() {
 
 digitalWrite (led1, 1);          //diz que o led1 acende enquanto os outros ficam apagados
 digitalWrite (led2, 0);
 digitalWrite (led3, 0);
 digitalWrite (led4, 0);
 delay (t);                       //Tempo que o programa vai manter o led1 aceso e os outros apagados
 
 digitalWrite (led1, 0);          //diz que o led 3 acende enquanto os outros apagam
 digitalWrite (led2, 0);
 digitalWrite (led3, 1);
 digitalWrite (led4, 0);
 delay (t);                       //tempo até seguir com o programa
 
 digitalWrite (led1, 0);
 digitalWrite (led2, 1);
 digitalWrite (led3, 0);
 digitalWrite (led4, 0);
 delay (t);

 digitalWrite (led1, 0);
 digitalWrite (led2, 0);
 digitalWrite (led3, 0);
 digitalWrite (led4, 1);
 delay (t);
 
}
