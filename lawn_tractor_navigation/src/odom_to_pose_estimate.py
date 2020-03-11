#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String, Bool
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseWithCovarianceStamped

pub = rospy.Publisher('/pose_estimate', PoseWithCovarianceStamped, queue_size=10)

class ROS_NODE():
    def __init__(self):
        rospy.init_node('odom_to_pose', anonymous=True)
        sub = rospy.Subscriber("/odom",Odometry,self.odomCallback)
        boolSub = rospy.Subscriber('/hybrid_astar/isPathRecieved',Bool,self.boolCallback)
        rate = rospy.Rate(1.0) # 10hz
        self.shouldPub = False
        self.firstTime = True
        while not rospy.is_shutdown():
            if self.shouldPub:
                pub.publish(self.poseOut)
            rate.sleep()
    def boolCallback(self,data):
        self.shouldPub = not data
    def odomCallback(self,data):
        #unpack the odometry msg and send out the pose estimate 
        odomMsg = data
        poseOut = PoseWithCovarianceStamped()
        poseOut.header = odomMsg.header
        poseOut.pose = odomMsg.pose
        if self.firstTime:
            self.poseOut = poseOut
            self.shouldPub = True
        elif self.poseOut.pose.x == poseOut.pose.x & self.poseOut.pose.y == poseOut.pose.y:
            self.shouldPub = False
        else:
            rospy.loginfo["new pose being sent"]
            self.poseOut = poseOut
            self.shouldPub = True


    



if __name__ == '__main__':
    try:
        node = ROS_NODE()
    except rospy.ROSInterruptException:
        pass