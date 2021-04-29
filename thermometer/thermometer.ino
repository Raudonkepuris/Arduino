#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS A2

OneWire ow(ONE_WIRE_BUS);
DallasTemperature sen(&ow);

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;
int D5 = 13;

const unsigned long interv = 20000;
unsigned long prevT = 0;

int num = 0;
int num1 = 0;
int num2 = 0;
int num3 = 0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
  sen.begin();
  
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
}

void loop() {

  unsigned long crT = millis();

  if(crT - prevT >= interv){
    num = getTemperature();
    num1 = num / 100;
    num2 = num % 100 / 10;
    num3 = num % 10;
    prevT = crT;
  }


  digitalWrite(D1, HIGH);  
  digitalWrite(D2, LOW);  
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  switch(num1){
    case 0:
        digitalWrite(pinA, LOW);   
         digitalWrite(pinB, LOW);   
         digitalWrite(pinC, LOW);   
         digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
         digitalWrite(pinF, LOW);   
         digitalWrite(pinG, HIGH);
         break;
    case 1: 
          digitalWrite(pinA, HIGH);   
           digitalWrite(pinB, LOW);   
         digitalWrite(pinC, LOW);   
        digitalWrite(pinD, HIGH);   
          digitalWrite(pinE, HIGH);   
         digitalWrite(pinF, HIGH);   
         digitalWrite(pinG, HIGH); 
      break;
    case 2: 
      digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW); 
  break;
  case 3:
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
  break;
  case 4:
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  break;               // wait for a second
  case 5:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
break;// wait for a second
  case 6:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  break;               // wait for a second
  case 7:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
  break;               // wait for a second
  case 8:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  break;               // wait for a second
  case 9:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
  break;
  default:
  break;
    }
    delay(1);

  digitalWrite(D1, LOW);  
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
digitalWrite(D4, LOW);
digitalWrite(D5, LOW);

  switch(num2){
    case 0:
        digitalWrite(pinA, LOW);   
         digitalWrite(pinB, LOW);   
         digitalWrite(pinC, LOW);   
         digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
         digitalWrite(pinF, LOW);   
         digitalWrite(pinG, HIGH);
         break;
    case 1: 
          digitalWrite(pinA, HIGH);   
           digitalWrite(pinB, LOW);   
         digitalWrite(pinC, LOW);   
        digitalWrite(pinD, HIGH);   
          digitalWrite(pinE, HIGH);   
         digitalWrite(pinF, HIGH);   
         digitalWrite(pinG, HIGH); 
      break;
    case 2: 
      digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW); 
  break;
  case 3:
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
  break;
  case 4:
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  break;               // wait for a second
  case 5:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
break;// wait for a second
  case 6:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  break;               // wait for a second
  case 7:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
  break;               // wait for a second
  case 8:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  break;               // wait for a second
  case 9:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
  break;
  default:
  break;
    }
    delay(1);

   digitalWrite(D1, LOW);  
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
   digitalWrite(D4, LOW);
   digitalWrite(D5, LOW);

   digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
  delay(1);

   digitalWrite(D1, LOW);  
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
   digitalWrite(D4, HIGH);
   digitalWrite(D5, LOW);

    switch(num3){
    case 0:
        digitalWrite(pinA, LOW);   
         digitalWrite(pinB, LOW);   
         digitalWrite(pinC, LOW);   
         digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
         digitalWrite(pinF, LOW);   
         digitalWrite(pinG, HIGH);
         break;
    case 1: 
          digitalWrite(pinA, HIGH);   
           digitalWrite(pinB, LOW);   
         digitalWrite(pinC, LOW);   
        digitalWrite(pinD, HIGH);   
          digitalWrite(pinE, HIGH);   
         digitalWrite(pinF, HIGH);   
         digitalWrite(pinG, HIGH); 
      break;
    case 2: 
      digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW); 
  break;
  case 3:
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
  break;
  case 4:
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  break;               // wait for a second
  case 5:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
break;// wait for a second
  case 6:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  break;               // wait for a second
  case 7:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
  break;               // wait for a second
  case 8:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  break;               // wait for a second
  case 9:
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
  break;
  default:
  break;
    }
    delay(1);

       digitalWrite(D1, LOW);  
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
   digitalWrite(D4, LOW);
   digitalWrite(D5, HIGH);

     digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);

  delay(1);
}

int getTemperature(){
  float temperature = 0;
  sen.requestTemperatures();
  temperature = sen.getTempCByIndex(0);
  temperature = temperature * 10;
  return temperature;
  }
