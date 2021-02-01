int led[9] = {2,3,4,5,6,7,8,9,10};        //uma variável com variáveis dentro. Define todas as 9 portas em 1 variável
int x;                                    //variável que substitui o n de portas p/ comando for
int nLed;                                 //variável que diz o n de leds
int t = 100;                              //delay
char digitado;                            //variável p/ dizer qual letra tem que aparecer na porta serial p/ parar os leds

void setup() {

  for (x = 0; x <= 8; x = x + 1){         //for vai ler as portas de 0 (pin 2) até menor ou igual a 8 (pin 10), somando de 1 em 1
    pinMode (led[x], OUTPUT);             //define todos os x como saídas
  }

  Serial.begin(9600);                     //inicia comunicação serial; 9600 é a velocidade
 
}

void loop() {

  digitado = ' ';                         //começa com um espaço
  nLed = 0;                               
  while ( digitado != 'P') {              /*enquanto o que estiver aparecendo na porta serial for diferente de P, os 
                                            leds vão continuar passando. Quando aparecer a letra, os leds param */
     digitalWrite (led[nLed], 0);         //diz que todos os leds apagam
     nLed = nLed + 1;
     if (nLed > 8) {                      //se número do led passar do 8 ele volta ao 0
     nLed = 0;
      }
     digitalWrite (led[nLed], 1);         //acende o número do led dnv

     if (Serial.available()) {            //lê a porta serial pra ver se a letra P aparece
       digitado = Serial.read();
      }
      
      delay (50);
    }

    delay (5000);
}
