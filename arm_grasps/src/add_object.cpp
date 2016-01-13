#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>


int main(int argc,char**argv)
{
	ros::init(argc,argv,"object_addition");

	ros::NodeHandle nh;

	ros::AsyncSpinner spinner(1);
	spinner.start();

	moveit::planning_interface::PlanningSceneInterface  scene;

	sleep(3.0);

	moveit_msgs::CollisionObject cylinder;
	cylinder.id="manipulator_arm_cylinder";

	shape_msgs::SolidPrimitive solid_primitive;
	solid_primitive.type=solid_primitive.CYLINDER;
	solid_primitive.dimensions.resize(3);
	solid_primitive.dimensions[0]=0.04;
	solid_primitive.dimensions[1]=0.02;

	geometry_msgs::Pose pose;
	pose.orientation.w=1.0;
	pose.position.x=0.0;
	pose.position.y=-0.5;
	pose.position.z=0.0;

	cylinder.primitives.push_back(solid_primitive);
	cylinder.primitive_poses.push_back(pose);
	cylinder.operation=cylinder.ADD;

	std::vector<moveit_msgs::CollisionObject> collision_objects;
    collision_objects.push_back(cylinder);

   
    scene.addCollisionObjects(collision_objects);

    ros::shutdown();


}