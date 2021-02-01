int v = 2;                          //led verde
int a = 3;                          //led amarelo
int vm = 4;                         //led vermelho
int t1 = 1200;                      //delay do verdo p/ amarelo e vermelho p/ verde
int t2 = 600;                      //delay do amarelo p/ vermelho


void setup() {
  pinMode (v, OUTPUT);
  pinMode (a, OUTPUT);
  pinMode (vm, OUTPUT);
}

void loop() {
  digitalWrite (v, 1);
  digitalWrite (a, 0);
  digitalWrite (vm, 0);
  delay (t1);

  digitalWrite (v, 0);
  digitalWrite (a, 1);
  digitalWrite (vm, 0);
  delay (t2);

  digitalWrite (v, 0);
  digitalWrite (a, 0);
  digitalWrite (vm, 1);
  delay (t1);
}
