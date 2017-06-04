#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "rpibot_teleop_motor");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<std_msgs::String>("/rpibot/cmd_vel",1000);
	ros::Rate loop_rate(10);

	int count  = 0;
	while(ros::ok()) {
		//TODO: pub Twsit message.
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world" << count;
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());
		pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
	return 0;
}
