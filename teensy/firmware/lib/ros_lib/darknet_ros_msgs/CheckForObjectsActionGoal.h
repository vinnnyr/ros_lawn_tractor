#ifndef _ROS_darknet_ros_msgs_CheckForObjectsActionGoal_h
#define _ROS_darknet_ros_msgs_CheckForObjectsActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "darknet_ros_msgs/CheckForObjectsGoal.h"

namespace darknet_ros_msgs
{

  class CheckForObjectsActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef darknet_ros_msgs::CheckForObjectsGoal _goal_type;
      _goal_type goal;

    CheckForObjectsActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "darknet_ros_msgs/CheckForObjectsActionGoal"; };
    const char * getMD5(){ return "5276fa5e1994ff473eead64845a6fd41"; };

  };

}
#endif