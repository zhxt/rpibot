#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

#include "rpibot/motor_interface.h"

#include <sstream>

MotorInterface *motor;

const float EPSILON = 0.00001; 

//void velocityCallback(const std_msgs::String::ConstPtr& msg)
void velocityCallback(const geometry_msgs::Twist::ConstPtr& vel)
{
	ROS_INFO("I heard: linear:  [x: %f, y: %f, z: %f]", vel->linear.x, vel->linear.y, vel->linear.z);
	ROS_INFO("I heard: angular: [x: %f, y: %f, z: %f]", vel->angular.x, vel->angular.y, vel->angular.z);
	
	if ((vel->linear.x >= -EPSILON) && (vel->linear.x <= +EPSILON)) {
		ROS_INFO("stop");
		motor->stop();
	} else if (vel->linear.x > +EPSILON) {
		ROS_INFO("go forward");
		motor->goForward();
	} else if (vel->linear.x < -EPSILON) {
		ROS_INFO("go backward");
		motor->goBackward();
	}	 
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "rpibot_motor_driver");

	motor = new MotorInterface;

	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe<geometry_msgs::Twist>("/rpibot/cmd_vel", 1000, velocityCallback);
	ros::spin();
	return 0;
}
