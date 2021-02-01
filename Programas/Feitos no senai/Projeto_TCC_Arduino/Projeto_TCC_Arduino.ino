const int lamp = 2;           // Lampada
int tmd = 4;                 // Tomada
int tmdvent = 6;              // Tomada do Ventilador
const int sp = 8;             // Sensor de Presença
int estadoSp = 0;
const int LM35 = A0;          // Sensor de luminosidade
float temperatura;



void setup() {
Serial.begin(9600);
pinMode(lamp, OUTPUT);
pinMode(tmd, OUTPUT);
pinMode(sp, INPUT);
pinMode(tmdvent, OUTPUT);
 }

void loop() {
  
estadoSp = digitalRead(sp);

if (estadoSp == 1) {
digitalWrite(lamp, 1);
digitalWrite(tmd, 1);
} else {
digitalWrite(lamp, 0);
digitalWrite(tmd, 0);
}

if  (estadoSp == 0){
digitalWrite(lamp, 0);
delay(10000);
digitalWrite(tmd, 0);
}

temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
Serial.print("Temperatura: ");
Serial.println(temperatura);
delay(200);

if(temperatura >23){
digitalWrite(tmdvent, 1);
}

if(temperatura <18){
digitalWrite(tmdvent, 0);
}

if (sp == 0)
{
digitalWrite(lamp, 0);
digitalWrite(tmd, 0);
digitalWrite(tmdvent, 0);
}
}
