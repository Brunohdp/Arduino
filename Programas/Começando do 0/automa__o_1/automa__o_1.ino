//Bibliotecas incluidas
//LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//teclado
#include <Keypad.h>


//definições do lcd
#define endereco 0x27    //endereço do display (ver no "Scanner I2C")
#define colunas 16       //define quantidade de colunas do display
#define linhas 2         //define quantidade de linhas


//instanciando objetos
LiquidCrystal_I2C lcd (endereco, colunas, linhas);      //diz que o "lcd" é o conjunto de definições acima


//Definições de pinos
#define bz 2             //buzzer
#define sp 3             //sensor de presença
#define mc 4             //microfone
#define tc 5             //teclado
#define temphm 7         //sensor de temperatura e humidade
#define pt 8             //potenciometro


//Teclado e senha
char* senha = "159";                                      //define a senha
byte pinosLinhas[] = {36,34,32,30};                       //define portas das linhas
byte pinosColunas[] = {37,35,33,31};                     //define portas das colunas
char teclas [4][4] = {{'1','2','3','A'},
                      {'4','5','6','B'},
                      {'7','8','9','C'},
                      {'*','0','#','D'}};                  //mostra serial print qual tecla apertou
                      

Keypad teclado1 = Keypad (makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 4);   //faz mapeamento de todas as teclas


//declaração de variáveis
int position = 0;
int ativado;
int estadoAlarme;


void setup() {
  estadoAlarme = 0;                                        //diz se alarme ta ligado ou não
    
  //display
  lcd.init ();                                                 //inicia comunicação
  lcd.backlight();                                             //liga iluminação do display
  lcd.clear();                                                 //limpa o display

  lcd.setCursor (2,0);
  lcd.print("Iniciando.");                                     //escreve na tela 
  delay (500);
  lcd.clear();
  lcd.setCursor (2,0);
  lcd.print("Iniciando..");                                   //escreve na tela
  delay (500);
  lcd.clear();
  lcd.setCursor (2,0);
  lcd.print("Iniciando...");                                  //escreve na tela
  delay (500);
  lcd.clear();
  lcd.setCursor (2,0);
  lcd.print("Iniciando.");                                    //escreve na tela
  delay (500);
  lcd.clear();
  lcd.setCursor (2,0);
  lcd.print("Iniciando..");                                   //escreve na tela
  delay (500);
  lcd.clear();
  lcd.setCursor (2,0);
  lcd.print("Iniciando...");                                  //escreve na tela
  delay (500);                                                //exibe por meio seg
  lcd.clear();                                                //limpa tela
  lcd.setCursor (2,0);
  lcd.print("Iniciando.");                                    //escreve na tela
  delay (500);
  lcd.clear();
  lcd.setCursor (2,0);
  lcd.print("Iniciando..");                                    //escreve na tela
  delay (500);
  lcd.clear();
  lcd.setCursor (2,0);
  lcd.print("Iniciando...");                                   //escreve na tela
 /* delay (500);                                                 //exibe por meio segundo
  lcd.clear ();                                                //limpa tela
  lcd.setCursor (5,0);                                         //Posiciona o cursor na coluna 6 da linha 1
  lcd.print ("Inicio");                                        //escreve na tela
  lcd.setCursor (4,1);                                         //posiciona na coluna 5 da linha 2 e
  lcd.print ("Completo");                                      //escreve na tela
  delay (2000);                                                //exibe por 2 segs
*/
  lcd.clear ();                                                //limpa tela
  lcd.setCursor (4,0);                                         //posiciona na coluna 5 da linha 1
  lcd.print ("Bom Dia,");                                      //escreve
  lcd.setCursor (4,1);                                         //posiciona na coluna 5 da linha 2
  lcd.print ("Recruta!");                                      //escreve
  delay (2000);                                                //exibe por 5 segs
  lcd.noBacklight();                                           //apaga luz de fundo
  lcd.clear ();                                                //limpa tela
  delay (1000);

    //define cada item como entrada ou saída
    pinMode (bz, OUTPUT);                                      //buzzer: saída
    pinMode (sp, INPUT);                                       //sensor de presença: entrada
    pinMode (mc, INPUT);                                       // microfone: entrada
    pinMode (tc, INPUT);                                       //teclado p/ senha: entrada
    pinMode (temphm, INPUT);                                   //sensor de temperatura e umidade: entrada
    pinMode (pt, INPUT);                                       //potenciometro: entrada

}


void loop() {
  char tecla_pressionada = teclado1.getKey();                   //faz a leitura das teclas
    bool valorSp = digitalRead (sp);                                //cria memória p/ ler o valor do sensor de presença

  if (tecla_pressionada !=0 && estadoAlarme == 0) {             //aciona buzzer ao apertar teclas
   digitalWrite (bz, 1);
   delay (50);
   digitalWrite (bz, 0);
   
   if (tecla_pressionada == senha[position] && estadoAlarme == 0) {     //verifica se o dígito apertado corresponde a senha
    position ++;
   } else {position = 0; }                                              //retorna p/ primeiro digito se não corresponder

   if (position == 3 && estadoAlarme == 0){                             //altera estado do alarme
    lcd.backlight();
    lcd.setCursor (4,0);
    lcd.print ("Ativando");
    lcd.setCursor (5,1);
    lcd.print ("Alarme"); 
    delay(3000);
    estadoAlarme = 1; 
  }
  delay (100);
}
  
    if (estadoAlarme == 1){                 //se a senha estiver certa acontece isso:
  if (valorSp) {                          //se sp dectar algo executa:
    digitalWrite (bz, 1);                 //ativa o buzzer
    lcd.clear ();                         //limpa tela
    lcd.backlight ();                     //liga luz de fundo
    lcd.setCursor (4,0);                  //cursor coluna 4, linha 1
    lcd.print ("INVASAO:");               //escreve na tela
    lcd.setCursor (4,1);                  //cursor coluna 5, linha 2
    lcd.print ("QUARTO 1");               //escreve na tela
    delay (2000);                         //exibe por 3 segundos
    lcd.clear ();
    lcd.setCursor (3,0);
    lcd.print ("AGUARDANDO");
    lcd.setCursor (5,1);
    lcd.print ("SENHA!");
    delay (2000);
  } else {                                //se sp não dectar:
    digitalWrite (bz, 0);                 //buzzer desligado
    lcd.clear ();                         //limpa tela
    lcd.backlight ();                     //acende luz de fundo
    lcd.setCursor (0,0);                  //colocar cursor na primeira linha e coluna
    lcd.print ("Por Enquanto Ta");        //escreve
    lcd.setCursor (1,1);                  //cursor segunda linha e coluna
    lcd.print ("Tudo Tranquilo");         //escreve
    delay (50);
  }
  }
   if (tecla_pressionada !=0 &&  estadoAlarme == true) {              //se alarme estiver ligado desliga ao digitar senha
   digitalWrite (bz, 1);
   delay (50);
   digitalWrite (bz, 0);
   
   if (tecla_pressionada == senha[position] &&  estadoAlarme == true) {
    position ++;
   } else {position = 0; }

   if (position == 3 &&  estadoAlarme == true){
    estadoAlarme = 0;                                                //diz que alarme tá desligado
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(2,0);
    lcd.print("Desativando");
    lcd.setCursor (5,1);
    lcd.print("Alarme");
    delay(3000);
    position = 0;                                                    //volta senha ao ponto 0 p/ digitar dnv
    lcd.noBacklight();                                               //apaga luz de fundo
    lcd.clear();                                                     //limpa tela
  }
}
}
