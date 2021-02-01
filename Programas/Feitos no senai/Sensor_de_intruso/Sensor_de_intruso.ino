
/*
 * SENSOR DE INTRUSOS
 * SENAI CFP 7.91 BOTUCATU SP
 * CURSO TECNICO DE ELETROELETRONICA
 * ALUNO MICAELISON PIRES, Murilo Vendramini
 */
 #include <NewPing.h>       // Chama a biblioteca NewPing
 #include <Servo.h>         // Chama a biblioteca servo
 #define trigPin 12         // Pino do disparo do ultrassom
 #define echoPin 13         // Pino do echo do ultrassom
 #define MAX_DISTANCE 500

 NewPing sonar(trigPin, echoPin, MAX_DISTANCE);    // ConfiguraÃƒÂ§ÃƒÂ£o da biblioteca

 int greenLed = 3, redLed = 2;       // Associa o led verde ao pino 3 e led vermelho ao pino 2

 int pos = 20;
 Servo myservo;
 
void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(greenLed,OUTPUT);
 pinMode(redLed, OUTPUT);
 myservo.attach(9);           // Servomotor conectado ao pino 9

}

void loop() {
  int duration, distance, pos = 0, i;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);     // O pino Trig envia o ping
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);   // O pino Echo recebe o ping
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 15)            // Se o sensor detectar objeto a menos de 15 cm
  {
    digitalWrite(greenLed, LOW);   // Desliga led verde
    digitalWrite(redLed, HIGH);    // Liga led vermelho
    myservo.write(180);            // Movimenta o braco do servomotor em 180 graus
    delay(450);
    digitalWrite(redLed, LOW);     // Desliga led vermelho
    myservo.write(90);
    delay(450);
    digitalWrite(redLed, HIGH);
    myservo.write(0);
    delay(450);
    digitalWrite(redLed, LOW);
    myservo.write(90);
  }
  else {           // Se a condicao acima nao for verdadeira faca
    digitalWrite(redLed, LOW);   // Desliga LED vermelho
    digitalWrite(greenLed, HIGH); // Liga LED verde
    myservo.write(90);
  }

  delay(450);
  

}


