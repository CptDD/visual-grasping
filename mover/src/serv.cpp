#include <iostream>
#include <ros/ros.h>
#include <mover/my_srv.h>

using namespace std;


bool callback(mover::my_srv::Request &req,mover::my_srv::Response &resp)
{
	cout<<"Received :"<<req.in;
	resp.out="Sent";

	return true;
}


int main(int argc,char**argv)
{
	ros::init(argc,argv,"s_service");
	ros::NodeHandle n;

	ros::ServiceServer s=n.advertiseService("simple_service",callback);

	ros::spin();

	return 0;

}