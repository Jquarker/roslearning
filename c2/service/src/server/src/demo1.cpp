#include "ros/ros.h"
#include "std_srvs/Empty.h"

// Service callback function
bool handle_service_request(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res) {
    ROS_INFO("Service request received");
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "demo1_server");
    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("demo1_service", handle_service_request);
    ROS_INFO("Service server ready to receive requests.");

    ros::spin();

    return 0;
}