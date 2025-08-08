int push = 4;
int push2 = 12;
int valorPot = 0;
int vetor[100];
int i = 0;
int menu = 0;
int SOMA = 0;
int Epar = 0;
int SOMAPAR = 0;
int SOMAIMPAR = 0;

void mostra(){
  Serial.println("Função mostra VALOR POT:");
  for (int num = 0; num < i; num++) {
      Serial.print(String(vetor[num]) + "-");   
      SOMA += vetor[num]; 
  }         
  Serial.println();
  Serial.println("A soma total é de: " + String(SOMA));
  delay(2000);  
}

void leitura(){
  valorPot = analogRead(A0);
  vetor[i] = valorPot;
  i++;
  Serial.println("ValorPot: " + String(valorPot));
}

void mostrapar(){
  Serial.println("Função mostra PAR:");
  for (int FORPAR = 0; FORPAR < i; FORPAR++) {
    if (vetor[FORPAR] % 2 == 0){
      Serial.print(String(vetor[FORPAR]) + "-");
      SOMAPAR += vetor[FORPAR];
    }
  }
  Serial.println();
  Serial.println("A soma dos números pares é: " + String(SOMAPAR));
  delay(2000); 
}

void mostraimpar(){
  Serial.println("Função mostra IMPAR:");
  for (int FORIMPAR = 0; FORIMPAR < i; FORIMPAR++) {
    if (vetor[FORIMPAR] % 2 != 0){
      Serial.print(String(vetor[FORIMPAR]) + "-");
      SOMAIMPAR += vetor[FORIMPAR];
    }
  }
  Serial.println();
  Serial.println("A soma dos números ímpares é: " + String(SOMAIMPAR));
  delay(2000); 
}

void setup() {
  pinMode(push, INPUT);
  pinMode(push2, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(push) == HIGH){ leitura();}
  if (digitalRead(push2) == HIGH){
    if (menu == 0){mostra();}
    if (menu == 1){mostrapar();}
    if (menu == 2){mostraimpar();}
    menu++;
    if (menu > 2){menu = 0;} 
  } // final push2 condicional
  delay(100); 
}
