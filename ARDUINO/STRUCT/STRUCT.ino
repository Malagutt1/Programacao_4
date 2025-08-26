/*STRUCT = AGRUPA VARIAVEIS DIVERSAS (INT, FLOAT E STRING):
struct  abc_type{
  int a;
  float b;
  String c;
}abc_array[10]; // ponto e virgula após definir o tamanho das linhas

void setup() {
  Serial.begin(9600);
  for (int i = 0; i<10; i++){
    // int | float | str
    abc_array[i].a = i;
    abc_array[i].b = i*random(1,5);
    abc_array[i].c = "b*10: " + String((abc_array[i].b )*0.10); 
  }
}

void loop() {
  for (int i = 0; i<10; i++){
    Serial.print ("  A: " + String(abc_array[i].a));
    Serial.print (" -B: " + String(abc_array[i].b));
    Serial.print (" -C:") + Serial.println(abc_array[i].c);
    delay(1000);
  }

}*/

struct rgb_types{
  int r,g,b,cont;
  String cor;
  } rgb_array[10];

int linha = 0;
int pinos[] = {11, 10, 9}; //R | G | B
int PushButtom1 = 2;
int pushMostraMatriz = 4;

void liga_led(int linha){
  for (int x=0; x <10; x++){
      if (x == linha){
        Serial.println("### Cor " + String(rgb_array[x].cor) + " no led RGB ###");  
        analogWrite(pinos[0], rgb_array[x].r);
        analogWrite(pinos[1], rgb_array[x].g);
        analogWrite(pinos[2], rgb_array[x].b);
        rgb_array[linha].cont++;
      }
    }
  
}

void LeituraPotenciometro() {
  Serial.println("##### LEITURA DO POTENCIOMETRO #####");
  linha = map(analogRead(A0), 0, 1023, 0, 9); // só 1 a 10
}

void Matriz_mostra() {
Serial.println("");
  Serial.println("##### QUANTIDADE DE VEZES ACESSADO CADA COR: #####");
  for (int i = 0; i <10 ; i++) {
    Serial.print("A cor " +String(rgb_array[i].cor));
    Serial.println(" foi acessada:  " + String(rgb_array[i].cont));
  }
}

void setup() {
  rgb_array[0].r = 255;
  rgb_array[0].g = 0;
  rgb_array[0].b = 0;
  rgb_array[0].cont = 0;
  rgb_array[0].cor = "Vermelho";

  rgb_array[1].r = 0;
  rgb_array[1].g = 255;
  rgb_array[1].b = 0;
  rgb_array[1].cont = 0;
  rgb_array[1].cor = "Verde";

  rgb_array[2].r = 0;
  rgb_array[2].g = 0;
  rgb_array[2].b = 255;
  rgb_array[2].cont = 0;
  rgb_array[2].cor = "Azul";

  rgb_array[3].r = 255;
  rgb_array[3].g = 255;
  rgb_array[3].b = 0;
  rgb_array[3].cont = 0;
  rgb_array[3].cor = "Amarelo";

  rgb_array[4].r = 150;
  rgb_array[4].g = 0;
  rgb_array[4].b = 255;
  rgb_array[4].cont = 0;
  rgb_array[4].cor = "Magenta";

  rgb_array[5].r = 0;
  rgb_array[5].g = 255;
  rgb_array[5].b = 255;
  rgb_array[5].cont = 0;
  rgb_array[5].cor = "Ciano";

  rgb_array[6].r = 139;
  rgb_array[6].g = 69;
  rgb_array[6].b = 19;
  rgb_array[6].cont = 0;
  rgb_array[6].cor = "Marrom";

  rgb_array[7].r = 255;
  rgb_array[7].g = 165;
  rgb_array[7].b = 0;
  rgb_array[7].cont = 0;
  rgb_array[7].cor = "Laranja";

  rgb_array[8].r = 170;
  rgb_array[8].g = 170;
  rgb_array[8].b = 170;
  rgb_array[8].cont = 0;
  rgb_array[8].cor = "Branco";

  rgb_array[9].r = 255;
  rgb_array[9].g = 165;
  rgb_array[9].b = 0;
  rgb_array[9].cont = 0;
  rgb_array[9].cor = "Laranja";


for (int i = 0; i < 3; i++) { // só 3 pinos
    pinMode(pinos[i], OUTPUT);
  }
  pinMode(PushButtom1, INPUT);
  pinMode(pushMostraMatriz, INPUT);
  Serial.begin(9600);
}


void loop() { // CHAMADOR DE FUNÇÕES
  if (digitalRead(PushButtom1) == HIGH) {
    LeituraPotenciometro();
    liga_led(linha);
    delay(500);
  }
  if (digitalRead(pushMostraMatriz) == HIGH) {
    Matriz_mostra();
    delay(500);
  }
}
