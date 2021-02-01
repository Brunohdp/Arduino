//Bibliotecas incluidas
#include <Wire.h>                                                 //LCD
#include <LiquidCrystal_I2C.h>                                    //LCD
#include <Keypad.h>                                               //teclado
//#include <SPI.h>                                                  //protocolo que leitor usa
//#include (MFRC522.h)                                              //leitor



//definições do lcd
#define endereco 0x27                                             //endereço do display (ver no "Scanner I2C")
#define colunas 16                                                //define quantidade de colunas do display
#define linhas 2                                                  //define quantidade de linhas


//instanciando objetos
LiquidCrystal_I2C lcd (endereco, colunas, linhas);               //diz que o "lcd" é o conjunto de definições acima
//MFRC522 mfrc522(SS_PIN, RST_PIN);


//Definições de pinos
#define bz 3                                                      //buzzer
#define sp 4                                                      //sensor de presença
#define mc 2                                                      //microfone
#define temphm 8                                                  //sensor de temperatura e humidade
#define pt 9                                                      //potenciometro
#define led1 5                                                   //led verde
#define led2 6                                                   //led branco
#define led3 7                                                   //led vermelho
#define tempoMaximoEspera 150                                 //define como 150 milisegundos
#define tempoMaximoEntrePalmas 500                                //define como 500 milisegundos


//Teclado e senha
char* senha = "1234";                                            //define a senha
byte pinosLinhas[] = {36,34,32,30};                              //define portas das linhas
byte pinosColunas[] = {37,35,33,31};                             //define portas das colunas
char teclas [4][4] = {{'1','2','3','A'},
                      {'4','5','6','B'},
                      {'7','8','9','C'},
                      {'*','0','#','D'}};                        //mostra serial print qual tecla apertou


 Keypad teclado1 = Keypad (makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 4);                //faz mapeamento de todas as teclas
                      

 //declaração de variáveis
 int position = 0;
 int ativado;
 int contaPalmas = 0;
 long tempoEspera = 0;
 long tempoEsperaEntrePalmas = 0;




void setup() {
  estadoAlarme (0);                                              //diz se a condição do estado do alarme inicia executado ou não
  ativado = 0;                                                   //diz se o alarme inicia ativado ou não

  /*Configuração leitor
  SPI.begin();
  mfrc522.PCD_Init();*/
    
    //display
    lcd.init ();                                                 //inicia comunicação
    lcd.backlight();                                             //liga iluminação do display
    lcd.clear();                                                 //limpa o display
    
    lcd.setCursor (2,0);
    lcd.print("Iniciando.");                                     //escreve na tela 
    delay (500);
    lcd.clear();
    lcd.setCursor (2,0);
    lcd.print("Iniciando..");                                    //escreve na tela
    delay (500);
    lcd.clear();
    lcd.setCursor (2,0);
    lcd.print("Iniciando...");                                   //escreve na tela
    delay (500);
    lcd.clear();
    lcd.setCursor (2,0);
    lcd.print("Iniciando.");                                     //escreve na tela
    delay (500);
    lcd.clear();
    lcd.setCursor (2,0);
    lcd.print("Iniciando..");                                    //escreve na tela
    delay (500);
    lcd.clear();
    lcd.setCursor (2,0);
    lcd.print("Iniciando...");                                   //escreve na tela
    delay (500);                                                 //exibe por meio seg
    lcd.clear();                                                 //limpa tela
    lcd.setCursor (2,0);
    lcd.print("Iniciando.");                                     //escreve na tela
    delay (500);
    lcd.clear();
    lcd.setCursor (2,0);
    lcd.print("Iniciando..");                                    //escreve na tela
    delay (500);
    lcd.clear();
    lcd.setCursor (2,0);
    lcd.print("Iniciando...");                                   //escreve na tela
    delay (500);                                                 //exibe por meio segundo
    lcd.clear ();                                                //limpa tela
    lcd.setCursor (5,0);                                         //Posiciona o cursor na coluna 6 da linha 1
    lcd.print ("Inicio");                                        //escreve na tela
    lcd.setCursor (4,1);                                         //posiciona na coluna 5 da linha 2 e
    lcd.print ("Completo");                                      //escreve na tela
    delay (2000);                                                //exibe por 2 segs

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
    pinMode (bz, OUTPUT);                                        //buzzer: saída
    pinMode (sp, INPUT);                                         //sensor de presença: entrada
    pinMode (mc, INPUT);                                         //microfone: entrada
    pinMode (temphm, INPUT);                                     //sensor de temperatura e umidade: entrada
    pinMode (pt, INPUT);                                         //potenciometro: entrada
    pinMode (led1, OUTPUT);                                     //lampadas: saída
    pinMode (led2, OUTPUT);
    pinMode (led3, OUTPUT);
    digitalRead (sp);                                            //lê sensor de presença
    
}




void loop() {
  
palmas();                                                        //coloca void palmas em loop
teclado();                                                       //coloca void teclado em loop
estadoAlarme(ativado);                                           //coloca void estadoAlarme em loop
sensorPresenca();

}




void palmas() {

int som = digitalRead (mc);

if (som == 1) {

   if (tempoEspera == 0) {

      tempoEspera = tempoEsperaEntrePalmas = millis ();
      contaPalmas ++;
        
    } else if ((millis() - tempoEspera) >= tempoMaximoEspera) {

      tempoEspera = 0;
        
 }
}

if ((contaPalmas != 0) && ((millis() - tempoEsperaEntrePalmas) > 500)) {

    acao();
    contaPalmas = 0;
    tempoEsperaEntrePalmas = millis();
    
 }
}


void acao() {

switch (contaPalmas){

       case 2:
            digitalWrite (led1, !digitalRead(led1));
            break;
       case 3:
            digitalWrite (led2, !digitalRead(led2));
            break;
       case 4:
            digitalWrite (led3, !digitalRead(led3));
            break;
    
 }
}



void teclado () {
  
    char tecla_pressionada = teclado1.getKey();                  //faz a leitura das teclas
    

  if (tecla_pressionada !=0 && ativado == 0) {                   //aciona buzzer ao apertar teclas
    
      digitalWrite (bz, 1);
      delay (50);
      digitalWrite (bz, 0);
   
   if (tecla_pressionada == senha[position]) {                   //verifica se o dígito apertado corresponde a senha
    
      position ++;
      
   } else {
    
       position = 0;
   }                                                             //retorna p/ primeiro digito se não corresponder

   if (position == 4){                                           //altera estado do alarme
    
      lcd.clear();
      lcd.backlight();
      lcd.setCursor (4,0);
      lcd.print ("Ativando");
      lcd.setCursor (5,1);
      lcd.print ("Alarme"); 
      delay(3000);
      ativado = 1;
      estadoAlarme (true); 
      position = 0;
      
 }
}
 
delay (100);


   if (tecla_pressionada !=0 &&  ativado == 1) {                 //se alarme estiver ligado desliga ao digitar senha
   digitalWrite (bz, 1);
   delay (50);
   digitalWrite (bz, 0);
   
   if (tecla_pressionada == senha[position]) {
    position ++;
   } else {position = 0; }

   if (position == 4){
    estadoAlarme (false);                                        //diz que alarme tá desligado
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(2,0);
    lcd.print("Desativando");
    lcd.setCursor (5,1);
    lcd.print("Alarme");
    delay(3000);
    ativado = 0;
    position = 0;                                                //volta senha ao ponto 0 p/ digitar dnv
    lcd.noBacklight();                                           //apaga luz de fundo
    lcd.clear();                                                 //limpa tela
  }
 }
}




void estadoAlarme (int ativado) {
  
  bool valorSp = digitalRead (sp);                               //cria memória p/ ler o valor do sensor de presença
  
    if (ativado){                                                //se a senha estiver certa acontece isso:
      if (valorSp == 1) {                                        //se sp dectar algo executa:
      digitalWrite (bz, 1);                                      //ativa o buzzer
      lcd.clear ();                                              //limpa tela
      lcd.backlight ();                                          //liga luz de fundo
      lcd.setCursor (4,0);                                       //cursor coluna 4, linha 1
      lcd.print ("INVASAO:");                                    //escreve na tela
      lcd.setCursor (4,1);                                       //cursor coluna 5, linha 2
      lcd.print ("QUARTO 1");                                    //escreve na tela
      delay (2000);                                              //exibe por 3 segundos
      lcd.clear ();
      lcd.setCursor (3,0);
      lcd.print ("AGUARDANDO");
      lcd.setCursor (5,1);
      lcd.print ("SENHA!");
      delay (2000);
  } else {                                                       //se sp não dectar:
    
      digitalWrite (bz, 0);                                      //buzzer desligado
      lcd.clear ();                                              //limpa tela
      lcd.backlight ();                                          //acende luz de fundo
      lcd.setCursor (0,0);                                       //colocar cursor na primeira linha e coluna
      lcd.print ("Por Enquanto Ta");                             //escreve
      lcd.setCursor (1,1);                                       //cursor segunda linha e coluna
      lcd.print ("Tudo Tranquilo");                              //escreve
      delay (50);
  }
 }
}



void sensorPresenca () {

  int estadoSp = digitalRead (sp);

  if (estadoSp) {

      digitalWrite (led1, 1);
    
  } else {

      digitalWrite (led1, 0);
    
  }
}
