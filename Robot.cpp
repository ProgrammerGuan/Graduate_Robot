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
    Walk_LegUpDown(3); //RF
    Walk_MoveBody(1);
    Walk_LegUpDown(2); //LB
    Walk_LegUpDown(1); //LF
    Walk_MoveBody(2);
    Walk_LegUpDown(4); //RB
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

void Robot::Walk_LegUpDown(int legcnt)
{
  switch (legcnt)
  {
  case 1:
    LF->Walk_Up();
    delay(move_time);
    LF->Walk_Down();
    delay(move_time);
    break;
  case 2:
    LB->Walk_Up();
    delay(move_time);
    LB->Walk_Down();
    delay(move_time);
    break;
  case 3:
    RF->Walk_Up();
    delay(move_time);
    RF->Walk_Down();
    delay(move_time);
    break;
  case 4:
    RB->Walk_Up();
    delay(move_time);
    RB->Walk_Down();
    delay(move_time);
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
  delay(move_time);
}

void Robot::TurnRight(int cnt)
{
  for (int i = 0; i < cnt; i++)
  {
    // RB->TurnRight_Up();   //RB up
    // TurnRightMoveBody(1); //movebody(1)
    // RB->TurnRight_Down(); //RB down
    // LB->TurnRight_Up();   //LB up
    // TurnRightMoveBody(2); //movebody(2)
    // LB->TurnRight_Down(); //LB down
    // LF->TurnRight_Up();   //LF up
    // TurnRightMoveBody(3); //movebody(3)
    // LF->TurnRight_Down(); //LF down
    // RF->TurnRight_Up();   //RF up
    // TurnRightMoveBody(4); //movebody(4)
    // RF->TurnRight_Down(); //RF down
  }
}

void Robot::TurnRightMoveBody(int flag)
{
}

void Robot::GetRBM3(Servo *s)
{
  RBM3 = s;
  RB->GetRBM3(s);
}
