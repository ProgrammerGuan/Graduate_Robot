class IMovingData
{
protected:
    float theda = 45, fi = 26;
    float b[4] = {40, 39, 35, 60};
    float r[4] = {-40, -34, -17, 0};
    // turning t0 t1 t1zUp xdzUP
    float turning_a[4] = {37, 11, 37, 0};
    float turning_b[4] = {31, 29, 31, 30};
    float turning_r[4] = {-18, -12, 30, 30};

public:
    float alpha[4] = {0, 0, 0, 0};
    float beta[4] = {0, 0, 0, 0};
    float gama[4] = {0, 0, 0, 0};
    float turning_alpha[4] = {0, 0, 0, 0};
    float turning_beta[4] = {0, 0, 0, 0};
    float turning_gama[4] = {0, 0, 0, 0};

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
