int pinos[] = {11, 10, 9}; // R, G, B
int matriz[8][8] {  
  {255, 0, 0},     // red
  {0, 255, 0},     // green
  {0, 0, 255},     // blue
  {115, 255, 0},   // yellow
  {122, 255, 255}, // white
  {122, 0, 255},   // purple
  {0, 255, 255},   // cyan
  {90, 110, 110}  // gray
};                           
  
void setup() {
  for (int i = 0; i < 3; i++) { // só 3 pinos
    pinMode(pinos[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 8; i++) { // percorre as 8 cores
    for (int c = 0; c < 3; c++) { // só 3 valores RGB
      analogWrite(pinos[c], matriz[i][c]);
    }
    Serial.print("Cor ");
    Serial.println(i);
    delay(1000); // espera 1 segundo
  }
}
