
/*
 * CENTRAL DE DOMÓTICA
 * SENAI CFP 7.91 BOTUCATU SP
 * CURSO TECNICO ELETROELETRONICA
 * ALUNOS MURILO
 */
 const int LDR1 = A4;    //Pino analógico que o sensor de luz está conectado.
 //const int LDR2 = A5;
 //const int LDR3 = A3;
 int luminosidade1 = 0;  //Declara a variavel luminosidade com atribuicao igual a zero
 //int luminosidade2 = 0;
 //int luminosidade3 = 0;
 int LED1 = 11;          //Declara a variavel LED no pino analogico 4
 //int LED2 = 10;
 //int LED3 = 6;
 int pot1 = A0;          //Declara a variavel pot no pino analogico 2
 //int pot2 = A2;
 //int pot3 = A1;
 int ajuste1 = 0;        //Declara a variavel ajuste com atribuicao igual a zero 
 //int ajuste2 = 0;
 //int ajuste3 = 0; 
 int red1 = 2;
 int red2 = 8;
 int red3 = 7;
 //int red4 = 9;
 //int red5 = 5;
 //int red6 = 4;
 int buzzer = 13;
 int ambiente1 = 0;
 int ambiente2 = 0;
 int ambiente3 = 0;
 //int ambiente4 = 0;
 //int ambiente5 = 0;
 //int ambiente6 = 0;
 int sensordepresenca1 = 6;
 int sensordepresenca2 = 4;
 //int sensordepresenca3 = 12;
 int ambientemov1 = 0;
 int ambientemov2 = 0;
 //int ambientemov3 = 0;
 int rele = 10;
 
 

 
void setup() {
 Serial.begin(9600);    //Inicia a comunicacao serial
 pinMode (red1,INPUT);
 pinMode(red2,INPUT);
 pinMode(red3,INPUT);
 //pinMode(red4,INPUT);
 //pinMode(red5,INPUT);
 //pinMode(red6,INPUT);
 
 pinMode(buzzer,OUTPUT);
 pinMode (LDR1,INPUT);   //Definbe o LDR como uma entrada para o sistema
 //pinMode (LDR2,INPUT);
 //pinMode (LDR3,INPUT);
 pinMode(LED1,OUTPUT);   //Define LED como saida
 //pinMode(LED2,OUTPUT);
 //pinMode(LED3,OUTPUT);
 pinMode(pot1,INPUT);
 //pinMode(pot2,INPUT); //Define pot como entrada
 //pinMode(pot3,INPUT);

 pinMode(sensordepresenca1,INPUT);
 pinMode(sensordepresenca2,INPUT);
 //pinMode(sensordepresenca3,INPUT);

 pinMode(rele, OUTPUT);

 
 }

void loop() {
ambiente1 = digitalRead(red1);
ambiente2 = digitalRead(red2);
ambiente3 = digitalRead(red3);
//ambiente4 = digitalRead(red4);
//ambiente5 = digitalRead(red5);
//ambiente6 = digitalRead(red6);

if(ambiente1 == 0){
  Serial.println("COPA INVADIDA");
  digitalWrite(buzzer,HIGH);
}


if (ambiente2 ==0){
  Serial.println("COZINHA INVADIDA");
   digitalWrite(buzzer,HIGH);
}


if (ambiente3 ==0){
  Serial.println(" QUARTO 1 INVADIDO ");
   digitalWrite(buzzer,HIGH);
}


//if (ambiente4 ==0){
  //Serial.println("PEDRINHA ENTROU NO AMBIENTE 4");
   //digitalWrite(buzzer,HIGH);
//}


//if (ambiente5 ==0){
  //Serial.println("PEDRINHA ENTROU NO AMBIENBTE 5");
   //digitalWrite(buzzer,HIGH);
//}

//if (ambiente6 ==0){
  //Serial.println("PEDRINHA ENTROU NO AMBIENTE 6");
   //digitalWrite(buzzer,HIGH);
//}

if (ambiente1 == 1 && ambiente2 == 1 && ambiente3== 1) {
  digitalWrite(buzzer,LOW);
}
ambientemov1 = digitalRead(sensordepresenca1);
ambientemov2 = digitalRead(sensordepresenca2);
//ambientemov3 = digitalRead(sensordepresenca3);
if(ambientemov1 == 1){
  Serial.println("SALA INVADIDA");
  digitalWrite(buzzer,HIGH);
}
if(ambientemov2 == 1){
  Serial.println("ÁREA DE LAZER INVADIDA");
  digitalWrite(buzzer,HIGH);
}
//if(ambientemov3 == 1){
  //Serial.println("ambiente mov3 invadido");
  //digitalWrite(buzzer,HIGH);
//}


luminosidade1 = analogRead(LDR1);
luminosidade1 = map(luminosidade1, 0, 900, 0, 100);
ajuste1 = analogRead(pot1);
ajuste1 = map(ajuste1, 0, 1023, 0, 100);
delay(100);
Serial.println(luminosidade1);
Serial.println(ajuste1);
if (ajuste1 >= luminosidade1){
  digitalWrite (LED1,HIGH);
}
else{
  digitalWrite (LED1,LOW);
}
//luminosidade2 = analogRead(LDR2);
//luminosidade2 = map(luminosidade2, 0, 900, 0, 100);
//ajuste2 = analogRead(pot2);
//ajuste2 = map(ajuste2, 0, 1023, 0, 100);
//delay(100);
//Serial.println(luminosidade2);
//Serial.println(ajuste2);
//if (ajuste2 >= luminosidade2){
  //digitalWrite (LED2,HIGH);
//}
//else{
  //digitalWrite (LED2,LOW);
//}
//luminosidade3 = analogRead(LDR3);
//luminosidade3 = map(luminosidade3, 0, 900, 0, 100);
//ajuste3 = analogRead(pot3);
//ajuste3 = map(ajuste3, 0, 1023, 0, 100);
//delay(100);
//Serial.println(luminosidade3);
//Serial.println(ajuste3);
//if (ajuste3 >= luminosidade3){
  //digitalWrite (LED3,HIGH);
//}
//else{
  //digitalWrite (LED3,LOW);
//}
 if(Serial.available()>=2)  
  {  
    int key=Serial.read();  
    int val=Serial.read();  
    digitalWrite(key,val);  
  }  
}



