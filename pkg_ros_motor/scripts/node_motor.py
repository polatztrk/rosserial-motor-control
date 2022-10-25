#!/usr/bin/env python
import rospy

from std_msgs.msg import Int64
from std_msgs.msg import Float64
from std_msgs.msg import Int16


PWM_Output = 188

pub = rospy.Publisher('/PWM_Values',Int16,queue_size=100)

def pub_pwm():
    pub.publish(PWM_Output)

if __name__ == '__main__':
    print("Running")
    pub_pwm()