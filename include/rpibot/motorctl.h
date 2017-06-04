#ifndef MOTORCTL_H
#define MOTORCTL_H

#include <stdio.h>
#include <stdlib.h>
#include <softPwm.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <wiringPi.h>


#define Trig	28
#define Echo	29
#define LEFT	11
#define RIGHT	10
#define BUFSIZE 512

#define MOTOR_GO_FORWARD   digitalWrite(1,HIGH);digitalWrite(4,LOW);digitalWrite(5,HIGH);digitalWrite(6,LOW)
#define MOTOR_GO_BACK	   digitalWrite(4,HIGH);digitalWrite(1,LOW);digitalWrite(6,HIGH);digitalWrite(5,LOW)
#define MOTOR_GO_RIGHT	   digitalWrite(1,HIGH);digitalWrite(4,LOW);digitalWrite(6,HIGH);digitalWrite(5,LOW)
#define MOTOR_GO_LEFT	   digitalWrite(4,HIGH);digitalWrite(1,LOW);digitalWrite(5,HIGH);digitalWrite(6,LOW)
#define MOTOR_GO_STOP	   digitalWrite(1, LOW);digitalWrite(4,LOW);digitalWrite(5, LOW);digitalWrite(6,LOW)

void ultraInit(void)
{
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
}


void print_status()
{
    int fL, fR, bL, bR;
    fL = digitalRead(1);
    fR = digitalRead(4);
    bL = digitalRead(5);
    bR = digitalRead(6);
    printf("fL: %d, fR: %d\n", fL, fR);
}

void reset_motor()
{
    printf("reset motor\n");
    digitalWrite(1,0);
    digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,0);
    print_status();
}
void go_forward()
{
    printf("go forward\n");
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(4,LOW);

    softPwmWrite(24,100); 
    softPwmWrite(25,100); 
    //delay(1000);
//    reset_motor();
   // while(1) {
   // 	delay(500);
   // }
}

void go_backward()
{
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(1,LOW);
}

void go_left()
{
    printf("go forward\n");
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(4,LOW);

    softPwmWrite(24,50); 
    softPwmWrite(25,250); 
    delay(1000);
    reset_motor();
}
void init_motor()
{
    //wiringPiSetup();
    pinMode (1, OUTPUT);	//IN1
    pinMode (4, OUTPUT);	//IN2
    pinMode (5, OUTPUT);	//IN3
    pinMode (6, OUTPUT);	//IN4
    pinMode (24,OUTPUT);	//ENA
    pinMode (25,OUTPUT);	//EAB

    int ret = softPwmCreate(24,0, 300); 
    if (ret != 0) {
	printf("Failed to create pwm\n");
    }

    ret = softPwmCreate(25,0, 300); 
    if (ret != 0) {
	printf("Failed to create pwm\n");
    }
}
#endif
