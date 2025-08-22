
/*Montar um circuito com led RGB + potenciômetro para selecionar uma cor entre as seis cores disponíveis na MatrizRGB.

  Ao pressionar o PushButtom1 pegar o valor do potenciômetro(0-5) e selecionar a cor definida na Matriz. 
  O LedRGB deverá acender na respectiva cor.

  O PushButtom2 serve para mostrar quantas vezes cada cor foi selecionada bem como seu percentual 
  em relação ao total de cores escolhidas.

  Ao final, salve o código em um arquivo juntamente com uma foto do projeto, 
  coloque os dois arquivos em uma pasta zipada e envie como resposta desta atividade.
*/
int pinos[] = {11, 10, 9}; //R | G | B
int PushButtom1 = 2;
int pushMostraMatriz = 4;
int matrizRGB[6][4] = { // red | green | blue | contador
  {255, 0, 0, 0}, //red
  {0, 255, 0, 0},//green
  {0, 0, 255, 0},//blue
  {255, 255, 0, 0}, // AMARELO
  {150, 0, 255, 0}, //MAGENTA
  {128, 0, 128, 0}  // ROSDA
};

void LeituraPotenciometro() {
  Serial.println("##### LEITURA DO POTENCIOMETRO #####");
  int linha = map(analogRead(A0), 0, 1023, 1, 6);

  if (linha == 1) {
    Serial.println("##### COR VERMELHA NO LED! #####");
    Serial.println("");
    matrizRGB[linha][3] = matrizRGB[linha][3] + 1;
  }
  else if (linha == 2) {
    Serial.println("##### COR VERDE NO LED! #####");
    Serial.println("");
    matrizRGB[linha][3] = matrizRGB[linha][3] + 1;
  }
  else if (linha == 3) {
    Serial.println("##### COR AZUL NO LED! #####");
    Serial.println("");
    matrizRGB[linha][3] = matrizRGB[linha][3] + 1;
  }
  else if (linha == 4) {
    Serial.println("##### COR AMARELO NO LED! #####");
    Serial.println("");
    matrizRGB[linha][3] = matrizRGB[linha][3] + 1;
  }
  else if (linha == 5) {
    Serial.println("##### COR MAGENTA NO LED! #####");
    Serial.println("");
    matrizRGB[linha][3] = matrizRGB[linha][3] + 1;
  }
  else if (linha == 6) {
    Serial.println("##### COR ROSA NO LED! #####");
    Serial.println("");
    matrizRGB[linha][3] = matrizRGB[linha][3] + 1;

  }

}

void Matriz_mostra() {
  int total = 0;
  for (int i = 0; i < 6; i++) {
    total += matrizRGB[i][3];
  }
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
      float percentual = (total == 0) ? 0 : (matrizRGB[i][3] * 100.0 / total);
      Serial.print(percentual, 2);
      Serial.println("%");

    } else if (i == 2) {
      Serial.print("COR AZUL: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
      float percentual = (total == 0) ? 0 : (matrizRGB[i][3] * 100.0 / total);
      Serial.print(percentual, 2);
      Serial.println("%");

    } else if (i == 3) {
      Serial.print("COR AMARELA: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
      float percentual = (total == 0) ? 0 : (matrizRGB[i][3] * 100.0 / total);
      Serial.print(percentual, 2);
      Serial.println("%");

    } else if (i == 4) {
      Serial.print("COR MAGENTA: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
      float percentual = (total == 0) ? 0 : (matrizRGB[i][3] * 100.0 / total);
      Serial.print(percentual, 2);
      Serial.println("%");

    } else if (i == 5) {
      Serial.print("COR ROSA: ");
      Serial.print(matrizRGB[i][3]);
      Serial.println(" vezes!");
      float percentual = (total == 0) ? 0 : (matrizRGB[i][3] * 100.0 / total);
      Serial.print(percentual, 2);
      Serial.println("%");
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
