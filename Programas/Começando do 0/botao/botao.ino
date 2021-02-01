int led1 = 2;
int led2 = 3;
int led3 = 4;
int botao = 7;
int estadoBotao;

void setup() {
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (botao, INPUT);

}

void loop() {

  estadoBotao = digitalRead(botao);

  digitalWrite (led1, estadoBotao);
  digitalWrite (led2, estadoBotao);
  digitalWrite (led3, estadoBotao);

 
}
