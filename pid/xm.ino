#include<Servo.h>

Servo myservo_x;

void init_x()
{
  myservo_x.attach(12);

  myservo_x.write(50);
}

void shouhui()
{
  myservo_x.write(50);
}

void zheguang()
{
  myservo_x.write(150);
}

