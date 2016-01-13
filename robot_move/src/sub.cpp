#include<iostream>
#include<ros/ros.h>
#include<robot_move/my.h>

using namespace std;


void msg_callback(const robot_move::my &msg)
{
	cout<<"The received message :"<<msg.description<<" "<<msg.value<<endl;
}


int main(int argc,char**argv)
{
	ros::init(argc,argv,"sub_robot");
	
	ros::NodeHandle handle;
	
	ros::Subscriber subscriber=handle.subscribe("/robot_topic",1,msg_callback);
	
	ros::Rate loop_rate(30);
	
	while(ros::ok())
	{
		loop_rate.sleep();
		ros::spinOnce();
	}
	
	
	return 0;
		
}
