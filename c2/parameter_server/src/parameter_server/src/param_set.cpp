#include"ros/ros.h"

/*实现参数的新增和修改
  需求：
    设置机器人的共享参数(类型，半径)
    修改半径
  实现：
    1. ros::NodeHandle::setParam()
    2. ros::param  set()
 * 
 */

int main(int argc,char* argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_set");
    ros::NodeHandle nh;
    // 新增参数
    //1. nh
    nh.setParam("type","sentory1");
    nh.setParam("radius",20);
    //2.ros::param
    ros::param::set("type_param","sentory2");
    ros::param::set("radius_param",20);
    // 修改参数
    //即重新使用函数对上文参数进行覆盖
    nh.setParam("radius",30);
    ros::param::set("radius_paeram",30);
    ros::spin();
    return 0;
}

