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
  delay(2000);

    m_Robot.OriType();
    delay(1000);
    m_Robot.Walk(3);
}

void loop()
{
//   m_Robot.RobotTest();
}
