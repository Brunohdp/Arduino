#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define endereco 0x27
#define colunas 16
#define linhas 2

LiquidCrystal_I2C lcd(endereco, colunas, linhas);

char* senha1 = "2510";
char* senha2 = "2079";
char* senha3 = "2181";
char* senha4 = "1109";
byte pl[] = {36,34,32,30};
byte pc[] = {37, 35, 33, 31};
char teclas[4][4] = {{'1','2','3','A'},
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};

Keypad teclado1 = Keypad (makeKeymap(teclas), pl, pc, 4, 4);

int position;
int bz = 0;
int sp = 0;

void setup() {
  tela();

}

void loop() {
  alarme(0);

}

void tela() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.print("INICIANDO...");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("Inicialização Completa!");
  delay(2000);

  lcd.noBacklight();
  lcd.clear();
}

void alarme(int on) {
  bool vSp = digitalRead(sp);

  while (position == 1){
      if (on){
          if(vSp == 1){
              digitalWrite(bz, 1);
          }
      } 
  }
}
