const byte encoder0pinA_z = 2;//A pin -> the interrupt pin 0
const byte encoder0pinA_y = 3;//A pin -> the interrupt pin 0
const byte encoder0pinB_z = 44;//B pin -> the digital pin 4
const byte encoder0pinB_y = 42;//B pin -> the digital pin 4
boolean Direction_z;//the rotation direction 
boolean Direction_y;//the rotation direction 
byte encoder0PinALast_z;
byte encoder0PinALast_y;
int duration_z;//the number of the pulses
int duration_y;//the number of the pulses
int duration1_z;//the number of the pulses
int duration1_y;//the number of the pulses
 
void EncoderInit()
{
  Direction_z = true;//default -> Forward  
  Direction_y = true;//default -> Forward  
  pinMode(encoder0pinB_z,INPUT);  
  pinMode(encoder0pinB_y,INPUT);  
  attachInterrupt(0, wheelSpeed_z, CHANGE);
  attachInterrupt(1, wheelSpeed_y, CHANGE);
}

void wheelSpeed_z()
{
  int Lstate = digitalRead(encoder0pinA_z);
  if((encoder0PinALast_z == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encoder0pinB_z);
    if(val == LOW && Direction_z)
    {
      Direction_z = false; //Reverse
    }
    else if(val == HIGH && !Direction_z)
    {
      Direction_z = true;  //Forward
    }
  }
  encoder0PinALast_z = Lstate;
 
  if(!Direction_z)  duration_z++;
  else  duration_z--;
}

void wheelSpeed_y()
{
  int Lstate = digitalRead(encoder0pinA_y);
  if((encoder0PinALast_z == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encoder0pinB_y);
    if(val == LOW && Direction_y)
    {
      Direction_y = false; //Reverse
    }
    else if(val == HIGH && !Direction_y)
    {
      Direction_y = true;  //Forward
    }
  }
  encoder0PinALast_y = Lstate;
 
  if(!Direction_y)  duration_y--;
  else  duration_y++;
}

void speedTest()
{
  duration1_z = duration_z;
  duration_z = 0;
  duration1_y = duration_y;
  duration_y = 0;
//  Serial.print("zuo");
//  Serial.println(duration1_z);
//  Serial.print("you");
//  Serial.println(duration1_y);
  value_y = value_y + a * (y - duration1_y);
  value_z = value_z + b * (z - duration1_z);
  if (value_y > pwm_max)
    value_y = pwm_max;
  if (value_z > pwm_max)
    value_z =pwm_max;
  if (value_y  < pwm_min)
    value_y = pwm_min;
  if (value_z < pwm_min)
    value_z =pwm_min;
  if (duration1_y >= -5)
    t_back = 1;
  else 
   t_back = 0;
   if(duration1_z < 12)
    flag_z = 0;
   else
    flag_z  = 1;
   if(duration1_y < 12)
    flag_y  = 0;
   else
    flag_y = 1;
  analogWrite(ENA, value_y);
  analogWrite(ENB, value_z );
}

