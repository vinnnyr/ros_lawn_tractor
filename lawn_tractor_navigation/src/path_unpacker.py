#!/usr/bin/env python
#Stupid node to unpack a path into it's poses, should probably be done within actionserver / SMACH framework
#Will subscribe to the path, and the success state of the Move base flex EXEPath action. 
import rospy
from nav_msgs.msg import Path
from geometry_msgs.msg import PoseStamped

class PathUnpacker():
    def __init__(self):
        rospy.init_node('path_unpacker')
        
        self.pathSub = rospy.Subscriber('/hybrid_astar/goalPath',Path,self.newPathCallback)
        self.posePub = rospy.Publisher('/hybrid_astar/goalPathUnpacked',PoseStamped,queue_size=10)
    
    def run(self):
        rate = rospy.Rate(10) # 10hz
        while not rospy.is_shutdown():
            rate.sleep()
    
    def newPathCallback(self,newPath):
        poses = newPath.poses
        for pose in poses:
            self.posePub.publish(pose)

if __name__ == '__main__':
    pathUnpacker = PathUnpacker()
    pathUnpacker.run()

