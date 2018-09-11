#include <MsTimer2.h>

int var;
int black = 0;
int pwm_max = 0;
int pwm_min = 0;

int black_a = 0;
int value_y, value_z = 0;
int z = 0, y = 0;
float a = 0, b = 0;
int t;
int t_back = 0;

int flag_z = 0,flag_y =0;
void setup()
{
  Serial.begin(115200);
  EncoderInit();//Initialize the module
  MsTimer2::set(10, speedTest);
  MsTimer2::start();
  value_y = 0;
  value_z = 0;
  init_m();
  init_i();
  init_x();
}
  
void loop(){
//  black_a = black_1();
//  
//  if (black_a <= 150 && black == 1)
// {
//  t = 0;
//  while(t<1000)
//    {  
//      if(t_back == 0)
//      {
//       houtui();    
//       delay(1);
//       black = 0;
//       shouhui();
//       t++;
//      }
//      else
//       {
//        houtui();
//        black = 0;
//        shouhui();
//       }
//    }
//  
//    houtuitingzhi();
//    delay(500);
// }
//  else
  {
    if (Serial.available())
    {  
      var = Serial.read();
      switch (var)
      {
        case 'f':
        {
          qianjin();
          shouhui();
          
          break;
        }
        
        case 'b':
        {
         // if(black == 1)
            houtui();

          shouhui();
          black = 0;
          break;
        }
        
        case 's':
        {
          qianjintingzhi();
          break;
        }

        case 'w':
        {
          houtuitingzhi();
          break;
          }
               
        case 'l':
        {
          //Serial.println("Hello Raspberry,I am Arduino.l");
          xiaozuozhuan();
          break;
        }
        
        case 'r':
        {
          //Serial.println("Hello Raspberry,I am Arduino.r");
          xiaoyouzhuan();
          break;
        }
        
        case 'R':
        {
          //Serial.println("Hello Raspberry,I am Arduino.r");
          kuaisuyouzhuan();          
          shouhui();
          break;
        }
        
//        case 'L':
//        {
//          //Serial.println("Hello Raspberry,I am Arduino.r");
//          bushache();
//          kuaisu();
//          jizuozhuan();
//          break;
//        }
        
        case 'm':
        { 
          manxingqianjin();
          zheguang();
          black = 1;
          break;
        }
  
        case 'q':
        {
          manxingzuozhuan();
          zheguang();
          black = 1;
            
          break;
        }
  
        case 'e':
        {
          manxingyouzhuan();
          zheguang();
          black = 1;

          break;
        }
        case 'z':
        {
          zheguang();
          break;
        }
        default:
        {
          //Serial.println("error");
          qianjintingzhi();
          break;
        }
      }
    }
  }
}


