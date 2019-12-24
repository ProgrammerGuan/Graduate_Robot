#include "Robot.h"
#include <Arduino.h>

Robot::Robot()
{
  Serial.begin(9600);
  LF = new Leg("LF");
  LB = new Leg("LB");
  RF = new Leg("RF");
  RB = new Leg("RB");
}

void Robot::Initial(int pins[12])
{
  LF->Initial(pins[0], pins[1], pins[2]);
  LB->Initial(pins[3], pins[4], pins[5]);
  RF->Initial(pins[6], pins[7], pins[8]);
  RB->Initial(pins[9], pins[10], pins[11]);
}

void Robot::RobotTest()
{
  LF->LegTest();
  LB->LegTest();
  RF->LegTest();
  RB->LegTest();
}

void Robot::OriType()
{
  LF->OriType();
  LB->OriType();
  RF->OriType();
  RB->OriType();
}

void Robot::Walk(int cnt)
{
  for (int i = 0; i < cnt; i++)
  {
    Walk_LegUpDown(3); //RF
    Walk_MoveBody(1);
    Walk_LegUpDown(2); //LB
    Walk_LegUpDown(1); //LF
    Walk_MoveBody(2);
    Walk_LegUpDown(4); //RB
  }
}

void Robot::Walk_LegUpDown(int legcnt)
{
  switch (legcnt)
  {
  case 1:
    LF->Walk_Up();
    delay(1000);
    LF->Walk_Down();
    delay(1000);
    break;
  case 2:
    LB->Walk_Up();
    delay(1000);
    LB->Walk_Down();
    delay(1000);
    break;
  case 3:
    RF->Walk_Up();
    delay(1000);
    RF->Walk_Down();
    delay(1000);
    break;
  case 4:
    RB->Walk_Up();
    delay(1000);
    RB->Walk_Down();
    delay(1000);
    break;
  default:
    break;
  }
}

void Robot::Walk_MoveBody(int s)
{
  LF->Walk_MoveBody(s);
  LB->Walk_MoveBody(s);
  RF->Walk_MoveBody(s);
  RB->Walk_MoveBody(s);
  delay(1000);
}

void Robot::GetRBM3(Servo *s)
{
  RBM3 = s;
}