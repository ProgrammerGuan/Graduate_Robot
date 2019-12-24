#include "Leg.h"

class Robot
{
public:
    Leg *RF, *RB, *LF, *LB;
    Servo *RBM3;
    Robot();
    void Initial(int[]);
    void RobotTest();
    void OriType();
    void Walk(int);
    void Walk_MoveBody(int);
    void Walk_LegUpDown(int);
    void GetRBM3(Servo *);
};
