#include <Keypad.h>


char* senha = "1";                                      //define a senha
byte pinosLinhas[] = {36,34,32,30};                       //define portas das linhas
byte pinosColunas[] = {37,35,33,31};                      //define portas das colunas
char teclas [4][4] = {{'1','2','3','A'},
                      {'4','5','6','B'},
                      {'7','8','9','C'},
                      {'*','0','#','D'}};
                      

Keypad teclado1 = Keypad (makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 4);   //faz mapeamento de todas as teclas

int position;
int bz;
int sp = 0;

void setup() {
  estadoAlarme (0);
}

void loop() {
  
  teclado();

}

void teclado() {
      char tecla_pressionada = teclado1.getKey();                   //faz a leitura das teclas

  if (tecla_pressionada !=0) {             //aciona buzzer ao apertar teclas
   digitalWrite (bz, 1);
   delay (50);
   digitalWrite (bz, 0);
   
   if (tecla_pressionada == senha[position]) {     //verifica se o dígito apertado corresponde a senha
    position ++;
   } else {position = 0; }                                              //retorna p/ primeiro digito se não corresponder

   if (position == 1){                             //altera estado do alarme
    estadoAlarme (true); 
  }
  delay (100);
}
}
void estadoAlarme (int ativado) {
  bool valorSp = digitalRead (sp);                                //cria memória p/ ler o valor do sensor de presença
  
    if (ativado){                 //se a senha estiver certa acontece isso:
  if (valorSp) {                          //se sp dectar algo executa:
    digitalWrite (bz, 1);                 //ativa o buzzer
    delay (2000);
  } else {                                //se sp não dectar:
    digitalWrite (bz, 0);                 //buzzer desligado
      delay (50);
  }
  }
}
