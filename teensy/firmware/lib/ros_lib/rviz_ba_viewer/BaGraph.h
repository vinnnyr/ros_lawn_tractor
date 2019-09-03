#ifndef _ROS_rviz_ba_viewer_BaGraph_h
#define _ROS_rviz_ba_viewer_BaGraph_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "rviz_ba_viewer/KeyFrame.h"
#include "rviz_ba_viewer/BaPoint.h"

namespace rviz_ba_viewer
{

  class BaGraph : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t keyframes_length;
      typedef rviz_ba_viewer::KeyFrame _keyframes_type;
      _keyframes_type st_keyframes;
      _keyframes_type * keyframes;
      uint32_t points_length;
      typedef rviz_ba_viewer::BaPoint _points_type;
      _points_type st_points;
      _points_type * points;

    BaGraph():
      header(),
      keyframes_length(0), keyframes(NULL),
      points_length(0), points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->keyframes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->keyframes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->keyframes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->keyframes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->keyframes_length);
      for( uint32_t i = 0; i < keyframes_length; i++){
      offset += this->keyframes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t keyframes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      keyframes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      keyframes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      keyframes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->keyframes_length);
      if(keyframes_lengthT > keyframes_length)
        this->keyframes = (rviz_ba_viewer::KeyFrame*)realloc(this->keyframes, keyframes_lengthT * sizeof(rviz_ba_viewer::KeyFrame));
      keyframes_length = keyframes_lengthT;
      for( uint32_t i = 0; i < keyframes_length; i++){
      offset += this->st_keyframes.deserialize(inbuffer + offset);
        memcpy( &(this->keyframes[i]), &(this->st_keyframes), sizeof(rviz_ba_viewer::KeyFrame));
      }
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (rviz_ba_viewer::BaPoint*)realloc(this->points, points_lengthT * sizeof(rviz_ba_viewer::BaPoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(rviz_ba_viewer::BaPoint));
      }
     return offset;
    }

    const char * getType(){ return "rviz_ba_viewer/BaGraph"; };
    const char * getMD5(){ return "724d69c8e20124c8a4ad0bd429b4253f"; };

  };

}
#endif