#include "Robot.h"

Robot::Robot(){
  LF = new Leg("LF");
  LB = new Leg("LB");
  RF = new Leg("RF");
  RB = new Leg("RB");
}

void Robot::Initial(int pins[12]){
    LF->Initial(pins[0],pins[1],pins[2]);
    LB->Initial(pins[3],pins[4],pins[5]);
    RF->Initial(pins[6],pins[7],pins[8]);
    RB->Initial(pins[9],pins[10],pins[11]);
}

void Robot::RobotTest(){
    LF->LegTest();
}