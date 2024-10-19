#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/jquark/ROS/c6/gazebo/src/arbotix_ros/arbotix_sensors"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/jquark/ROS/c6/gazebo/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/jquark/ROS/c6/gazebo/install/lib/python3/dist-packages:/home/jquark/ROS/c6/gazebo/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/jquark/ROS/c6/gazebo/build" \
    "/usr/bin/python3" \
    "/home/jquark/ROS/c6/gazebo/src/arbotix_ros/arbotix_sensors/setup.py" \
     \
    build --build-base "/home/jquark/ROS/c6/gazebo/build/arbotix_ros/arbotix_sensors" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/jquark/ROS/c6/gazebo/install" --install-scripts="/home/jquark/ROS/c6/gazebo/install/bin"
