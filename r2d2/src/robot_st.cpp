#include <iostream>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <interactive_markers/interactive_marker_server.h>

using namespace std;

void feedback_callback(const visualization_msgs::InteractiveMarkerFeedbackConstPtr &feedback)
{
      double roll,pitch,yaw;

      tf::Quaternion q;
      tf::quaternionMsgToTF(feedback->pose.orientation,q);
      tf::Matrix3x3(q).getRPY(roll,pitch,yaw);

      cout<<"Marker name :"<<feedback->marker_name<<endl;
      cout<<"Roll :"<<roll<<" Pitch :"<<pitch<<" Yaw :"<<yaw<<endl;

      cout<<"X :"<<feedback->pose.position.x<<" "<<feedback->pose.position.y<<" "<<feedback->pose.position.z<<endl;

}


int main(int argc,char**argv)
{
         ros::init(argc,argv,"interactive_marker");

         
         interactive_markers::InteractiveMarkerServer server("server");

         visualization_msgs::InteractiveMarker marker;
         marker.header.frame_id="/base_link";   
         marker.name="Interactive Marker";
         marker.description="2-DOF control";

         cout<<"The server is running!"<<endl;

         visualization_msgs::Marker box_marker;
         box_marker.type=visualization_msgs::Marker::CUBE;
         box_marker.scale.x=0.5;
         box_marker.scale.y=0.5;
         box_marker.scale.z=0.5;

         box_marker.color.r=1.0;
         box_marker.color.g=0.0;
         box_marker.color.b=0.0;
         box_marker.color.a=1.0;

         visualization_msgs::InteractiveMarkerControl box_control;
         box_control.always_visible=true;
         box_control.markers.push_back(box_marker);


         visualization_msgs::InteractiveMarkerControl move_x,rotate_z;

         move_x.name="move_x";
         move_x.interaction_mode=visualization_msgs::InteractiveMarkerControl::MOVE_AXIS;

         rotate_z.name="rotate_z";
         rotate_z.orientation.w=1;
         rotate_z.orientation.y=1;
         rotate_z.interaction_mode=visualization_msgs::InteractiveMarkerControl::ROTATE_AXIS;

         marker.controls.push_back(box_control);
         marker.controls.push_back(move_x);
         marker.controls.push_back(rotate_z);

         server.insert(marker,&feedback_callback);
         server.applyChanges();

         ros::spin();










         




}
