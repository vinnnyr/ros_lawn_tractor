#!/usr/bin/env python

#
#  The Construct Video Tutorial on Markers https://www.youtube.com/watch?v=5pGzW-M6iGQ
#  Tutorial on basic shapes http://wiki.ros.org/rviz/Tutorials/Markers%3A%20Basic%20Shapes
#  Different shapes you can use http://wiki.ros.org/rviz/DisplayTypes/Marker
#

import rospy
from visualization_msgs.msg import Marker
from visualization_msgs.msg import MarkerArray


# Trees in orchard
marker_list = [[10,5], [10, 0], [10,-5],
               [15,5], [15, 0], [15,-5],
               [20,5], [20, 0], [20,-5]
            ]


class OrchardVis():

    def __init__(self):
        self.marker_vis = MarkerArray()
        self.vis_pub = rospy.Publisher('orchard_vis', MarkerArray, queue_size=10)

        marker_count = 0

        for m in marker_list:
            marker_count += 1
            marker = Marker()
            marker.header.frame_id = "map"
            marker.id = marker_count
            marker.type = marker.CYLINDER
            marker.action = marker.ADD
            marker.scale.x = 0.25
            marker.scale.y = 0.25
            marker.scale.z = 1.0
            marker.color.a = 1.0
            marker.color.r = 1.00
            marker.color.g = 0.67
            marker.color.b = 0.33
            marker.pose.orientation.w = 1.0
            marker.pose.position.x = m[0]
            marker.pose.position.y = m[1]
            marker.pose.position.z = 1

            self.marker_vis.markers.append(marker)
            

    def publish_vis(self):
        rate = rospy.Rate(1)
        while not rospy.is_shutdown():
            self.vis_pub.publish(self.marker_vis)
            rate.sleep()
        rospy.spin()


if __name__ == '__main__':
    rospy.init_node('orchar_vis_node')
    orchard_object = OrchardVis()
    try:
        orchard_object.publish_vis()
    except rospy.ROSInterruptException:
        pass
