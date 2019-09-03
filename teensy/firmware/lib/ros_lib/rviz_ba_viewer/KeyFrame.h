#ifndef _ROS_rviz_ba_viewer_KeyFrame_h
#define _ROS_rviz_ba_viewer_KeyFrame_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"

namespace rviz_ba_viewer
{

  class KeyFrame : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _id_type;
      _id_type id;
      typedef geometry_msgs::PoseWithCovariance _pose_type;
      _pose_type pose;
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef sensor_msgs::CameraInfo _cinfo_type;
      _cinfo_type cinfo;
      uint32_t point_ids_length;
      typedef uint32_t _point_ids_type;
      _point_ids_type st_point_ids;
      _point_ids_type * point_ids;

    KeyFrame():
      header(),
      id(0),
      pose(),
      image(),
      cinfo(),
      point_ids_length(0), point_ids(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->image.serialize(outbuffer + offset);
      offset += this->cinfo.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->point_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_ids_length);
      for( uint32_t i = 0; i < point_ids_length; i++){
      *(outbuffer + offset + 0) = (this->point_ids[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_ids[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_ids[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_ids[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_ids[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->cinfo.deserialize(inbuffer + offset);
      uint32_t point_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_ids_length);
      if(point_ids_lengthT > point_ids_length)
        this->point_ids = (uint32_t*)realloc(this->point_ids, point_ids_lengthT * sizeof(uint32_t));
      point_ids_length = point_ids_lengthT;
      for( uint32_t i = 0; i < point_ids_length; i++){
      this->st_point_ids =  ((uint32_t) (*(inbuffer + offset)));
      this->st_point_ids |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_point_ids |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_point_ids |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_point_ids);
        memcpy( &(this->point_ids[i]), &(this->st_point_ids), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "rviz_ba_viewer/KeyFrame"; };
    const char * getMD5(){ return "8581547716aba0147e523814ee52048c"; };

  };

}
#endif