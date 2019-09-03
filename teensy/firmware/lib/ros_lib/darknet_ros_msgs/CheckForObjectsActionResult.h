#ifndef _ROS_darknet_ros_msgs_CheckForObjectsActionResult_h
#define _ROS_darknet_ros_msgs_CheckForObjectsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "darknet_ros_msgs/CheckForObjectsResult.h"

namespace darknet_ros_msgs
{

  class CheckForObjectsActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef darknet_ros_msgs::CheckForObjectsResult _result_type;
      _result_type result;

    CheckForObjectsActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "darknet_ros_msgs/CheckForObjectsActionResult"; };
    const char * getMD5(){ return "7c8ca8b3a5ded7528f44f0cf05628c0d"; };

  };

}
#endif