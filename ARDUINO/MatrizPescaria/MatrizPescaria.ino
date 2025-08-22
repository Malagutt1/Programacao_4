/*Objetivo do projeto: simular uma pescaria onde o Arduino é o rio por onde passam
  os peixes(while). O peso do peixe é ajustado pelo potenciômetro que varia de 1 a 10 kg.
  Cada peixe fisgado(push) deverá ser inserido no cesto correspondente ao seu tamanho
  conforme a tabela abaixo respeitando sempre a capacidade de cada cesto. */
String debugger = "##############################"; // USADO PRA TESTAR SE A FUNÇÃ ESTA ENTRANDO (OCASIONALMENTE)
int peixe[3][7] = {
  // PESOmin, PESOmax, QuantidadeMax, QuantidadeAtual, PesoMaxKG, PesoAtual, VezesCheio[6]
  {1, 3, 9, 0, 30, 0, 0}, // peixe P
  {3, 6, 7, 0, 45, 0, 0}, // peixe M
  {7, 10, 6, 0, 65, 0, 0} // peixe G
};

int VaraPesca = 2; // pino 2
int InfoPesca = 8; // pino 8 || Mostra informações da pesca nos cestos

void setup() {
  pinMode(VaraPesca, INPUT);
  pinMode(InfoPesca, INPUT);
  Serial.begin(9600);
}

void MostraMatriz() {
  Serial.println("########## MOSTRAR CAIXA DE PEIXES ##########");
  for (int MM = 0; MM < 3; MM++) {
    if (MM == 0) {
      Serial.print("Total peso Peixe Pequeno: ");
      Serial.println(peixe[MM][5]);
    }
    else if (MM == 1) {
      Serial.print("Total peso Peixe Medio: ");
      Serial.println(peixe[MM][5]);
    }
    else {
      Serial.print("Total peso Peixe Grande: ");
      Serial.println(peixe[MM][5]);
    }
  }
  Serial.println("#############################################");
}


void pesca() {
  int peso = map(analogRead(A0), 0, 1023, 1, 10);
  Serial.println(); // quebra de linha
  Serial.println("### PEIXE PESCADO ###");
  Serial.println ("peso: " + String(peso) + "KG");

  /*For para mostrar quantidade e peso*/
  for (int i = 0; i < 3; i++) {
    if ((peso >= peixe[i][0]) && (peso <= peixe[i][1])) {
      peixe[i][3] = peixe[i][3] + 1; //soma quantidade
      peixe[i][5] = peixe[i][5] + peso; //soma peso
    
    if ((peixe[i][5] > peixe[i][4]) || (peixe[i][3] > peixe[i][2])) {
        peixe[i][6]++; // incrementa contador de vezes que encheu
        Serial.println("⚠️ Cesto do tipo " + String(i) + " encheu!");
      }
    }
  }
}

void loop() {
  if (digitalRead(VaraPesca) == HIGH ) {
    pesca();
    delay(500);
  }
  if (digitalRead(InfoPesca) == HIGH) {
    MostraMatriz();
    delay(500);
  }

}
