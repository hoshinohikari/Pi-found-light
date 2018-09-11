Pi-found-light
===========================
本代码用于RaspberryPi 3的Python3+OpenCV 3.4.0环境，使用USB串口与Arduino Mega 2560链接
|Author|hoshinokun|
|---|---
|E-mail|hoshinokirari

## 目录
* [介绍](#介绍)
* [准备](#准备)
* [运行](#运行)

介绍
------
这是一个基于树莓派的OpenCV3库RasCamera库调节摄像头参数，使其适应各种环境能够正确寻找到合适颜色的光源的寻光程序，为了解决RaspberryPi的硬件接口上的先天缺陷，我们仅采用树莓派完成寻光工作，而靠串口通讯方法让Arduion做出行动判断。
由于树莓派采用软件PWM，所以采用树莓派与Arduino之间用I2C总线通信的方法，通过使用Arduino实现硬件PWM的功能
