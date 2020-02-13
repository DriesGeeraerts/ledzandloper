#include "SevSeg.h"
  int sensorvalue = 0;
  int SegA = 0;
  int SegB = 1;
  int SegC = 2;
  int SegD = 3;
  int SegE = 4;
  int SegF = 5;
  int SegG = 6;
  int DisH = 7;
  int DisT = 8;
  int DisE = 9;
  int Temp = A4;
  int BO1 = 10;
  int BO2 = 11;
  int BO3 = 12;
  int Drup1 = 13;
  int Drup2 = A0;
  int Drup3 = A1;
  int Drup4 = A2;
  int Drup5 = A3;
  int number = 0;
  int hundreds = 0;
  int tens = 0;
  int ones = 0;
  int tijd = 0;
  int vorigverval = 0;
  int verval = 0;

void setup() {
  pinMode (SegA, OUTPUT);
  pinMode (SegB, OUTPUT);
  pinMode (SegC, OUTPUT);
  pinMode (SegD, OUTPUT);
  pinMode (SegE, OUTPUT);
  pinMode (SegF, OUTPUT);
  pinMode (SegG, OUTPUT);
  pinMode (DisH, OUTPUT);
  pinMode (DisT, OUTPUT);
  pinMode (DisE, OUTPUT);
  pinMode (A0, OUTPUT);
  pinMode (A1, OUTPUT);
  pinMode (A2, OUTPUT);
  pinMode (A3, OUTPUT);
  pinMode (A4, INPUT);
  pinMode (A5, INPUT);  
}

void drup(){
    verval = millis();
    vorigverval = verval - vorigverval;
    digitalWrite (Drup1, HIGH);


    if (250 <vorigverval  ){
    digitalWrite (Drup1, LOW);
    digitalWrite (Drup2, HIGH);
    }
    else if(500 <  vorigverval < 750){
    digitalWrite (Drup2, LOW);
    digitalWrite (Drup3, HIGH);
    }
    else if (750 < vorigverval <1000){
    digitalWrite (Drup3, LOW);
    digitalWrite (Drup4, HIGH);
    }
    else if (1000 < vorigverval < 1250){
    digitalWrite (Drup4, LOW);
    digitalWrite (Drup5, HIGH);
    }else if (1250 < vorigverval){
    digitalWrite (Drup5, LOW);

    }
}

void zandloper(){
  digitalWrite (BO1,HIGH);
  digitalWrite (BO2,HIGH);
  digitalWrite (BO3,HIGH);
  tijd = millis();
  if (tijd > 300000){
  digitalWrite (BO1, LOW);
  }
  if (tijd > 600000){
  digitalWrite (BO2, LOW);
  }
  if (tijd > 900000){
  digitalWrite (BO3, LOW);
  }
}
void loop() {

  sensorvalue = analogRead(Temp);
  number = sensorvalue;
  hundreds = number/100;
  number = number-hundreds*100;

  tens = number/10;
  ones = number-tens*10;

  SevSeg.setNumber (Hundreds,1); /*krijg dees op pin DisH*/
  SevSeg.setNumber (tens,1); /*krijg dees op pin DisT*/
  SevSeg.setNumber (ones,1); /*krijg dees op pin DisE */
  
}
