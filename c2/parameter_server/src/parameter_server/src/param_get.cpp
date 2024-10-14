#include "ros/ros.h"

/*
    演示参数查询
    需求：演示参数查询的几种方式
    1. 使用ros::NodeHandle查询
    2. 使用ros::param查询   
*/

int main(int argc,char* argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_get");
    
    ros::NodeHandle nh;
    
    return 0;
}
