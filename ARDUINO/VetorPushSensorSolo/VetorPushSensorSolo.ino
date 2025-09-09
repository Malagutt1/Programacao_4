int ledverde=6;
int ledamarelo=5;
int ledvermelho=4;
int pushleitura=3;
int pushmostra=2;
int resist=0;
int vetor[5];
int i=0;
int cont=0;

void setup() {
  Serial.begin(9600);
  pinMode(pushleitura,INPUT);
  pinMode(pushmostra,INPUT);
  pinMode(ledverde,OUTPUT);
  pinMode(ledamarelo,OUTPUT);
  pinMode(ledvermelho,OUTPUT);
}

void leitura(){
  resist=analogRead(A0);
  Serial.println(resist);
  vetor[i]=resist;
  i++;  
  }

void mostra(){
  int soma=0;
  for (cont=0;cont<i;cont++){
    Serial.print(vetor[cont]);
    Serial.print("-");
    soma=soma+vetor[cont];
    }
    Serial.println("Media"+String(soma/i));
    delay(500);
  }  
void loop() {
  if (digitalRead(pushleitura)==HIGH &&i<5){leitura();}
  if (digitalRead(pushmostra)==HIGH){mostra();}
  delay(500);
}
