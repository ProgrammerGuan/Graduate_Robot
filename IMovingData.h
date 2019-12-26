class IMovingData
{
protected:
    float theda = 23, fi = 13;
    float b[4] = {-30, -30, -33, -11};
    float r[4] = {41, 44, 51, 20};

public:
    float alpha[4] = {0, 0, 0, 0};
    float beta[4] = {0, 0, 0, 0};
    float gama[4] = {0, 0, 0, 0};
    int LegFlag;
};

class MovingData_RF : public IMovingData
{
public:
    MovingData_RF();
};

class MovingData_RB : public IMovingData
{
public:
    MovingData_RB();
};

class MovingData_LF : public IMovingData
{
public:
    MovingData_LF();
};

class MovingData_LB : public IMovingData
{
public:
    MovingData_LB();
};