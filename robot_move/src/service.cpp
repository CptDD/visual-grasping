#include<iostream>
#include<ros/ros.h>
#include <robot_move/my_service.h>

using namespace std;


bool add(robot_move::my_service::Request &req,robot_move::my_service::Response &res)
{
	res.sum=req.a+req.b;
	return true;
}


int main(int argc,char**argv)
{
	ros::init(argc,argv,"simple_server");
	
	ros::NodeHandle handle;
	
	ros::ServiceServer server=handle.advertiseService("add_two_ints",add);
	
	cout<<"Ready!"<<endl;
	ros::spin();
	
	
	return 0;
	
}
