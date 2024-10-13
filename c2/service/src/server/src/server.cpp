#include "server/addInt.h"
/*
服务端实现：解析客户端提交的数据，并运算后返回
    1.包含头文件
    2.初始化ros节点
    3.创建ros节点句柄
    4.创建一个服务端对象
    5.处理请求并调用回调函数
    6.循环等待回调函数
*/
#include "ros/ros.h"

// 实现回调函数
bool add(server::addInt::Request &request, server::addInt::Response &response)
{
    int sum = request.a + request.b;
    response.sum = sum;
    ROS_INFO("服务器端解析的数据a = %d, b = %d, 响应结果sum = %d", request.a, request.b, response.sum);
    ROS_INFO("结果为：%d", response.sum);
    return true;
}   

int main(int argc, char *argv[])
{
    // 1.设置编码
    setlocale(LC_ALL, "");
    // 2.初始化ros节点
    ros::init(argc, argv, "server_demo1");
    // 3.创建ros节点句柄
    ros::NodeHandle nh;
    // 4.创建一个服务端对象
    ros::ServiceServer server = nh.advertiseService("addInt", add);
    // 5.处理请求并调用回调函数
    ROS_INFO("服务已经启动....");   
    // 6.循环等待回调函数
    ros::spin();
    return 0;
}