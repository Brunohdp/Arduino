int LED = 9;                  // Pino no qual o LED está conectado
int BOTAO = 7;                // Pino no qual o Botão está conectado
int valor = LOW;
int valorAnterior = LOW;
int estado = 0;               // 0 = LED apagado, 1 = LED aceso
int brilho = 128;
unsigned long inicio;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);      //Definir o pino como saída
  pinMode(BOTAO, INPUT);     // Definir o pino como entrada 
}

void loop() {
  {
   valor = digitalRead(BOTAO);
   if ((valor == HIGH) && (valorAnterior == LOW))
    {
   estado = 1 - estado;
   inicio = millis();   // Obtém a quantidade de milisegundos após
                        // o Arduino ser inicializado
   delay (10);
   } 
   // Verifica se o botao está segurado pressionado
   if ((valor == HIGH) && (valorAnterior))
   {
   //verifica se o botão está pressionado por mais de 0,5 segundos 
   if (estado == 1 && (millis() - inicio) > 500)
   
  { 
   brilho++;
   delay(10); 

   if (brilho > 255)
        brilho =

