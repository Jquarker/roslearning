#include "ros/ros.h"
#include "server/addInt.h"
/*
    客户端实现：提交两个整数，并处理响应结果
    1.包含头文件
    2.初始化ros节点
    3.创建ros节点句柄
    4.创建一个客户端对象
    5.提交请求并处理响应
    6.spin一次

    参数的动态提交：    
    1.格式：rosrun 包名 节点名 参数值1 参数值2
    2.节点执行时，会自动读取命令中的参数，并组织进request中 
*/
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        ROS_INFO("提交的参数个数不对");
        return 1;
    }
    setlocale(LC_ALL, "");
    // 2.初始化ros节点
    ros::init(argc, argv, "client_demo1");  
    // 3.创建ros节点句柄
    ros::NodeHandle nh;
    // 4.创建一个客户端对象
    ros::ServiceClient client = nh.serviceClient<server::addInt>("addInt");
    // 5.提交请求并处理响应
    server::addInt ai;
    ai.request.a = atoi(argv[1]); // 提交数据
    ai.request.b = atoi(argv[2]); // 提交数据
    bool flag = client.call(ai); // 发送请求
    if (flag)
    {
        ROS_INFO("响应成功：%d", ai.response.sum); // 处理响应  
    }
    else
    {
        ROS_INFO("响应失败");
    }
    // 6.spin一次
    ros::spinOnce();
    return 0;
}   