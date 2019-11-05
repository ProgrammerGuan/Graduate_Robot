#include "Motor.h"

Motor::Motor(char Name){
  m_name = Name;
}

void Motor::RotateTo(int degree){
  if(m_name == 'f')
    m_servo.write(90+degree);
  else
    m_servo.write(90-degree);
}

void Motor::Initial(int pinNum){
  m_servo.attach(pinNum);
  m_servo.write(90);
}
