#include "Motor.h"
#include "IMovingData.h"
class Leg
{
private:
    float L1 = 37.55, L2 = 70, L3 = 107.5;
    int f = 0;

public:
    IMovingData *moving_data;

    Motor *m1, *m2, *m3;
    char m_name[2];
    bool getRBM3_Servo = false;
    Leg(char[]);
    void Initial(int, int, int);
    void LegTest();
    void LegTest2();
    void WalkMotorRotate(int);
    void OriType();
    void Walk_Up();
    void Walk_Down();
    void Walk_MoveBody(int);
    void TurnRight_Up(int);
    void TurnRight_Down(int);
    void TurnRight_MoveBody(int);
    void GetRBM3(Servo *);
};
