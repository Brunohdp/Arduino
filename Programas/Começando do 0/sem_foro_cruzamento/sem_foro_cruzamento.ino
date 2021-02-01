int v1 = 2;                             //led verde 1 e 2
int v2 = 5;
int a1 = 3;                             //led amarelo 1 e 2
int a2 = 6;
int vm1 = 4;                            //led vermelho 1 e 2
int vm2 = 7;
int t1 = 3000;                          //tempo do verde pro amarelo e do vermelho pro verde
int t2 = 1200;                          //tempo do amarelo

void setup() {
  
  pinMode (v1, OUTPUT);                 //define todos os leds como saidas
  pinMode (v2, OUTPUT);
  pinMode (a1, OUTPUT);
  pinMode (a2, OUTPUT);
  pinMode (vm1, OUTPUT);
  pinMode (vm2, OUTPUT);

}

void loop() {
 
   digitalWrite (v1, 1);                  //led verde1 e vermelho2 acendem
   digitalWrite (v2, 0);
   digitalWrite (a1, 0);
   digitalWrite (a2, 0);
   digitalWrite (vm1, 0);
   digitalWrite (vm2, 1);
   delay (t1);                            //timer pro próximo

   digitalWrite (v1, 0);                  //led amarelo1 acende e vermelho2 continua aceso
   digitalWrite (v2, 0);
   digitalWrite (a1, 1);
   digitalWrite (a2, 0);
   digitalWrite (vm1, 0);
   digitalWrite (vm2, 1);
   delay (t2);

   digitalWrite (v1, 0);                  //led verde2 e vermelho1 acende,
   digitalWrite (v2, 1);
   digitalWrite (a1, 0);
   digitalWrite (a2, 0);
   digitalWrite (vm1, 1);
   digitalWrite (vm2, 0);
   delay (t1);

   digitalWrite (v1, 0);                  //led amarelo2 acende e vermelho1 continua aceso
   digitalWrite (v2, 0);
   digitalWrite (a1, 0);
   digitalWrite (a2, 1);
   digitalWrite (vm1, 1);
   digitalWrite (vm2, 0);
   delay (t2);

   digitalWrite (v1, 1);                   //led verde1 e vermelho2 acendem
   digitalWrite (v2, 0);
   digitalWrite (a1, 0);
   digitalWrite (a2, 0);
   digitalWrite (vm1, 0);
   digitalWrite (vm2, 1);

}
