#!/usr/bin/env python
# license removed for brevity
import rospy
import tf
from std_msgs.msg import String, Bool
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped,PoseWithCovarianceStamped

pub = rospy.Publisher('/initialpose', PoseWithCovarianceStamped, queue_size=10)

class ROS_NODE():
    def __init__(self):
        rospy.init_node('odom_to_pose', anonymous=True)
        self.tfListener = tf.TransformListener()
        sub = rospy.Subscriber("/odom",Odometry,self.odomCallback)
        rate = rospy.Rate(.10) 
        while not rospy.is_shutdown():
            try:
                pub.publish(self.poseOut)
            except AttributeError:
                rate.sleep()
            rate.sleep()
        
    def odomCallback(self,data):
        #unpack the odometry msg and send out the pose estimate 
        odomMsg = data
        odomPoseStamped = PoseStamped()
        odomPoseStamped.pose = odomMsg.pose.pose #bascially, get rid of the "Covariance, and the twist"
        odomPoseStamped.header = odomMsg.header
        t = self.tfListener.getLatestCommonTime("/map", "/odom")

        poseOutStamped = odomPoseStamped
        poseOutStampedNew = self.tfListener.transformPose("/map",poseOutStamped)
        poseOutStamped = poseOutStampedNew
        poseOutWithCovariance = PoseWithCovarianceStamped()
        poseOutWithCovariance.header = poseOutStamped.header
        poseOutWithCovariance.pose.pose = poseOutStamped.pose

        self.poseOut = poseOutWithCovariance

if __name__ == '__main__':
    try:
        node = ROS_NODE()
    except rospy.ROSInterruptException:
        pass