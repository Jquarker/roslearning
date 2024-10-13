#include "server/service.h"

#include "ros/ros.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "server_demo1");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("service", add);
    
    ros::spin();
    return 0;
}