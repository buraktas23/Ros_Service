#include<ros/ros.h>
#include<first_service_example/sum.h>
#include<cstdlib>

int main(int argc,char **argv)
{

	ros::init(argc,argv,"service_client");
	if(argc!=3)
	{
		ROS_INFO("You cannot enter more or less than two values");
		return 1;
	}


	ros::NodeHandle nh;
	ros::ServiceClient service_client = nh.serviceClient<first_service_example::sum>("summing");

	first_service_example::sum srv;
	
	srv.request.a = atoi(argv[1]);
	srv.request.b = atoi(argv[2]);
	
	if(service_client.call(srv))
	{

		ROS_INFO("The values that sent = %d %d",srv.request.a,srv.request.b);
		ROS_INFO("The response : %d",srv.response.resuld);	
	
	}
	else
	{
		ROS_ERROR("ERROR!!");
	return 1;		
	}

return 0;
}
