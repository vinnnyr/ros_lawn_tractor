#ifndef _ROS_darknet_ros_msgs_CheckForObjectsAction_h
#define _ROS_darknet_ros_msgs_CheckForObjectsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "darknet_ros_msgs/CheckForObjectsActionGoal.h"
#include "darknet_ros_msgs/CheckForObjectsActionResult.h"
#include "darknet_ros_msgs/CheckForObjectsActionFeedback.h"

namespace darknet_ros_msgs
{

  class CheckForObjectsAction : public ros::Msg
  {
    public:
      typedef darknet_ros_msgs::CheckForObjectsActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef darknet_ros_msgs::CheckForObjectsActionResult _action_result_type;
      _action_result_type action_result;
      typedef darknet_ros_msgs::CheckForObjectsActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    CheckForObjectsAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "darknet_ros_msgs/CheckForObjectsAction"; };
    const char * getMD5(){ return "4b091ec72e3eb1454537f0081ec26232"; };

  };

}
#endif