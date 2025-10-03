#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>
#define D7 13 // dht11
#define D6 12 //push
#define D3 0 //LED
#define DHTTYPE DHT11 // DHT 11
#define DHTPIN 13 // leitura DHT11
DHT dht(DHTPIN, DHTTYPE, 50);


const char *ssid = "TP-Link_688A";
const char *password = "debarbamiguel";
const int http_port = 8080;

WiFiClient client;

void setup() {
  delay(1000);
  pinMode(D0, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF); delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); Serial.println(".");
  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println ("");
  Serial.print ("Conectado a "); Serial.println (ssid);
  Serial.print ("EndereÃ§o IP: "); Serial.println (WiFi.localIP ());
  Serial.print("MAC: ");    Serial.println(WiFi.macAddress());

  pinMode(D3, OUTPUT);
  pinMode(D6, INPUT);
  digitalWrite(D3, LOW);

}
void enviaServer(String postData) {
  HTTPClient http;
  http.begin(client, "http://modulo4.migueldebarba.com.br/kaua/insertleitura.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(postData);
  String payload = http.getString();
  Serial.println("httpCode:" + String(httpCode));
  Serial.println("payload:" + payload);
  http.end();
}


void loop() {
  if (digitalRead(D6) == HIGH) {
    String Mac = WiFi.macAddress();
    float temperatura = dht.readTemperature( ) ;
    float umidade = dht.readHumidity();
    String from = "esp8266";
    
    String postData = "idmac=" + String(Mac) + 
   "&umidade=" + String(umidade) +
   "&from=" + String(from) +
   "&temperatura=" + String(temperatura);
   
    enviaServer(postData);
    digitalWrite(D3, HIGH);
    delay(1000);
    digitalWrite(D3, LOW);
  }
}
