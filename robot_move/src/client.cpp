#include<iostream>
#include<ros/ros.h>
#include<robot_move/my_service.h>

using namespace std;


int main(int argc,char**argv)
{
	ros::init(argc,argv,"simple_client");
	
	ros::NodeHandle handle;
	
	ros::ServiceClient client=handle.serviceClient<robot_move::my_service>("add_two_ints");
	
	robot_move::my_service srv;
	srv.request.a=10;
	srv.request.b=9;
	
	if(client.call(srv))
	{
		cout<<"Client called"<<endl;
		
		cout<<"Got :"<<srv.response.sum<<endl;
	}else{
		cout<<"An error has occured!"<<endl;
	}
	
	
	
	return 0;
}
