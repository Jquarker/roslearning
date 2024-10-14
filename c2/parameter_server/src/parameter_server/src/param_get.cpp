#include "ros/ros.h"
#include <vector>
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
    //1.ros::NodeHandle查询
    //1.param实现
    double radius = nh.param("radius",0.32);
    ROS_INFO("radius = %lf",radius);
    //2.get实现
    double radius_b = 0;
    //getParamCached 性能比getParam高   
    // 如果参数不存在，则返回false    
    //3.getParam实现
    bool result_b = nh.getParam("radiusyyy",radius_b);
    if(result_b)
    {
        ROS_INFO("radius_b = %lf",radius_b);
    }
    else
    {
        ROS_ERROR("Failed to get param 'radius'");
    }
    //getParamCached实现
    bool result_b_cached = nh.getParamCached("radiusyyy",radius_b);
    if(result_b_cached)
    {
        ROS_INFO("radius_b_cached = %lf",radius_b);
    }
    else
    {
        ROS_ERROR("Failed to get param 'radius'");
    }   
    //4.getParamNames实现
    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &&name : names)
    {
        ROS_INFO("getParamNames name = %s",name.c_str());
    }

    //5.hasParam实现
    bool result_c = nh.hasParam("radius");
    bool result_d = nh.hasParam("radiusyyy");
    if(result_c)
    {
        ROS_INFO("has param 'radius'");
    }
    else
    {
        ROS_ERROR("has no param 'radius'");
    }
    if(result_d)
    {
        ROS_INFO("has param 'radiusyyy'");
    }
    else
    {
        ROS_ERROR("has no param 'radiusyyy'");
    }
 
    //6.searchParam实现
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("searchParam key = %s",key.c_str());
    nh.searchParam("radiusyyy",key);
    ROS_INFO("searchParam key = %s",key.c_str());


    //ros::param实现
    double radius_c = ros::param::param("radius",0.1);
    ROS_INFO("radius_c = %lf",radius_c);

    std::vector<std::string> names_c;
    ros::param::getParamNames(names_c);
    for(auto &&name : names_c)
    {
        ROS_INFO("ros::param::getParamNames name = %s",name.c_str());//转换为c风格字符串
    }

    return 0;
}
