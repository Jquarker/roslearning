#include "topic/coordinate.h"
#include "ros/ros.h"

void doMsg(const topic::coordinate::ConstPtr& msg_p)
{
    ROS_INFO("订阅到的数据：x=%.2f, y=%.2f, z=%.2f, frame_id=%s", 
             msg_p->x, msg_p->y, msg_p->z, msg_p->frame_id.c_str());
}
// 回调函数处理订阅的消息

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化ROS节点
    ros::init(argc, argv, "listener_demo02");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建订阅者对象
    ros::Subscriber sub = nh.subscribe<topic::coordinate>("coordinate", 10, doMsg);
    // 5.处理订阅的消息
    ros::spin();
    return 0;
}   