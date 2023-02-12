#include "Rad.h"
#include "Rueda.h"
#include "Auto.h"

int letra = 0;
//Rad* radRechts = new Rad(0x88, 23680, A0);
//Rad* radLinks = new Rad(0x8A, 24350, A1);
Auto* car = new Auto();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  TCCR1A = 0b10101010;
  TCCR1B = 0b00011001;
  ICR1 = 320000;

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    letra = Serial.read();
        
    switch(letra){
      case 102:
      car->moveForward(40,400);
      /*
      while(1){
        
        radRechts->move(400, true);
        radLinks->move(400, false);
        letra = Serial.read();
        if (letra == 115){
          radRechts->stop();
          radLinks->stop();
          break;
        } 
      }
      */
    }
  }
}
