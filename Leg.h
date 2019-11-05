#include "Motor.h"

class Leg{
public:
    Motor *m1,*m2,*m3;
    char m_name[2];
    Leg(char[]);
    void Initial(int,int,int);
    void LegTest();
};
