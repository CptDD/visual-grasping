#include<iostream>
#include<ros/ros.h>

using namespace std;


void binarySearch(int a[],int l,int h,int k)
{	
	int m;
	while(l<h)
	{
		m=(l+h)/2;
		
		if(k<a[m])
		{
			h=m;
		}else if(k>a[m])
		{
			l=m;
		}
	}	
	
	cout<<"Found :"<<a[m]<<endl;
}


int main(int argc,char**argv)
{
	ros::init(argc,argv,"transformer");
	
	ros::NodeHandle node_handle;
	
	int a[]={1,2,3,4,5,6,7,8,9,10};
	
	binarySearch(a,0,10,9);
	
	return 0;
	
}
