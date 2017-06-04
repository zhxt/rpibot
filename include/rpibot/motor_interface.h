#include <iostream>
#include "geometry_msgs/Twist.h"

class MotorInterface
{
public:
	MotorInterface();
	~MotorInterface();

	void go(geometry_msgs::Twist vel);
	void goForward();
	void goBackward();
	void goLeft();
	void goRight();
	void stop();
	void init();
private:
	int state;	
};
