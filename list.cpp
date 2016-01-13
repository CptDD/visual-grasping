#include <iostream>
#include <std_msgs/Int32.h>
#include <ros/ros.h>

using namespace std;

void callback(const std_msgs::Int32::ConstPtr &msg)
{
		cout<<"Received :"<<msg->data<<endl;
}


int main(int argc,char**argv)
{
		ros::init(argc,argv,"listener");

		ros::NodeHandle n;

		ros::Subscriber sub=n.subscribe("/go",10,callback);

		ros::spin();

		return 0;

}