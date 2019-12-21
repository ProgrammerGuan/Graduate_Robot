#include "IMovingData.h"

MovingData_RF::MovingData_RF(){
    alpha[0] = 0;
    alpha[1] = fi;
    alpha[2] = theda;
    alpha[3] = fi;
    for(int i=0 ; i<4 ; i++){
        beta[i] = b[i];
        gama[i] = r[i];
    }
    LegFlag = 3;
}

MovingData_RB::MovingData_RB(){
    alpha[0] = 0;
    alpha[1] = -fi;
    alpha[2] = -theda;
    alpha[3] = -fi;
    for(int i=0 ; i<4 ; i++){
        beta[i] = b[i];
        gama[i] = r[i];
    }
    LegFlag = 4;
}

MovingData_LF::MovingData_LF(){
    alpha[0] = 180;
    alpha[1] = 180-fi;
    alpha[2] = 180-theda;
    alpha[3] = 180-fi;
    for(int i=0 ; i<4 ; i++){
        if(b[i]<0) beta[i] = -180-b[i];
        else beta[i] =180-b[i];
        gama[i] =-r[i];
    }
    LegFlag = 1;
}

MovingData_LB::MovingData_LB(){
    alpha[0] = -180;
    alpha[1] = -180 + fi;
    alpha[2] = -180 + theda;
    alpha[3] = -180 + fi;
    for(int i=0 ; i<4 ; i++){
        if(b[i]<0) beta[i] = -180-b[i];
        else beta[i] =180-b[i];
        gama[i] =-r[i];
    }
    LegFlag = 2;
}