#ifndef _ROS_darknet_ros_msgs_CheckForObjectsFeedback_h
#define _ROS_darknet_ros_msgs_CheckForObjectsFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace darknet_ros_msgs
{

  class CheckForObjectsFeedback : public ros::Msg
  {
    public:

    CheckForObjectsFeedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "darknet_ros_msgs/CheckForObjectsFeedback"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif