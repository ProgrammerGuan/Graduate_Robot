#include <Servo.h>

class Motor
{
private:
  int now_degree, goal_degree;

public:
  Servo m_servo;
  Servo *test_servo;
  char m_name;
  Motor(char);
  void Initial(int, int);
  void Initial(Servo *s, int);
  void RotateTo(int);
  void TestServoRotateTo(int);
};
