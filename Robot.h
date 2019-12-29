#include "Leg.h"

class Robot
{
public:
    Leg *RF, *RB, *LF, *LB;
    Servo *RBM3;
    int move_time = 2000;
    Robot();
    void Initial(int[]);
    void RobotTest();
    void RobotTest2();
    void OriType();
    void Walk(int);
    void Walk_Back(int);
    void WalkLegTest(int);
    void Walk_MoveBody(int);
    void Walk_LegUpDown(int);
    void TurnRight(int);
    void TurnRightMoveBody(int);
    void GetRBM3(Servo *);
};
