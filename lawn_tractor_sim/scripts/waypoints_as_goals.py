#! /usr/bin/env python
#
# waypoints_as_goals.py
#
# Bill Mania <bill@manialabs.us>
#
"""waypoints_as_goals.py

An action client which demonstrates the publishing of goals
to move_base.

"""

from __future__ import print_function

import roslib
roslib.load_manifest('lawn_tractor_sim')
import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal


client = actionlib.SimpleActionClient('move_base', MoveBaseAction)

def goal_is_done(end_state, end_result):
    rospy.loginfo('Done: end_state: %d', end_state)


def goal_is_active():
    rospy.loginfo('Active goal')


def goal_feedback(feedback):
    timestamp = feedback.base_position.header.stamp.secs
    x = feedback.base_position.pose.position.x
    y = feedback.base_position.pose.position.y
    theta = feedback.base_position.pose.orientation.w
    current_state = client.get_state()
    rospy.loginfo('Feedback: %d: %f, %f, %f, %d',
                  timestamp,
                  x,
                  y,
                  theta,
                  current_state)


def move_base_client(x, y):
    """move_base_client()

    """

    client.wait_for_server()

    goal = MoveBaseGoal()
    goal.target_pose.header.frame_id = 'map'
    goal.target_pose.pose.position.x = x
    goal.target_pose.pose.position.y = y
    goal.target_pose.pose.orientation.w = 1.0

    client.send_goal(goal=goal,
                     done_cb=goal_is_done,
                     active_cb=goal_is_active,
                     feedback_cb=goal_feedback)

    rospy.loginfo('Waiting for action to complete')
    if client.wait_for_result(timeout=rospy.Duration(10.0)):
        rospy.loginfo('Goal reached')
    else:
        rospy.logwarn('wait_for_result() returned False, cancelling goal')
        client.cancel_goal()

    return

if __name__ == '__main__':
    rospy.init_node('waypoints_as_goals')
    for position in [(12.0, 2.0), (2.0, 12.0), (5.0, 5.0), (20.0, 20.0)]:
        rospy.loginfo('Moving to (%f, %f)', position[0], position[1])
        move_base_client(position[0], position[1])
        rospy.loginfo('Done')
