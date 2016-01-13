#include <iostream>
#include <moveit/move_group_interface/move_group.h>

using namespace std;


int main(int argc,char**argv)
{
	ros::init(argc,argv,"random_position",ros::init_options::AnonymousName);

	ros::AsyncSpinner spinner(1);
	spinner.start();

	move_group_interface::MoveGroup group("arm");

	group.setRandomTarget();
	group.move();

	ros::waitForShutdown();

	return 0;
}