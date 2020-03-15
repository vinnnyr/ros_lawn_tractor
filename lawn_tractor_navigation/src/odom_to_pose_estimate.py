#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String, Bool
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseWithCovarianceStamped

pub = rospy.Publisher('/initialpose', PoseWithCovarianceStamped, queue_size=10)

class ROS_NODE():
    def __init__(self):
        rospy.init_node('odom_to_pose', anonymous=True)
        sub = rospy.Subscriber("/odom",Odometry,self.odomCallback)
        rate = rospy.Rate(1.0) # 10hz
        while not rospy.is_shutdown():
            try:
                pub.publish(self.poseOut)
            except AttributeError:
                rate.sleep()
            rate.sleep()
    def odomCallback(self,data):
        #unpack the odometry msg and send out the pose estimate 
        odomMsg = data
        poseOut = PoseWithCovarianceStamped()
        poseOut.header = odomMsg.header
        poseOut.header.frame_id = "map"
        poseOut.pose = odomMsg.pose
        self.poseOut = poseOut

if __name__ == '__main__':
    try:
        node = ROS_NODE()
    except rospy.ROSInterruptException:
        pass