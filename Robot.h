#include "Leg.h"

class Robot
{
public:
    Leg *RF, *RB, *LF, *LB;
    Servo *RBM3;
    int move_time = 300;
    int motorPin = 1;
    Robot();
    void Initial(int[]);
    void RobotTest();
    void RobotTest2();
    void OriType();
    void Walk(int);
    void Walk_Back(int);
    void WalkLegTest(int);
    void Walk_MoveBody(int, bool);
    void Walk_LegUpDown(int, bool);
    void TurnRight(int);
    void TurnLeft(int);
    void Throw();
    void GetRBM3(Servo *);
};
