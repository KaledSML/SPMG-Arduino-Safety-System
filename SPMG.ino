#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensor_minimo = 85;      
const int sensor_maximo = 382; 

int temperatura = 0;
int PIR = 3;
int LED = 8;

void setup() {
  
  pinMode(3, OUTPUT); //luz verde movimiento
  pinMode(2, OUTPUT); //luz amarilla movimiento
  pinMode(1, OUTPUT); //luz roja movimiento 
  pinMode (13, OUTPUT); //buzzer
  lcd.begin(16, 2); //lcd
  pinMode(4, OUTPUT);//luz verde temperatura
  pinMode(5, OUTPUT);//luz amarillo temperatura
  pinMode(6, OUTPUT);//luz rojo temperatura
  Serial.begin(9600);
}

void loop() {
  //sensor de movimiento
  int sensor = analogRead(A3); 
  int rango = map(sensor, sensor_minimo, sensor_maximo, 0, 3);
  switch (rango) {   
    case 0:
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite (13,LOW);
      delay(2000);
      lcd.setCursor(0,0);
      lcd.println("SENSOR MOVIMIENTO");
      lcd.setCursor(0,2);
      lcd.print("NORMAL");      
      break;
    
    case 1:
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite (13,LOW);
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.println("SENSOR DE MOVIMIENTO");
      lcd.setCursor(0,2);
      lcd.print("INTERMEDIO");
      break;    
    
    case 2:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite (13,HIGH);
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.println("SENSOR DE MOVIMIENTO");
      lcd.setCursor(0,2);
      lcd.print("CRITICO");
      break;
    
    lcd.setCursor(0, 1);
    lcd.print(100);
  }
  
  //temperatura
  temperatura = (-40 + 0.488155 * (analogRead(A0) - 20));
  Serial.println(temperatura);
                 
    if (temperatura <= 40) {
    digitalWrite(1, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);      
    digitalWrite (13,HIGH);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("T° NORMAL");
    lcd.setCursor(0,2);
    lcd.print(temperatura);
    noTone(7);
  }
  
  if (temperatura >= 40) {
    digitalWrite(1, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    
    digitalWrite (13,HIGH);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("T° CRITICA");
    lcd.setCursor(0,2);
    lcd.print(temperatura); 
  }
  
  delay(100);
}