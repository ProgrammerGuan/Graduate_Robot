#include "Robot.h"
#include <Servo.h>
int motorPins[12];
Robot m_Robot;

Servo s;
void setup()
{
  for (int i = 0; i < 12; i++)
  {
    motorPins[i] = i + 2;
  }
  m_Robot.Initial(motorPins);
  s.attach(13);
  m_Robot.GetRBM3(&s);
  delay(3000);
  m_Robot.Throw();
  delay(2000);
  m_Robot.OriType();
  delay(3000);
  m_Robot.Walk_Back(14);
  m_Robot.TurnRight(3);
  m_Robot.Walk_Back(7);
  m_Robot.TurnRight(6);
  m_Robot.Walk_Back(7);
  m_Robot.TurnRight(3);
  m_Robot.Walk_Back(14);
}

void loop()
{
}
