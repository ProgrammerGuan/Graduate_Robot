#include "Leg.h"
#include <Arduino.h>

Leg::Leg(char Name[2])
{
  for (int i = 0; i < 2; i++)
    m_name[i] = Name[i];
  if (m_name[0] == 'L' && m_name[1] == 'F')
    f = 1;
  else if (m_name[0] == 'L' && m_name[1] == 'B')
    f = 2;
  else if (m_name[0] == 'R' && m_name[1] == 'F')
    f = 3;
  else if (m_name[0] == 'R' && m_name[1] == 'B')
    f = 4;
  switch (f)
  {
  case 1:
    moving_data = new MovingData_LF();
    Serial.println("LF");
    break;
  case 2:
    moving_data = new MovingData_LB();
    Serial.println("LB");
    break;
  case 3:
    moving_data = new MovingData_RF();
    Serial.println("RF");
    break;
  case 4:
    moving_data = new MovingData_RB();
    Serial.println("RB");
  default:
    break;
  }
  Serial.println(moving_data->LegFlag);
}

void Leg::Initial(int pin1, int pin2, int pin3)
{
  m1 = new Motor('f');
  m2 = new Motor('s');
  m3 = new Motor('t');
  if (m_name[0] == 'L')
  {
    m1->Initial(pin1, 180);
    m2->Initial(pin2, 180);
  }
  else
  {
    m1->Initial(pin1, 0);
    m2->Initial(pin2, 0);
  }
  if (f != 4)
    m3->Initial(pin3, 0);
}

void Leg::GetRBM3(Servo *s)
{
  m3 = new Motor("t");
  m3->Initial(s, 0);
  getRBM3_Servo = true;
}

void Leg::WalkMotorRotate(int t)
{
  m1->RotateTo(moving_data->alpha[t]);
  m2->RotateTo(moving_data->beta[t]);
  if (f != 4)
    m3->RotateTo(moving_data->gama[t]);
  else
    m3->TestServoRotateTo(moving_data->gama[t]);
}

void Leg::OriType()
{
  int t = 0;
  switch (f)
  {
  case 1:
    t = 1;
    break;
  case 2:
    t = 1;
    break;
  case 3:
    t = 0;
    break;
  case 4:
    t = 0;
    break;
  default:
    break;
  }
  WalkMotorRotate(t);
}

void Leg::Walk_Up()
{
  int t = 3;
  WalkMotorRotate(t);
}

void Leg::Walk_Down(bool forward)
{
  int t = 0;

  if (forward)
  {
    switch (f)
    {
    case 1:
      t = 2;
      break;
    case 2:
      t = 0;
      break;
    case 3:
      t = 2;
      break;
    case 4:
      t = 0;
      break;
    default:
      break;
    }
  }
  else
  {
    switch (f)
    {
    case 1:
      t = 0;
      break;
    case 2:
      t = 2;
      break;
    case 3:
      t = 0;
      break;
    case 4:
      t = 2;
      break;
    default:
      break;
    }
  }

  WalkMotorRotate(t);
}

void Leg::Walk_MoveBody(int type, bool forward)
{
  int t = 0;

  if (forward)
  {
    if (type == 1)
    {
      switch (f)
      {
      case 1:
        t = 0;
        break;
      case 2:
        t = 2;
        break;
      case 3:
        t = 1;
        break;
      case 4:
        t = 1;
        break;
      default:
        break;
      }
    }
    else if (type == 2)
    {
      switch (f)
      {
      case 1:
        t = 1;
        break;
      case 2:
        t = 1;
        break;
      case 3:
        t = 0;
        break;
      case 4:
        t = 2;
        break;
      default:
        break;
      }
    }
  }
  else
  {
    if (type == 1)
    {
      switch (f)
      {
      case 1:
        t = 2;
        break;
      case 2:
        t = 0;
        break;
      case 3:
        t = 1;
        break;
      case 4:
        t = 1;
        break;
      default:
        break;
      }
    }
    else if (type == 2)
    {
      switch (f)
      {
      case 1:
        t = 1;
        break;
      case 2:
        t = 1;
        break;
      case 3:
        t = 2;
        break;
      case 4:
        t = 0;
        break;
      default:
        break;
      }
    }
  }
  WalkMotorRotate(t);
}

void Leg::TurnRight_Up()
{
  if (f == 1 || f == 2)
    m2->RotateTo(100);
  else
  {
    m2->RotateTo(80);
  }
}

void Leg::TurnRight_Down()
{
  if (f == 1 || f == 2)
    m2->RotateTo(moving_data->beta[1]);
  else
  {
    m1->RotateTo(-30);
    m2->RotateTo(moving_data->beta[0]);
  }
}

void Leg::TurnRight_MoveBody(int type)
{
  if (type == 1)
    m1->RotateTo(30);
  else if (type == 2)
    m1->RotateTo(moving_data->alpha[0]);
}

void Leg::LegTest()
{
  m1->RotateTo(30);
  delay(1000);
  m1->RotateTo(0);
  delay(1000);
  m2->RotateTo(30);
  delay(1000);
  m2->RotateTo(0);
  delay(1000);
  if (f != 4)
    m3->RotateTo(30);
  else
    m3->TestServoRotateTo(30);
  delay(1000);
  if (f != 4)
    m3->RotateTo(0);
  else
    m3->TestServoRotateTo(0);
  delay(1000);
}

void Leg::LegTest2()
{
  m1->RotateTo(30);
  m2->RotateTo(30);
  m3->TestServoRotateTo(30);
  delay(1000);
  m1->RotateTo(0);
  m2->RotateTo(0);
  m3->TestServoRotateTo(0);
  delay(1000);
}
