#ifndef _ROS_rviz_ba_viewer_BaPoint_h
#define _ROS_rviz_ba_viewer_BaPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point32.h"

namespace rviz_ba_viewer
{

  class BaPoint : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef geometry_msgs::Point32 _position_type;
      _position_type position;
      typedef uint32_t _keyframe_id_type;
      _keyframe_id_type keyframe_id;
      typedef float _depth_sigma_type;
      _depth_sigma_type depth_sigma;

    BaPoint():
      id(0),
      position(),
      keyframe_id(0),
      depth_sigma(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->position.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->keyframe_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->keyframe_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->keyframe_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->keyframe_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->keyframe_id);
      offset += serializeAvrFloat64(outbuffer + offset, this->depth_sigma);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      offset += this->position.deserialize(inbuffer + offset);
      this->keyframe_id =  ((uint32_t) (*(inbuffer + offset)));
      this->keyframe_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->keyframe_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->keyframe_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->keyframe_id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->depth_sigma));
     return offset;
    }

    const char * getType(){ return "rviz_ba_viewer/BaPoint"; };
    const char * getMD5(){ return "5198ef4f27797808b179c56dfdb85aa9"; };

  };

}
#endif