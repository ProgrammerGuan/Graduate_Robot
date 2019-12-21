class IMovingData{
protected: 
    float theda = 24, fi = 13;
    float b[4] = {4, 4, 3, 21};
    float r[4] = {-3,-1,4,-15};
    
public :
    float alpha[4] = {0,0,0,0};
    float beta[4] = {0,0,0,0};
    float gama[4] = {0,0,0,0};
    int LegFlag;
};

class MovingData_RF : public IMovingData{
public: 
    MovingData_RF();
};

class MovingData_RB : public IMovingData{
public: 
    MovingData_RB();
};

class MovingData_LF : public IMovingData{
public: 
    MovingData_LF();
};

class MovingData_LB : public IMovingData{
public: 
    MovingData_LB();
};