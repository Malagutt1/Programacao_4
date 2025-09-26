#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char *ssid = "TP-Link_688A";
const char *password = "debarbamiguel";
const int http_port = 8080;

WiFiClient client;

void setup() {
  delay(1000);
  pinMode(D0,OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);Serial.println(".");
  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);Serial.print(".");}
    Serial.println ("");
    Serial.print ("Conectado a ");Serial.println (ssid);
    Serial.print ("EndereÃ§o IP: ");Serial.println (WiFi.localIP ());
    Serial.print("MAC: ");    Serial.println(WiFi.macAddress());    
}
void enviaServer(String postData){
    HTTPClient http;
    http.begin(client,"http://modulo4.migueldebarba.com.br/kaua/insertleitura.php");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpCode = http.POST(postData);
    String payload = http.getString();
    Serial.println("httpCode:"+String(httpCode));
    Serial.println("payload:"+payload);
    http.end();
  }

void loop() {
    String Mac = WiFi.macAddress();    
    int umidade=random(1,100);
    int temperatura = random(18, 26);
    String dataleitura = "2025-09-26";
    String horaleitura = "16:35";
    
    String postData = "idmac=" + String(Mac) +
      "&umidade=" + String(umidade) +
      "&temperatura=" + String(temperatura) +
      "&dataleitura=" + String(dataleitura) +
      "&horaleitura=" + String(horaleitura);
    enviaServer(postData); 
  
    delay(random(10000,45000));
}
