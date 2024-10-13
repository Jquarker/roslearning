#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //执行节点初始化
    ros::init(argc,argv,"hellovscode");
    //输出日志
    ROS_INFO("Hello vscode");
    return 0;
}