
// PINOUT
// L_EN -> 8
// R_EN -> 8
// L_PWM -> 9
// R_PWM -> 10

#include "BTS7960.h"
#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Int16.h>


ros::NodeHandle  nh;


const uint8_t EN = 8;
const uint8_t L_PWM = 9;
const uint8_t R_PWM = 10;

BTS7960 motorController(EN, L_PWM, R_PWM);

void pwm_input( const std_msgs::Int16& pwm_value){
  int pwm =0;
  pwm = pwm_value.data;

  motorController.TurnLeft(pwm);
  delay(100);

}

ros::Subscriber<std_msgs::Int16> pwm("PWM_Values", &pwm_input);

void setup()
{
  nh.initNode();
  nh.subscribe(pwm);


}

void loop()
{
  motorController.Enable();
  nh.spinOnce();
  delay(100);


}