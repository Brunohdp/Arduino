/*
*  Expansão de portas utilizando shift register o CI 74HC595 E CI PCF8574
*  Curso Técnico de Eletroeletronica
*  SENAI CPF 7.91 BOTUCATU - SP,
*/



#include <Wire.h>                  //Inclusão da biblioteca Wirw para uso com o CI PCF8574
#include <SPI.h>                   //Inclusão da biblioteca para biblioteca para habilitar a comunicação paralela serial
#include <LiquidCrystal.h>
LiquidCrystal lcd(10);
int D20 = 0b00000001;            //variavel binária PCF8574
int D21 = 0b00000010;
int D22 = 0b00000100;
int D23 = 0b00001000;
int D24 = 0b00010000;
int D25 = 0b00100000;
int D26 = 0b01000000;
int D27 = 0b10000000;



void setup() {
  {
   Wire.begin();
   lcd.begin(16, 2);
   lcd.print(" Somos SENAI! ");
  }
}

void loop() 
  {
   Wire.beginTransmission(0X20);
   Wire.write(D22);
   Wire.endTransmission();
   lcd.setCursor(0, 1);
   lcd.print(" Controlador");
  }
