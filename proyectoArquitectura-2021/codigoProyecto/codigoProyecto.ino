#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

    const int ledVerde = 11; //verde
    const int ledRojo = 12; //rojo
    const int buzzer = 10; //buzzer
    const int tmp = A1; //lectura sensor temperatura
    const int push = A2; //pn push
  const int pir = 8;
    int lecturaPush = 0; //lectura del push
  float temperatura = 0;
    int valTemp, valPir;
  int duracion=70;
  int retardo=1000;
  int tonoTempAlto = 600;
  int tonoTempBajo = 800;
  
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(ledRojo,OUTPUT); 
  pinMode(ledVerde,OUTPUT);
  pinMode(buzzer,INPUT);
  pinMode(tmp,INPUT);
  pinMode(pir, INPUT);
}


void loop(){
  lecturaPush = digitalRead(push);
  valPir = digitalRead(pir);
  valTemp = analogRead(tmp);
 
  temperatura = map(valTemp,0,1023,-50,450);


  if(lecturaPush==HIGH){
    if(valPir == HIGH){
      if(temperatura>37){
        digitalWrite(ledRojo,HIGH);
        digitalWrite(ledVerde,LOW);
        tone(buzzer,tonoTempAlto,duracion);
        delay(retardo);
      }else{
        digitalWrite(ledRojo, LOW);
        digitalWrite(ledVerde, HIGH);
        tone(buzzer,tonoTempBajo,duracion);
        delay(retardo);
        }
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Temperatura:");
      lcd.setCursor(0,1);
      lcd.print(temperatura);
      lcd.print(" °C");
      delay(500);
    }
      
  }else if(lecturaPush==LOW){
      lcd.clear();
      digitalWrite(ledRojo, LOW);
      digitalWrite(ledVerde, LOW);
  }
 


}
