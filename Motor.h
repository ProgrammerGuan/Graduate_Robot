#include <Servo.h>

class Motor{
private:
  int now_degree, goal_degree;
public:
  Servo m_servo;
  char m_name;
  Motor(char);
  void Initial(int,int);
  void RotateTo(int);
};
