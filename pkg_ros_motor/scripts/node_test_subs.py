#!/usr/bin/env python
import rospy
from std_msgs.msg import Int64
from std_msgs.msg import Float64
from std_msgs.msg import Int16

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard {}".format(data.data))

def listener():
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("pub",Int16,callback)

    rospy.spin()

if __name__ == '__main__':
    listener()