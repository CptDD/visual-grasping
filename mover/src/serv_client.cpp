#include <iostream>
#include <ros/ros.h>
#include <mover/my_srv.h>

using namespace std;


int main(int argc,char**argv)
{
	ros::init(argc,argv,"simple_client");


	ros::NodeHandle n;

	ros::ServiceClient sc=n.serviceClient<mover::my_srv>("simple_service");

	ros::Rate loop_rate(30);

	while(ros::ok())
	{
			mover::my_srv srv;
			srv.request.in="Golfer";

			if(sc.call(srv))
			{
				cout<<"Got :"<<srv.response.out<<endl;
			}else
			{
				cout<<"Waiting for response!"<<endl;
			}

			ros::spinOnce();

			loop_rate.sleep();
	}

	return 0;
}