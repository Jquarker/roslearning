import rospy
from geometry_msgs.msg import Twist


def callback(data):
    rospy.loginfo(Twist.angular.x)


def get_direction_vector():
    rospy.init_node('get_direction_vector', anonymous=True)
    rospy.Subscriber("/cmd_vel", Twist, callback)
    rospy.spin()


if __name__ == '__main__':
    try:
        get_direction_vector()
    except rospy.ROSInterruptException:
        pass
