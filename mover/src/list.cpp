#include <iostream>
#include <mover/my_msg.h>
#include <ros/ros.h>

using namespace std;

void callback(const mover::my_msg::ConstPtr &msg)
{
		cout<<"Received :"<<msg->name<<" "<<msg->age<<endl;
}


int main(int argc,char**argv)
{
		ros::init(argc,argv,"listener");

		ros::NodeHandle n;

		ros::Subscriber sub=n.subscribe("/go",10,callback);

		ros::spin();

		return 0;

}