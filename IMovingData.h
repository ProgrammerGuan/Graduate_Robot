class IMovingData
{
protected:
    float theda = 25, fi = 13;
    float b[4] = {2, 2, -1, 17};
    float r[4] = {10, 12, 20, -2};

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