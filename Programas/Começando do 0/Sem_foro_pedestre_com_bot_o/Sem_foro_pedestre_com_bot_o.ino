int v = 2;                                    //define pino 2 como led verde
int a = 3;                                                      //pino 3 como led amarelo
int vm = 4;                                                     //pino 4 led vermelho
int botao = 10;                                                  //pino 5 botão
int pv = 8;                                                     //pino 7 led verde do pedestre
int pvm = 9;                                                    //pino 8 led vermelho pedestre

int faseSemaforo;                                               //ver qual fase que o semaforo esta: 1,2,3,4

int estadoBotao;                                                //ver qual o estado que o botao esta 0 ou 1
int estadoAnteriorBotao;                                        //ver qual o estado que o botao estava antes do atual

int tempoPisca;
int estadoPisca;


void setup() {

    pinMode (v, OUTPUT);
    pinMode (a, OUTPUT);
    pinMode (vm, OUTPUT);
    pinMode (pv, OUTPUT);
    pinMode (pvm, OUTPUT);
    pinMode (botao, INPUT);

    faseSemaforo = 1;                                              //fase que o semaforo inicia

    estadoAnteriorBotao = digitalRead(botao);                      //le o estado anterior do botao

    tempoPisca = 0;                                                //inicia o tempo do pisca com 0
    estadoPisca = 1;                                               //inicia com pisca aceso

}

void loop() {

  estadoBotao = digitalRead(botao);

  if ((estadoBotao == 1) && (estadoAnteriorBotao == 0)){            //Se o botão estiver ligado, mas estava desligado antes aí segue o programa
    
     if (faseSemaforo < 4){                                         //se a fase do semáforo for a quarta ou anterior a isso...
       faseSemaforo = faseSemaforo + 1;                             //... soma 1 a fase do semaforo quando aperta o botao
     } else {
     faseSemaforo = 1;                                              //se for maior que 4, volta pra fase 1
     }
  }
   if (faseSemaforo == 1) {                                         //fase 1: sinal verde aberto e vermelho p/ pedestre
      digitalWrite (v, 1);
      digitalWrite (a, 0);
      digitalWrite (vm, 0);

      digitalWrite (pv, 0);
      digitalWrite (pvm, 1);
    }

    estadoAnteriorBotao = estadoBotao;                              //o estado anterior do botao é igual ao estado atual

   if (faseSemaforo == 2) {                                         //fase 2: sinal amarelo e vermelho p/ pedestre
      digitalWrite (v, 0);
      digitalWrite (a, 1);
      digitalWrite (vm, 0);

      digitalWrite (pv, 0);
      digitalWrite (pvm, 1);
    }

   if (faseSemaforo == 3) {                                         //fase 3: sinal vermelho e verde p/ pedestre
      digitalWrite (v, 0);
      digitalWrite (a, 0);
      digitalWrite (vm, 1);

      digitalWrite (pv, 1);
      digitalWrite (pvm, 0);
    }

   if (faseSemaforo == 4) {                                         //fase 4: sinal vermelho e pisca sinal verde do pestre antes de voltar a ficar vermelho na fase 1
      digitalWrite (v, 0);
      digitalWrite (a, 0);
      digitalWrite (vm, 1);

      tempoPisca = tempoPisca + 1;

      if (tempoPisca == 400) {                                      //se o tempo do pisca for 400...
        estadoPisca = !estadoPisca;                                 //...estado do pisca vai ser o inverso do que esta, fazendo com que pisque
        tempoPisca = 0;                                             //tempo do pisca volta a 0
      }

      digitalWrite (pv, estadoPisca);                               //led verde do pedestre é igual ao estado do pisca, ou seja, piscando
      digitalWrite (pvm, 0);
    }
    delay (1);
  
}
