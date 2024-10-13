#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

// 头文件
// ROS节点
// 节点句柄
// 订阅者对象
// 订阅到的数据
// spin()函数

// 下面是subscribe的回调函数
void doMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("listener's data: %s",msg->data.c_str());
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle nh;
    ros::Subscriber listener = nh.subscribe("xy",1,doMsg);
    ros::spin();
    return 0;
}