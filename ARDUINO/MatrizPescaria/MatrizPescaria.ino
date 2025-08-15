/*Objetivo do projeto: simular uma pescaria onde o Arduino é o rio por onde passam
os peixes(while). O peso do peixe é ajustado pelo potenciômetro que varia de 1 a 10 kg.
Cada peixe fisgado(push) deverá ser inserido no cesto correspondente ao seu tamanho
conforme a tabela abaixo respeitando sempre a capacidade de cada cesto.                    */
int peixe[3][6] = {
  // PESOmin, PESOmax, QuantidadeMax, QuantidadeAtual, PesoMaxKG, PesoAtual
  {1, 3, 9, 0, 30, 0}, // peixe P
  {3, 6, 7, 0, 45, 0}, // peixe M
  {7, 10, 6, 0, 65, 0} // peixe G
};

int VaraPesca = 2; // pino 2

void setup() {
  pinMode(VaraPesca, INPUT);
  Serial.begin(9600);
}

void pesca() {
  int peso = map(analogRead(A0), 0, 1023, 1, 11);
    
  Serial.println(); // quebra de linha
  Serial.println("### PEIXE PESCADO ###");
  Serial.println ("peso: " + String(peso) + "KG");
  


  for (int i = 0; i < 3; i++) {
    if ((peso > peixe[i][0]) && (peso <= peixe[i][1])) {
      peixe[i][3] = peixe[i][3] + 1; //soma quantidade
      peixe[i][5] = peixe[i][5] + peso; //soma peso
      
    }
  }
}

void loop() {
  if (digitalRead(VaraPesca) == HIGH ){pesca(); delay(2000);}
    
}
