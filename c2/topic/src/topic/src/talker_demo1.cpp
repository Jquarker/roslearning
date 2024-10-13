#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
// 头文件 std_msgs/String.h
// 初始化ros节点
// 创建节点句柄
// 创建talker
// 发布逻辑与数据

int main(int argc,char *argv[])
{
    ros::init(argc,argv,"nuc");

    ros::NodeHandle nh;

    ros::Publisher talker = nh.advertise<std_msgs::String>("xy",10);
// 发布逻辑和数据
    std_msgs::String msg; //中文输出乱码解决
    ros::Rate rate(1);//表示10Hz
    int i = 1;
    ros::Duration(3).sleep();
    while(ros::ok())
    {
        setlocale(LC_ALL,"");
        // msg.data = "(1,1)";
        std::stringstream ss;
        ss << "(1,1) " << i;
        msg.data=ss.str();
        talker.publish(msg);
        ROS_INFO("DATA: %s ",ss.str().c_str());
        rate.sleep();
        i++;
        // ros::spinOnce(); //处理回调函数
    }

    return 0;
}