#include <Servo.h>

class Motor{
public:
  Servo m_servo;
  char m_name;
  Motor(char);
  void Initial(int);
  void RotateTo(int);
};
