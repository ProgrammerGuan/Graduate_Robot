#include "Motor.h"
#include <Arduino.h>
Motor::Motor(char Name)
{
  m_name = Name;
  now_degree = 0;
  goal_degree = 0;
}

void Motor::RotateTo(int degree)
{
  if (m_name == 't')
    m_servo.write(90 - degree);
  else
  {
    if (degree > 90 || degree < -90)
    {
      if (degree > 0)
        degree -= 180;
      else if (degree < 0)
        degree += 180;
    }
    m_servo.write(90 + degree);
  }
}

void Motor::Initial(int pinNum, int OriDegree)
{
  m_servo.attach(pinNum);
  m_servo.write(90);
  now_degree = OriDegree;
}
