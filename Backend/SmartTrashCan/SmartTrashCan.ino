#include <HCSR04.h>
#include <LiquidCrystal.h> // inclui a biblioteca para uso do Display LCD
// inicializa um objeto nos pinos para acesso as funções do LCD
const int RS = 7, EN = 6, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

UltraSonicDistanceSensor distanceSensor(13, 12);  // Inicia o sensor usando as portas digitais 13(trigger) e 12(echo)

int ledG = 8;
int ledY = 9;
int ledR = 10;

void setup(){
  // Configura o LCD com os número de colunas e linhas
  lcd.begin(16, 2); // 16 colunas e 2 linhas

  // Limpa o LCD
  lcd.clear();
  Serial.begin(9600);
  pinMode(ledG, OUTPUT); // verde
  pinMode(ledY, OUTPUT); // amarelo
  pinMode(ledR, OUTPUT); // vermelho
}

void loop(){
   float distancia = distanceSensor.measureDistanceCm();
   float porcent = distancia/40*100;

  Serial.println(distancia);

  // posiciona o cursor do LCD
  lcd.setCursor(0, 0); // (coluna 0, linha 2)
  lcd.print("Estou com :"); // Imprime mensagem
  // posiciona o cursor do LCD
  lcd.setCursor(0, 1); // (coluna 0, linha 2)
  lcd.print(porcent); // Imprime mensagem
  delay(1000);
  // posiciona o cursor do LCD
  lcd.setCursor(5, 1); // (coluna 0, linha 2)
  lcd.print("% livre :)"); // Imprime mensagem

 

  // Leds piscadores
 
  if(porcent < 15){
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH);
  }
  else if (porcent >= 15 && porcent <= 40){
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, HIGH);
  }
  else if (porcent > 40 && porcent <= 100){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
  }
  else if (porcent > 100){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);    
    digitalWrite(ledR, HIGH);
    
  }
}
