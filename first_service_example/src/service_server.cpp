#include<ros/ros.h>
#include<first_service_example/sum.h>




bool calculate(first_service_example::sum::Request &request,first_service_example::sum::Response &response)
{

response.resuld = request.a + request.b;
ROS_INFO("The values that sent : %d %d  ",request.a,request.b);
ROS_INFO("The value that calculated : %d",response.resuld);
return true;
}


int main(int argc , char **argv)
{

	ros::init(argc,argv,"service_server");
	ros::NodeHandle nh;
	
	ros::ServiceServer service_server = nh.advertiseService("summing",calculate);
	ROS_INFO("Service is ready!");
	ros::spin();
	
return 0;
}
