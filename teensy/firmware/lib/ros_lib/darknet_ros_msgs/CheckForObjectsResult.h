#ifndef _ROS_darknet_ros_msgs_CheckForObjectsResult_h
#define _ROS_darknet_ros_msgs_CheckForObjectsResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "darknet_ros_msgs/BoundingBoxes.h"

namespace darknet_ros_msgs
{

  class CheckForObjectsResult : public ros::Msg
  {
    public:
      typedef int16_t _id_type;
      _id_type id;
      typedef darknet_ros_msgs::BoundingBoxes _bounding_boxes_type;
      _bounding_boxes_type bounding_boxes;

    CheckForObjectsResult():
      id(0),
      bounding_boxes()
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
      offset += this->bounding_boxes.serialize(outbuffer + offset);
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
      offset += this->bounding_boxes.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "darknet_ros_msgs/CheckForObjectsResult"; };
    const char * getMD5(){ return "e1c1eea05bd032baf074f5342bdbaf2c"; };

  };

}
#endif