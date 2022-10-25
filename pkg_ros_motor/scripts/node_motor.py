#!/usr/bin/env python3
import rospy

from std_msgs.msg import Int64
from std_msgs.msg import Float64
from std_msgs.msg import Int16


PWM_Output = 188

pub = rospy.Publisher('PWM_Values',Int16,queue_size=100)

def pub_pwm():
    r = rospy.Rate(1) # 1hz 
    while not rospy.is_shutdown():
        pub.publish(PWM_Output)
        print("Publishing PWM value: {}".format(PWM_Output))
        r.sleep()

if __name__ == '__main__':
    print("Running")
    rospy.init_node('pub')
    pub_pwm()
