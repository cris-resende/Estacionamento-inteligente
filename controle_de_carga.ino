//Bibliotecas
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SoftwareSerial.h>

//Pinos
const int tx = 4, rx = 3;
const int servo1 = 12;
const int servo2 = 13;
const int trig1 = 34, echo1 = 33;
const int trig2 = 29, echo2 = 30;
const int trig3 = 31, echo3 = 32;
const int trig4 = 28, echo4 = 27;
const int trig5 = 26, echo5 = 25;
const int trig6 = 34, echo6 = 35;
const int trig7 = 36, echo7 = 37;
const int trig8 = 38, echo8 = 39;
const int buzzer = 42;
const int led1 = 8, led2 = 9, led3 = 36, led4 = 38, led5 = 40, led6 = 41;

//Objetos
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servomotor, servomotor2;
SoftwareSerial Bluetooth(tx, rx);

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);
  Serial.println("CÓDIGO INICIANDO SETUP");
  lcd.init();
  lcd.backlight();
  servomotor.attach(12);
  servomotor2.attach(13);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig4, OUTPUT);
  pinMode(echo4, INPUT);
  pinMode(trig5, OUTPUT);
  pinMode(echo5, INPUT);
  pinMode(trig6, OUTPUT);
  pinMode(echo6, INPUT);
  pinMode(trig7, OUTPUT);
  pinMode(echo7, INPUT);
  pinMode(trig8, OUTPUT);
  pinMode(echo8, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.println("CÓDIGO FINALIZANDO SETUP");
}

void loop() {
  //Variáveis
  float tempo, distancia1, distancia2, distancia3, distancia4, distancia5, distancia6, distancia7, distancia8;
  bool sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7, sensor8;
  String recebido;
  byte vaga;

  //Lógica
  if (Bluetooth.available() > 0) {
    recebido = Bluetooth.readString();
    if (digitalRead(buzzer) == 0){
      digitalWrite(buzzer, HIGH);
    }
  }
  Serial.println("CÓDIGO INICIANDO LOOP");
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  tempo = pulseIn(echo1, HIGH);
  distancia1 = tempo / 2 * 0.0344;

  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  tempo = pulseIn(echo2, HIGH);
  distancia2 = tempo / 2 * 0.0344;

  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
  tempo = pulseIn(echo3, HIGH);
  distancia3 = tempo / 2 * 0.0344;

  digitalWrite(trig4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig4, LOW);
  tempo = pulseIn(echo4, HIGH);
  distancia4 = tempo / 2 * 0.0344;

  digitalWrite(trig5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig5, LOW);
  tempo = pulseIn(echo5, HIGH);
  distancia5 = tempo / 2 * 0.0344;

  digitalWrite(trig6, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig6, LOW);
  tempo = pulseIn(echo6, HIGH);
  distancia6 = tempo / 2 * 0.0344;

  digitalWrite(trig7, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig7, LOW);
  tempo = pulseIn(echo7, HIGH);
  distancia7 = tempo / 2 * 0.0344;

  digitalWrite(trig8, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig8, LOW);
  tempo = pulseIn(echo8, HIGH);
  distancia8 = tempo / 2 * 0.0344;

  if (distancia1 <= 5) {
    sensor1 = 1;
    servomotor.write(90);
  } else {
    sensor1 = 0;
    servomotor.write(0);
  }
  if (distancia2 <= 5) {
    sensor2 = 1;
  } else {
    sensor2 = 0;
  }
  if (distancia3 <= 5) {
    sensor3 = 1;
  } else {
    sensor3 = 0;
  }

  if (distancia4 <= 5) {
    sensor4 = 1;
  } else {
    sensor4 = 0;
  }

  if (distancia5 <= 5) {
    sensor5 = 1;
  } else {
    sensor5 = 0;
  }
  if (distancia6 <= 5) {
    sensor6 = 1;
  } else {
    sensor6 = 0;
  }
  if (distancia7 <= 5) {
    sensor7 = 1;
  } else {
    sensor7 = 0;
  }
  if (distancia8 <= 5) {
    sensor8 = 1;
    servomotor2.write(90);
  } else {
    sensor8 = 0;
    servomotor2.write(0);
  }
  digitalWrite(led1, sensor2);
  digitalWrite(led2, sensor3);
  digitalWrite(led3, sensor4);
  digitalWrite(led4, sensor5);
  digitalWrite(led5, sensor6);
  digitalWrite(led6, sensor7);


  if (sensor2 == 0) {
    vaga = 1;
  } else if (sensor3 == 0) {
    vaga = 2;
  } else if (sensor4 == 0) {
    vaga = 3;
  } else if (sensor5 == 0) {
    vaga = 4;
  } else {
    vaga = 0;
  }
  if (vaga == 0) {
    Serial.println("TODAS VAGAS OCUPADAS");
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.println("Todas as vagas "),
      lcd.setCursor(4, 1);
    lcd.print("Ocupadas");
    Serial.println("PROJETO DE INOVAÇÃO - 2024");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VA PARA VAGA ");
    lcd.setCursor(13, 0);
    lcd.print(vaga);
  }
}