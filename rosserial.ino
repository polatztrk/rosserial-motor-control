
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Int16.h>
#include <AFMotor.h>
#include <std_msgs/UInt16.h>


ros::NodeHandle  nh;


AF_DCMotor motor1(1, MOTOR12_64KHZ);

AF_DCMotor motor2(2, MOTOR12_64KHZ);

AF_DCMotor motor3(3, MOTOR12_64KHZ);

AF_DCMotor motor4(4, MOTOR12_64KHZ);

void pwm_input( const std_msgs::UInt16& pwm_value){
  int pwm =0;
  pwm = pwm_value.data;

  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor4.setSpeed(pwm);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(1000);

}

ros::Subscriber<std_msgs::UInt16> pwm("PWM_Values", pwm_input);

void setup()
{
  nh.initNode();
  nh.subscribe(pwm);


}

void loop()
{
  
  nh.spinOnce();
  delay(1);


}
