#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped,PoseWithCovariance

pub = rospy.Publisher('/pose_estimate', PoseStamped, queue_size=10)

def converter():
    rospy.init_node('odom_to_pose', anonymous=True)
    sub = rospy.Subscriber("/odom",Odometry,odomCallback)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        rate.sleep()

def odomCallback(data):
    #unpack the odometry msg and send out the 
    odomMsg = data
    poseStampedOut = PoseStamped()
    poseStampedOut.header = odomMsg.header
    poseStampedOut.pose = odomMsg.pose.pose
    pub.publish(poseStampedOut)
    



if __name__ == '__main__':
    try:
        converter()
    except rospy.ROSInterruptException:
        pass