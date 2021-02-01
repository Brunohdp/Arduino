#include <Keypad.h>

byte pinosLinhas[] = {52,50,48,46};
byte pinosColunas[] = {53,51,49,47};
char teclas [4][4] = {{'1','2','3','A'},
                      {'4','5','6','B'},
                      {'7','8','9','C'},
                      {'*','0','#','D'}};

Keypad teclado1 = Keypad (makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 4);

void setup() {
  Serial.begin(9600);
  Serial.println ("Teclado 4x4 com biblioteca");
  Serial.println ("aguardando teclas");
  Serial.println ();

}

void loop() {
   char tecla_pressionada = teclado1.getKey();

  if (tecla_pressionada) {
    Serial.print("tecla: ");
    Serial.println(tecla_pressionada);
  }

}
