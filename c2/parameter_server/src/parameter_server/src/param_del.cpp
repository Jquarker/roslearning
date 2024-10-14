#include "ros/ros.h"

/*
    演示参数删除
    实现
        1. ros::param::del
        2. ros::NodeHandle::deleteParam
*/

int main(int argc,char *argv[])
{
    ros::init(argc,argv,"del_param");
    ros::NodeHandle nh;

    //ros::param::del
    bool result_d = ros::param::del("radius");
    if(result_d)
    {
        ROS_INFO("ros::param::del 'radius' success");
    }
    else
    {
        ROS_ERROR("ros::param::del 'radius' failed");
    }

    //ros::NodeHandle::deleteParam
    bool result_d_p = nh.deleteParam("radius");
    if(result_d_p)
    {
        ROS_INFO("ros::NodeHandle::deleteParam 'radius' success");
    }
    else
    {
        ROS_ERROR("ros::NodeHandle::deleteParam 'radius' failed");
    }
    return 0;
}
