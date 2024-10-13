#include "ros/ros.h"
#include "topic/coordinate.h"
/*
    发布方：发布坐标系信息
    1.包含头文件
    2.初始化ros节点
    3.创建节点句柄
    4.创建发布者对象
    5.编写发布逻辑并发布数据
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化ros节点
    ros::init(argc, argv, "talker_demo02");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建发布者对象 
    ros::Publisher pub = nh.advertise<topic::coordinate>("coordinate", 10); 
    // 5.编写发布逻辑并发布数据
    topic::coordinate coordinate;

    coordinate.x = 1.0;
    coordinate.y = 2.0;
    coordinate.z = 3.0;
    coordinate.frame_id = "base_link";      
    // 循环发布
    ros::Rate rate(1);  // 1Hz的发布频率
    while (ros::ok())
    {
        coordinate.x += 0.1;
        //核心 发布消息
        pub.publish(coordinate);
        rate.sleep();
        // 日志输出
        ROS_INFO("发布的坐标：x=%.2f, y=%.2f, z=%.2f, frame_id=%s", 
                 coordinate.x, coordinate.y, coordinate.z, coordinate.frame_id.c_str());
        ros::spinOnce();//回头函数
    }
    return 0;
}