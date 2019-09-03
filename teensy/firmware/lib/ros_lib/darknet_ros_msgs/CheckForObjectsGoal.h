#ifndef _ROS_darknet_ros_msgs_CheckForObjectsGoal_h
#define _ROS_darknet_ros_msgs_CheckForObjectsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"

namespace darknet_ros_msgs
{

  class CheckForObjectsGoal : public ros::Msg
  {
    public:
      typedef int16_t _id_type;
      _id_type id;
      typedef sensor_msgs::Image _image_type;
      _image_type image;

    CheckForObjectsGoal():
      id(0),
      image()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->image.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += this->image.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "darknet_ros_msgs/CheckForObjectsGoal"; };
    const char * getMD5(){ return "c2342f9acc4aac63fdd632073dd76c7d"; };

  };

}
#endif