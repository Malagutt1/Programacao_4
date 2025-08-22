int pinos[] = {11, 10, 9}; //R | G | B
int PushButtom1 = 2;
int pushMostraMatriz = 4;
int matrizRGB[6][4] = { // red | green | blue | contador
  {255, 0, 0, 0}, //red
  {0, 255, 0, 0}, //green
  {0, 0, 255, 0}, //blue
  {255, 255, 0, 0}, //AMARELA
  {150, 0, 255, 0}, //MAGENTA
  {128, 0, 128, 0}  //ROSA
};

String nomesCor[6] = {"VERMELHA", "VERDE", "AZUL", "AMARELA", "MAGENTA", "ROSA"};

void LeituraPotenciometro() {
  Serial.println("##### LEITURA DO POTENCIOMETRO #####");
  int linha = map(analogRead(A0), 0, 1023, 0, 5); // índice correto 0-5

  Serial.println("##### COR " + nomesCor[linha] + " NO LED! #####");
  matrizRGB[linha][3]++;

  analogWrite(pinos[0], matrizRGB[linha][0]); // R
  analogWrite(pinos[1], matrizRGB[linha][1]); // G
  analogWrite(pinos[2], matrizRGB[linha][2]); // B
}

void Matriz_mostra() {
  int total = 0;
  for (int i = 0; i < 6; i++) total += matrizRGB[i][3];

  Serial.println("##### QUANTIDADE DE VEZES ACESSADO CADA COR: #####");
  for (int i = 0; i < 6; i++) {
    Serial.print("COR " + nomesCor[i] + ": ");
    Serial.print(matrizRGB[i][3]);
    Serial.print(" vezes! ");
    float percentual = (total == 0) ? 0 : (matrizRGB[i][3] * 100.0 / total);
    Serial.print(percentual, 2);
    Serial.println("%");
  }
}

void setup() {
  for (int i = 0; i < 3; i++) pinMode(pinos[i], OUTPUT);
  pinMode(PushButtom1, INPUT);
  pinMode(pushMostraMatriz, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PushButtom1) == HIGH) {
    LeituraPotenciometro();
    delay(500);
  }
  if (digitalRead(pushMostraMatriz) == HIGH) {
    Matriz_mostra();
    delay(500);
  }
}
