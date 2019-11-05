#include "Robot.h"

int motorPins[12];
Robot m_Robot;
void setup() {
  for(int i=0; i<12 ; i++)
    motorPins[i] = i+2;
  m_Robot.Initial(motorPins);
}

void loop() {
  m_Robot.RobotTest();
}
