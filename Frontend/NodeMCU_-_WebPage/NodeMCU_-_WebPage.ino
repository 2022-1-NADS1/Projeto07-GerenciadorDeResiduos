#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "index_html.h"
// LED Amarelo
#define D1 5 
// LED Vermelho
#define D2 4
// LED Verde
#define D3 3

ESP8266WebServer server(80);

String lixeira = ""; // Armazenar a string que será impressa na página
int estado = D1;

void setup() {
Serial.begin(115200);
pinMode (5, INPUT); // Vai receber o sinal que for enviado pelo Led amarelo
pinMode (4, INPUT); // Vai receber o sinal que for enviado pelo Led Vermelho
pinMode (3, INPUT); // Vai receber o sinal que for enviado pelo Led Verde

WiFi.mode(WIFI_STA);
WiFi.begin("boanoite","18112167");
Serial.println("");
// espera a conexao
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.print("Conectado ");
Serial.println(WiFi.localIP());

server.on("/",Chamaeu);
server.on("/LED",ChamaLed);
server.begin();
pinMode(LED_BUILTIN, OUTPUT);
//pinMode(A0, OUTPUT);
}
void Chamaeu(){
//server.send(200,"text/plain", "ola");

String page=INDEX_HTML + INDEX_HTMLmid + lixeira + INDEX_HTMLfinal;

server.send(200,"text/html", page);
}
void ChamaLed(){
digitalWrite(LED_BUILTIN, HIGH);
}
void loop() {
server.handleClient();

if (digitalRead(5)==LOW && digitalRead(4)==LOW && digitalRead(D3)==HIGH)
{
 lixeira = "To relax, brota";
  Serial.println("Não estou recebendo sinal da Amarela nem da vermelha, mas estou recebendo da verde");
}
else if (digitalRead(5)==HIGH && digitalRead(4)==HIGH && digitalRead(D3)==HIGH)
{
  lixeira = "Estou em manutenção, aguarde";
  Serial.println("Estou recebendo sinal da amarela, vermelha e verde");
}
else if (digitalRead(5)==HIGH || digitalRead(4)==LOW && digitalRead(D3)==LOW)
{
  lixeira = "Socorrooo, estou ficando cheia";
  Serial.println("Estou recebendo sinal da Vermelha, mas não da amarela nem da verde");
}

delay(1000);
}
