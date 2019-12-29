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

void Robot::RobotTest2()
{
  RB->LegTest2();
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
    Walk_LegUpDown(3, true); //RF
    Walk_MoveBody(1, true);
    Walk_LegUpDown(2, true); //LB
    Walk_LegUpDown(1, true); //LF
    Walk_MoveBody(2, true);
    Walk_LegUpDown(4, true); //RB
  }
}

void Robot::Walk_Back(int cnt)
{
  for (int i = 0; i < cnt; i++)
  {
    Walk_LegUpDown(4, false); //RB
    Walk_MoveBody(1, false);
    Walk_LegUpDown(1, false); //LF
    Walk_LegUpDown(2, false); //LB
    Walk_MoveBody(2, false);
    Walk_LegUpDown(3, false); //RF
  }
}

void Robot::WalkLegTest(int cnt)
{
  switch (cnt)
  {
  case 1:
    LF->Walk_Up();
    break;
  case 2:
    LB->Walk_Up();
    break;
  case 3:
    RF->Walk_Up();
    break;
  case 4:
    RB->Walk_Up();
    break;
  default:
    break;
  }
}

void Robot::Walk_LegUpDown(int legcnt, bool forward)
{
  switch (legcnt)
  {
  case 1:
    LF->Walk_Up();
    delay(move_time);
    LF->Walk_Down(forward);
    delay(move_time);
    break;
  case 2:
    LB->Walk_Up();
    delay(move_time);
    LB->Walk_Down(forward);
    delay(move_time);
    break;
  case 3:
    RF->Walk_Up();
    delay(move_time);
    RF->Walk_Down(forward);
    delay(move_time);
    break;
  case 4:
    RB->Walk_Up();
    delay(move_time);
    RB->Walk_Down(forward);
    delay(move_time);
    break;
  default:
    break;
  }
}

void Robot::Walk_MoveBody(int s, bool forward)
{
  LF->Walk_MoveBody(s, forward);
  LB->Walk_MoveBody(s, forward);
  RF->Walk_MoveBody(s, forward);
  RB->Walk_MoveBody(s, forward);
  delay(move_time);
}

void Robot::TurnRight(int cnt)
{
  for (int i = 0; i < cnt; i++)
  {
    LF->TurnRight_Up();
    LB->TurnRight_Up();
    delay(move_time);
    RF->TurnRight_MoveBody(1);
    RB->TurnRight_MoveBody(1);
    delay(move_time);
    RF->TurnRight_Up();
    RB->TurnRight_Up();
    delay(move_time);
    RF->TurnRight_Down();
    RB->TurnRight_Down();
    delay(move_time);
    RF->TurnRight_MoveBody(2);
    RB->TurnRight_MoveBody(2);
  }
  LF->TurnRight_Down();
  LB->TurnRight_Down();
  delay(move_time);
}

void Robot::TurnRightMoveBody(int flag)
{
}

void Robot::GetRBM3(Servo *s)
{
  RBM3 = s;
  RB->GetRBM3(s);
}
