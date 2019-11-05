#include "Leg.h"
#include <Arduino.h>

Leg::Leg(char Name[2]){
    for(int i=0 ; i<2 ; i++)
        m_name[i] = Name[i];
}

void Leg::Initial(int pin1, int pin2, int pin3){
  m1 = new Motor('f');
  m2 = new Motor('s');
  m3 = new Motor('t');
  m1->Initial(pin1);
  m2->Initial(pin2);
  m3->Initial(pin3);
}

void Leg::LegTest(){
  m1->RotateTo(0);
  delay(1000);
  m1->RotateTo(90);
  delay(1000);
  m2->RotateTo(0);
  delay(1000);
  m2->RotateTo(90);
  delay(1000);
  m3->RotateTo(0);
  delay(1000);
  m3->RotateTo(90);
  delay(1000);
}
