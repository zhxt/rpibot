#include <iostream>

#include "rpibot/motor_interface.h"
#include "rpibot/motorctl.h"

using namespace std;

MotorInterface::MotorInterface()
{
	init();
}

MotorInterface::~MotorInterface()
{

}

void MotorInterface::init()
{
	if (wiringPiSetup() == -1) {
		printf("setup wiringPi failed!\n");
		return;
	}
	ultraInit();
	init_motor();
}

void MotorInterface::go(geometry_msgs::Twist vel)
{

}

void MotorInterface::goForward()
{
	cout << "go foward" << endl;
	go_forward();
}

void MotorInterface::goBackward()
{
	cout << "go backward" << endl;
	go_backward();
}

void MotorInterface::goLeft()
{
	cout << "go left" << endl;
}

void MotorInterface::goRight()
{
	cout << "go right" << endl;
}

void MotorInterface::stop()
{
	cout << "stop" << endl;
	reset_motor();
}
