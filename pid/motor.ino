int IN1 = 52;   // IN1 connected to pin 1
int IN2 = 53;   
int ENA = 6;  
int IN3 = 48;   // IN1 connected to pin 1
int IN4 = 49;   
int ENB = 7;  
//The sample code for driving one way motor encoder

int value  ;   // the duty cycle

int speed_err;
void init_m()
{
  //sets the pin as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //set direction；
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void qianjin()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  pwm_min = 30;
  pwm_max = 180;
  z = 18;
  y = 18;
  a = 2;
  b = 2;
}

void houtui()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  pwm_min = 30;
  pwm_max =180;
//  z = -18;
//  y = -18;
  z = -25;
  y = -25;
  a = -3;
  b = -3;
}

void qianjintingzhi()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  pwm_min = 0;
  pwm_max = 255;
  z = 0;
  y = 0;
  a = -5;
  b = -5;
}

void houtuitingzhi()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  pwm_min = 0;
  pwm_max = 255;
  z = 0;
  y = 0;
  a = 3;
  b = 3;
}

void kuaisuyouzhuan()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  pwm_min = 30;
  pwm_max =150;
  z = -3;
  y = 3;
  a = 2;
  b = -2;
}

void manxingqianjin()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  pwm_min = 0;
  pwm_max = 100;
  z = 2;
  y = 2;
  a = 15;
  b = 15;
}

void xiaozuozhuan()
{
  if(flag_z == 1)
  {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  pwm_min = 0;
  pwm_max =150;
  z = 20;
  y =  50;
  a = 5;
  b = -20;
  }
  if(flag_z == 0)
  {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  pwm_min = 0;
  pwm_max =150;
  z = 12;
  y =  50;
  a = 5;
  b = 20;
  }

}
  
void xiaoyouzhuan()
{  
  if(flag_y == 1)
  {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  pwm_min = 0;
  pwm_max =150;
  z = 50;
  y =  20;
  a = -20;
  b = 5;
  }
  if(flag_y == 0)
  {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  pwm_min = 0;
  pwm_max =150;
  z = 50;
  y = 12;
  a = 20;
  b = 5;
  }
}
  
void manxingzuozhuan()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  pwm_min = 0;
  pwm_max =150;
  z = 0;
  y = 15;
  a = 5;
  b = -20;
}
  
void manxingyouzhuan()
{  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  pwm_min = 0;
  pwm_max =130;
  z = 10;
  y = 0;
  a = -20;
  b = 5;
}
  

