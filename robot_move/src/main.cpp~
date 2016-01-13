#include<iostream>
#include<ros/ros.h>
#include<robot_move/my.h>

using namespace std;


int main(int argc,char**argv)
{
	ros::init(argc,argv,"robot_publisher");
	
	ros::NodeHandle handle;
	
	
	ros::Publisher publisher=handle.advertise<robot_move::my>("/robot_topic",1);
	
	ros::Rate loop_rate(30);
	
	while(ros::ok())
	{
		robot_move::my msg;
		msg.description="Go go go!";
		msg.value=46;
		publisher.publish(msg);
		cout<<"Published :"<<msg.description<<" "<<msg.value<<endl;
		
		loop_rate.sleep();
		ros::spinOnce();
	}
	
}
