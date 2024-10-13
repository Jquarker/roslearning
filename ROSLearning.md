# ROS c1基础知识

## 工作空间
创建工作空间  

     mkdir -p *name*/src  
     cd *name*  
     catkin_make  

创建功能包  

     cd src  
     catkin_create_pkg helloworld [roscpp rospy std_msgs]

编辑cpp和CMake  

     add_executable(步骤3的源文件名
     src/步骤3的源文件名.cpp
     )
     target_link_libraries(步骤3的源文件名
     ${catkin_LIBRARIES}
     )

## 工作空间目录

     .
     ├── build
     ├── build_isolated
     ├── devel
     ├── devel_isolated
     └── src
          ├── CMakeLists.txt -> /opt/ros/noetic/share/catkin/cmake/toplevel.cmake
          └── vscodetest (msg,srv,action通信格式)
               ├── CMakeLists.txt
               ├── include
               ├── launch
                    └──turtleall.launch
               ├── package.xml
               └── src
                    └──vscodetest.cpp

package.xml 软件包的属性
CMakeLists.txt 

## vscode

## launch
启动多个ros节点  
.launch文件  

     <launch>
         <node pkg="helloworld" type="demo_hello" name="hello" output="screen" />
         <node pkg="turtlesim" type="turtlesim_node" name="t1"/>
         <node pkg="turtlesim" type="turtle_teleop_key" name="key1" />
     </launch>
- node ---> 包含的某个节点
- pkg -----> 功能包
- type ----> 被运行的节点文件
- name --> 为节点命名
- output-> 设置日志的输出目标  

## ROS命令
增  

     catkin_create_pkg  catkin_create_pkg 自定义包名 依赖包  创建新的ROS功能包  
     sudo apt install  安装 ROS功能包

删  

     sudo apt purge 包名  删除某个功能包

查  

     rospack list  列出所有功能包

     rospack find 包名  查找某个功能包是否存在，如果存在返回安装路径

     roscd 包名  进入某个功能包

     rosls 包名  列出某个包下的文件

     apt search 包名  搜索某个功能包

改  

     rosed 包名 文件名  修改功能包文件  

执行

     roscore [-p xxxx]
     rosrun 包名 可执行文件名
     roslaunch 报名 .launch
## 计量图
rqt_graph
rosrun rqt_graph rqt_graph   


# ROS c2通信机制
话题通信(发布订阅) 服务通信(请求相应) 参数服务器(参数共享)

修改xml文件和cmakelist
1. xml
     - <build_export_depend>message_runtime</build_export_depend>
     - <build_depend>message_generation</build_depend>
     - <exec_depend>message_runtime</exec_depend>

2. cmakelist
     - add_*_files //通行类型文件
     - generation_messages //生成ros消息、动作和服务
     - catkin_package //ros依赖包
     - include_directories //包含头文件(类似.vscode中c_cpp_propreties)
     - add_executable //程序生成的名字
     - add_dependencies //确保必要的消息服务和动作已生成
     - target_link_libraries //链接动态库

## 话题通信
master管理者 talker发布者 listener订阅者
talker(topic+foo)和listener(topic)借助master进行连接，后续talker和listener直接联系，并有RCP地址联系转为TCP地址联系  
注意talker listener data  

发布方实现->订阅方实现->配置实现->编译执行

     头文件 std_msgs/String.h
     初始化ros节点
     创建节点句柄
     创建talker
     发布逻辑与数据

roscore
source ./devel/setup.zsh  
rosrun topic talker_demo1

命令验证 rostopic echo 话题名称

setlocale(LC_ALL,"") 避免中文乱码

参照c2 笔记(代码)

拓展 sstream头文件 实现字符串的拼接

### 自定义msg
数据类型 int float string string time,duration 其他msg文件 数组
*.msg 

#### 注意
数据丢失 在roscore注册完成前发送数据导致数据丢失(注册后加入sleep)

## 服务通信

- master管理者(平台，中间商)
- server服务端(服务提供者)
- client客户端(服务获得者)

- 客户端发起请求时服务端已经启动
- 客户端和服务端都可以存在多个

server和client
### 自定义srv
服务通信中，数据分成两部分，请求与响应，在 srv 文件中请求和响应使用---分割
服务通信的回调函数是bool类型，处理成功与失败



调用时 source->rosrun->source->rosservice