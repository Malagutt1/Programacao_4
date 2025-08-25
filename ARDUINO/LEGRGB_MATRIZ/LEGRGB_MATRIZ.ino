int pinos[] = {11, 10, 9}; //R | G | B
int PushButtom1 = 2;
int pushMostraMatriz = 4;
int matrizRGB[6][4] = { // red | green | blue | contador
  {255, 0, 0, 0},    //red
  {0, 255, 0, 0},    //green
  {0, 0, 255, 0},    //blue
  {255, 255, 0, 0},  //AMARELO
  {150, 0, 255, 0},  //MAGENTA
  {100, 0, 128, 0}   // ROSA
};

void LeituraPotenciometro() {
  Serial.println("##### LEITURA DO POTENCIOMETRO #####");
  int linha = map(analogRead(A0), 0, 1023, 1, 6); // só 1 a 6

  if (linha == 1){
    Serial.println("##### COR VERMELHA NO LED! #####");
    matrizRGB[linha-1][3]++;
    analogWrite(pinos[0], matrizRGB[linha-1][0]);
    analogWrite(pinos[1], matrizRGB[linha-1][1]);
    analogWrite(pinos[2], matrizRGB[linha-1][2]);
  }
  else if (linha == 2){
    Serial.println("##### COR VERDE NO LED! #####");
    matrizRGB[linha-1][3]++;
    analogWrite(pinos[0], matrizRGB[linha-1][0]);
    analogWrite(pinos[1], matrizRGB[linha-1][1]);
    analogWrite(pinos[2], matrizRGB[linha-1][2]);
  }
  else if (linha == 3){
    Serial.println("##### COR AZUL NO LED! #####");
    matrizRGB[linha-1][3]++;
    analogWrite(pinos[0], matrizRGB[linha-1][0]);
    analogWrite(pinos[1], matrizRGB[linha-1][1]);
    analogWrite(pinos[2], matrizRGB[linha-1][2]);
  }
  else if (linha == 4){
    Serial.println("##### COR AMARELA NO LED! #####");
    matrizRGB[linha-1][3]++;
    analogWrite(pinos[0], matrizRGB[linha-1][0]);
    analogWrite(pinos[1], matrizRGB[linha-1][1]);
    analogWrite(pinos[2], matrizRGB[linha-1][2]);
  }
  else if (linha == 5){
    Serial.println("##### COR MAGENTA NO LED! #####");
    matrizRGB[linha-1][3]++;
    analogWrite(pinos[0], matrizRGB[linha-1][0]);
    analogWrite(pinos[1], matrizRGB[linha-1][1]);
    analogWrite(pinos[2], matrizRGB[linha-1][2]);
  }
  else if (linha == 6){
    Serial.println("##### COR ROSA NO LED! #####");
    matrizRGB[linha-1][3]++;
    analogWrite(pinos[0], matrizRGB[linha-1][0]);
    analogWrite(pinos[1], matrizRGB[linha-1][1]);
    analogWrite(pinos[2], matrizRGB[linha-1][2]);
  }
}

void Matriz_mostra() {
  int total = 0;
  for (int i = 0; i < 6; i++) {
    total += matrizRGB[i][3];
  }

  Serial.println("");
  Serial.println("##### QUANTIDADE DE VEZES ACESSADO CADA COR: #####");
  for (int i = 0; i < 6; i++) {
    if (i == 0) {
      Serial.print("COR VERMELHA: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
    } else if (i == 1) {
      Serial.print("COR VERDE: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
    } else if (i == 2) {
      Serial.print("COR AZUL: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
    } else if (i == 3) {
      Serial.print("COR AMARELA: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
    } else if (i == 4) {
      Serial.print("COR MAGENTA: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
    } else if (i == 5) {
      Serial.print("COR ROSA: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
    }
  }
}

void setup() {
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
    delay(500);
  }
  if (digitalRead(pushMostraMatriz) == HIGH) {
    Matriz_mostra();
    delay(500);
  }
}
