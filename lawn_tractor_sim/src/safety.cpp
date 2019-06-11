#include <ros/ros.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

class SafetyNode
{
public:
  SafetyNode()
  {
    pub_ = n_.advertise<geometry_msgs::Twist>("cmd_vel_mux/safety", 1);
    sub_ = n_.subscribe("/ultrasonic", 1, &SafetyNode::callback, this);
  }

  void callback(const sensor_msgs::Range& input)
  {
    float dist_threshold;
    //Get distance threshold paramter
    n_.param("distance_threshold", dist_threshold, float(2.5)); // meters
    geometry_msgs::Twist output;
    //If robot is too close, send 0 cmd_vel
        if (input.range < dist_threshold ){
            output.angular.x = 0;
            output.angular.y = 0;
            output.angular.y = 0;
            output.linear.x = 0;
            output.linear.y = 0;
            output.linear.z = 0;  
            pub_.publish(output);      
        }
    }  

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SafetyNode

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "too_close");

  //Create an object of class SafetyNode that will take care of everything
  SafetyNode SAPObject;

  ros::spin();

  return 0;
}