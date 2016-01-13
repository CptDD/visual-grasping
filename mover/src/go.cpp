#include <iostream>
#include <ros/ros.h>
#include <mover/my_msg.h>

using namespace std;


int main(int argc,char**argv)
{
		ros::init(argc,argv,"simple_publisher");

		ros::NodeHandle n;

		ros::Publisher pub=n.advertise<mover::my_msg>("/go",1);

		ros::Rate loop_rate(30);

		while(ros::ok())
		{
			mover::my_msg msg;
			msg.name="Golfer";
			msg.age=23;

			pub.publish(msg);

			ros::spinOnce();
			loop_rate.sleep();
		}

		return 0;
}