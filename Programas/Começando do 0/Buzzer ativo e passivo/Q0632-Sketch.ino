/*
 *   CÓDIGO:    Q0632
 *   AUTOR:     BrincandoComIdeias
 *   ACOMPANHE: https://www.youtube.com/brincandocomideias ; https://www.instagram.com/canalbrincandocomideias/
 *   APRENDA:   https://cursodearduino.net/ ; https://cursoderobotica.net
 *   COMPRE:    https://www.arducore.com.br/
 *   SKETCH:    Buzzer ativo vs passivo
 *   DATA:      18/02/2020
*/

// INCLUSÃO DE BIBLIOTECAS
#include <PushButton.h>
#include "notas.h"

// DEFINIÇÕES DE PINOS
#define pinBotao1 2
#define pinBotao2 3
#define pinBotao3 4
#define pinBotao4 5
#define pinBotao5 6
#define pinBotao6 7

#define buzzerAtivo 8
#define buzzerPassivo 9

// INSTANCIANDO OBJETOSs
PushButton botao1(pinBotao1);
PushButton botao2(pinBotao2);
PushButton botao3(pinBotao3);
PushButton botao4(pinBotao4);
PushButton botao5(pinBotao5);
PushButton botao6(pinBotao6);

// DECLARAÇÃO DE FUNÇÕES
void bipAtivo(int tempoBip);
void bipPassivo(int tempoBip, int frequenciaBip = 300);
void musicaAtivo();
void musicaPassivo();
void alertaAtivo();
void alertaPassivo();

// DECLARAÇÃO DE VARIÁVEIS  
int frequencia = 0;
int tempo = 10;
int melodia[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int duracaoNotas[] = {4, 8, 8, 4, 4, 4, 4, 4 };

void setup() {
  pinMode (buzzerAtivo, OUTPUT);
  pinMode (buzzerPassivo, OUTPUT);
  
}

void loop() {
  botao1.button_loop();  botao2.button_loop();
  botao3.button_loop();  botao4.button_loop();
  botao5.button_loop();  botao6.button_loop();

  if ( botao1.pressed() ) {
    bipAtivo(250);
    delay(2000);
    bipAtivo(750);
    delay(2000);
    bipAtivo(1500);
    delay(2000);

  } else if ( botao2.pressed() ) {
    bipPassivo(250);
    delay(2000);
    bipPassivo(750, 800);
    delay(2000);
    bipPassivo(1000, 1500);
  
  } else if ( botao3.pressed() ) musicaAtivo();
    
    else if ( botao4.pressed() ) musicaPassivo();
    
    else if ( botao5.pressed() ) {
      alertaAtivo();
      alertaAtivo();
      alertaAtivo();
      alertaAtivo();
      alertaAtivo();
  
  } else if ( botao6.pressed() ) alertaPassivo();

}

void bipAtivo(int tempoBip) {
  digitalWrite(buzzerAtivo, HIGH);
  delay(tempoBip);
  digitalWrite (buzzerAtivo, LOW);
}

void bipPassivo(int tempoBip, int frequenciaBip = 300) {
  tone(buzzerPassivo, frequenciaBip, tempoBip);
}

void musicaAtivo() {
  for (int notaAtual = 0; notaAtual < 8; notaAtual++) {
    int duracaoNota = 1000 / duracaoNotas[notaAtual];
    tone(buzzerAtivo, melodia[notaAtual] * 4, duracaoNota);
    int pausaEntreNotas = duracaoNota * 1.30;
    delay(pausaEntreNotas);
    noTone(buzzerAtivo);
  }

}

void musicaPassivo() {
  for (int notaAtual = 0; notaAtual < 8; notaAtual++) {
    int duracaoNota = 1000 / duracaoNotas[notaAtual];
    tone(buzzerPassivo, melodia[notaAtual] * 4, duracaoNota);
    int pausaEntreNotas = duracaoNota * 1.30;
    delay(pausaEntreNotas);
    noTone(buzzerPassivo);
  }

}

void alertaAtivo() {
  bipAtivo(150);
  //bipAtivo(50);
  //bipAtivo(50);
  delay(500);
}

void alertaPassivo() {
  for (frequencia = 150; frequencia < 1800; frequencia ++) {
    tone(buzzerPassivo, frequencia, tempo);
    delay(1);
  }

  for (frequencia = 1800; frequencia > 150; frequencia --) {
    tone(buzzerPassivo, frequencia, tempo);
    delay(1);
  }
}
