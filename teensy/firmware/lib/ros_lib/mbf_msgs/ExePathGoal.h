#ifndef _ROS_mbf_msgs_ExePathGoal_h
#define _ROS_mbf_msgs_ExePathGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/Path.h"

namespace mbf_msgs
{

  class ExePathGoal : public ros::Msg
  {
    public:
      typedef nav_msgs::Path _path_type;
      _path_type path;
      typedef const char* _controller_type;
      _controller_type controller;
      typedef uint8_t _concurrency_slot_type;
      _concurrency_slot_type concurrency_slot;

    ExePathGoal():
      path(),
      controller(""),
      concurrency_slot(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      uint32_t length_controller = strlen(this->controller);
      varToArr(outbuffer + offset, length_controller);
      offset += 4;
      memcpy(outbuffer + offset, this->controller, length_controller);
      offset += length_controller;
      *(outbuffer + offset + 0) = (this->concurrency_slot >> (8 * 0)) & 0xFF;
      offset += sizeof(this->concurrency_slot);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
      uint32_t length_controller;
      arrToVar(length_controller, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_controller; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_controller-1]=0;
      this->controller = (char *)(inbuffer + offset-1);
      offset += length_controller;
      this->concurrency_slot =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->concurrency_slot);
     return offset;
    }

    const char * getType(){ return "mbf_msgs/ExePathGoal"; };
    const char * getMD5(){ return "33ff17a095839640ba7e28c0dc858031"; };

  };

}
#endif