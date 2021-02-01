/*PROJETO CONTROLADOR
 * SENAI CFP 7.91
 * TÉCNICO ELETROELETRÔNICA
 */
 int começa = 2;
 int botaoliga = 3;
 int forno = 4;
 int motor esteira1 = 5;
 int motor esteira2 = 6;   
 int sensor externo = 7; 
 int sensor interno = 8;
 int LED = 9;    
 const int LM35 = A1;
 int poten = A2;       
 int Temperatura = 0;  
 int ajuste = 0;         
 
void setup() {
 Serial.begin(9600);    //Inicia a comunicacao serial
 pinMode(começa,INPUT);
 pinMode(botaoliga,INPUT);
 pinMode(forno,OUTPUT);
 pinMode(motor esteira1,OUTPUT);
 pinMode(motor esteira2,OUTPUT);
 pinMode(sensor interno,INPUT);
 pinMode(sensor externo,INPUT);
 pinMode(LED,OUTPUT);
 pinMode (LM35,INPUT);   
 pinMode(poten,INPUT);    

}

void loop() {
  if  (botaoliga == 0 & começa == 0)
  digitalWrite (forno, HIGH);
  }
  else 
  {
    digitalWrite (forno, LOW);
  }
   Temperatura = analogRead(LM35);    // Executa a leitura de luminosidade do sensor LDR
  Temperatura = map(Temperatura,0,307,0,50);
  ajuste = (analogRead(poten));          // Executa a leitura do potenciometro
  ajuste = map(ajuste,0,1023,0,50);
  delay(100);
  Serial.println(Temperatura);      // Mostra o valor da luminosidade na interface serial
  Serial.println("\260c");
  delay(500);

  Serial.println(ajuste);            
  if (ajuste = Temperatura) {       
  digitalWrite (motor esteira1,HIGH);
  digitalWrite (motor esteira2,LOW);
  }
  
if (sensor interno == 1 ) {
  digitalWrite (motor esteira1,LOW) ;
  digitalWrite (motor esteira2,LOW);
  delay (6000);
  digitalWrite (motor esteira1,LOW);
  digitalWrite (motor esteira1,HIGH);
}

if ( sensor externo == 1 ) {
  digitalWrite (motor esteira1,LOW);
  digitalWrite (motor esteira1,LOW);
}

else 
  digitalWrite (motor esteira1,HIGH);
  digitalWrite (motor esterira2,LOW);
}

}
  
