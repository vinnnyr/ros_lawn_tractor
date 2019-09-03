#ifndef _ROS_rviz_depth_filter_DepthFilter_h
#define _ROS_rviz_depth_filter_DepthFilter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace rviz_depth_filter
{

  class DepthFilter : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t origins_length;
      typedef geometry_msgs::Point _origins_type;
      _origins_type st_origins;
      _origins_type * origins;
      uint32_t positions_length;
      typedef geometry_msgs::Point _positions_type;
      _positions_type st_positions;
      _positions_type * positions;
      uint32_t sigmas_length;
      typedef float _sigmas_type;
      _sigmas_type st_sigmas;
      _sigmas_type * sigmas;

    DepthFilter():
      header(),
      origins_length(0), origins(NULL),
      positions_length(0), positions(NULL),
      sigmas_length(0), sigmas(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->origins_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->origins_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->origins_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->origins_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->origins_length);
      for( uint32_t i = 0; i < origins_length; i++){
      offset += this->origins[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions_length);
      for( uint32_t i = 0; i < positions_length; i++){
      offset += this->positions[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->sigmas_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sigmas_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sigmas_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sigmas_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sigmas_length);
      for( uint32_t i = 0; i < sigmas_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->sigmas[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t origins_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      origins_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      origins_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      origins_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->origins_length);
      if(origins_lengthT > origins_length)
        this->origins = (geometry_msgs::Point*)realloc(this->origins, origins_lengthT * sizeof(geometry_msgs::Point));
      origins_length = origins_lengthT;
      for( uint32_t i = 0; i < origins_length; i++){
      offset += this->st_origins.deserialize(inbuffer + offset);
        memcpy( &(this->origins[i]), &(this->st_origins), sizeof(geometry_msgs::Point));
      }
      uint32_t positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->positions_length);
      if(positions_lengthT > positions_length)
        this->positions = (geometry_msgs::Point*)realloc(this->positions, positions_lengthT * sizeof(geometry_msgs::Point));
      positions_length = positions_lengthT;
      for( uint32_t i = 0; i < positions_length; i++){
      offset += this->st_positions.deserialize(inbuffer + offset);
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(geometry_msgs::Point));
      }
      uint32_t sigmas_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sigmas_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sigmas_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sigmas_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sigmas_length);
      if(sigmas_lengthT > sigmas_length)
        this->sigmas = (float*)realloc(this->sigmas, sigmas_lengthT * sizeof(float));
      sigmas_length = sigmas_lengthT;
      for( uint32_t i = 0; i < sigmas_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_sigmas));
        memcpy( &(this->sigmas[i]), &(this->st_sigmas), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "rviz_depth_filter/DepthFilter"; };
    const char * getMD5(){ return "5276d9141d8be0b6e6856c516b6309b2"; };

  };

}
#endif