int v1 = 2;                             //led verde 1 e 2, pinos 2 e 5
int v2 = 5;

int a1 = 3;                             //led amarelo 1 e 2, pinos 3 e 6
int a2 = 6;

int vm1 = 4;                            //led vermelho 1 e 2, pinos 4 e 7
int vm2 = 7;

int pv = 8;                             //led verde pedestre pino 8
int pvm = 9;                            //led vermelho pedestre pino 9

int botao = 10;                         //botao pino 10

int t1 = 2000;                          //tempo do verde pro amarelo e do vermelho pro verde
int t2 = 800;                           //tempo do amarelo p/ vermelho
int t3 = 3500;                          //tempo do led verde pedestre

int estadoBotao;                        //memória p/ ler se botao ta ligado ou não


void setup() {
  
  Serial.begin(9600);                     //inicia comunicacao serial

  pinMode (v1, OUTPUT);                   //define leds verdes como saidas
  pinMode (v2, OUTPUT);
  pinMode (a1, OUTPUT);                   //define leds amarelos como saidas
  pinMode (a2, OUTPUT);
  pinMode (vm1, OUTPUT);                  //define leds vermelhos como saidas
  pinMode (vm2, OUTPUT);
  pinMode (pv, OUTPUT);                   //define led verde pedestre como saidas
  pinMode (pvm, OUTPUT);                  //define led vermelho pedestre como saidas
  pinMode (botao, INPUT);                 //define botao como entrada
}

void loop() {
  
  estadoBotao = digitalRead(botao);  

  Serial.print ("Botão: ");                //texto que aparece antes do estado pra ver se tá sendo apertado
  Serial.println (estadoBotao);            //exibe estado do botão na porta serial
 
 if (estadoBotao == 0){
 
   digitalWrite (v1, 1);                  //led verde1 e vermelho2 acendem
   digitalWrite (v2, 0);
   digitalWrite (a1, 0);
   digitalWrite (a2, 0);
   digitalWrite (vm1, 0);
   digitalWrite (vm2, 1);

   digitalWrite (pv, 0);
   digitalWrite (pvm, 1);                 //led vermelho p/ pedestre aceso
   delay (t1);                            //timer pro próximo
   
   

   digitalWrite (v1, 0);                  //led amarelo1 acende e vermelho2 continua aceso
   digitalWrite (v2, 0);
   digitalWrite (a1, 1);
   digitalWrite (a2, 0);
   digitalWrite (vm1, 0);
   digitalWrite (vm2, 1);

   digitalWrite (pv, 0);
   digitalWrite (pvm, 1);                 //led vermelho p/ pedestre aceso
   delay (t2);
   


   digitalWrite (v1, 0);                  //led verde2 e vermelho1 acende
   digitalWrite (v2, 1);
   digitalWrite (a1, 0);
   digitalWrite (a2, 0);
   digitalWrite (vm1, 1);
   digitalWrite (vm2, 0);

   digitalWrite (pv, 0);                  //led vermelho p/ pedestre aceso
   digitalWrite (pvm, 1);
   delay (t1);
   


   digitalWrite (v1, 0);                  //led amarelo2 acende e vermelho1 continua aceso
   digitalWrite (v2, 0);
   digitalWrite (a1, 0);
   digitalWrite (a2, 1);
   digitalWrite (vm1, 1);
   digitalWrite (vm2, 0);

   digitalWrite (pv, 0);                  //led vermelho p/ pedestre aceso
   digitalWrite (pvm, 1);
   delay (t2);

   
 } else {
   digitalWrite (v1, 0);                  //se botao estiver apertado só led amarelo acende
   digitalWrite (v2, 0);
   digitalWrite (a1, 1);
   digitalWrite (a2, 1);
   digitalWrite (vm1, 0);
   digitalWrite (vm2, 0);

   digitalWrite (pv, 0);                  //pedestre continua vermelho
   digitalWrite (pvm, 1);
   delay (t2);
   
   
   digitalWrite (v1, 0);                  //só led vermelho aceso
   digitalWrite (v2, 0);
   digitalWrite (a1, 0);
   digitalWrite (a2, 0);
   digitalWrite (vm1, 1);
   digitalWrite (vm2, 1);

   digitalWrite (pv, 1);                  //led verde p/ pedestre aceso
   digitalWrite (pvm, 0);
   delay (t3);
 }
}
