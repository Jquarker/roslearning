// Generated by gencpp from file topic/coordinate.msg
// DO NOT EDIT!


#ifndef TOPIC_MESSAGE_COORDINATE_H
#define TOPIC_MESSAGE_COORDINATE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace topic
{
template <class ContainerAllocator>
struct coordinate_
{
  typedef coordinate_<ContainerAllocator> Type;

  coordinate_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , frame_id()  {
    }
  coordinate_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , frame_id(_alloc)  {
  (void)_alloc;
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _z_type;
  _z_type z;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _frame_id_type;
  _frame_id_type frame_id;





  typedef boost::shared_ptr< ::topic::coordinate_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::topic::coordinate_<ContainerAllocator> const> ConstPtr;

}; // struct coordinate_

typedef ::topic::coordinate_<std::allocator<void> > coordinate;

typedef boost::shared_ptr< ::topic::coordinate > coordinatePtr;
typedef boost::shared_ptr< ::topic::coordinate const> coordinateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::topic::coordinate_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::topic::coordinate_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::topic::coordinate_<ContainerAllocator1> & lhs, const ::topic::coordinate_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z &&
    lhs.frame_id == rhs.frame_id;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::topic::coordinate_<ContainerAllocator1> & lhs, const ::topic::coordinate_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace topic

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::topic::coordinate_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::topic::coordinate_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::topic::coordinate_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::topic::coordinate_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::topic::coordinate_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::topic::coordinate_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::topic::coordinate_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9eb74a11328521b704f7a4f80f046db9";
  }

  static const char* value(const ::topic::coordinate_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9eb74a11328521b7ULL;
  static const uint64_t static_value2 = 0x04f7a4f80f046db9ULL;
};

template<class ContainerAllocator>
struct DataType< ::topic::coordinate_<ContainerAllocator> >
{
  static const char* value()
  {
    return "topic/coordinate";
  }

  static const char* value(const ::topic::coordinate_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::topic::coordinate_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 x\n"
"float32 y\n"
"float32 z\n"
"string frame_id\n"
;
  }

  static const char* value(const ::topic::coordinate_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::topic::coordinate_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.frame_id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct coordinate_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::topic::coordinate_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::topic::coordinate_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<float>::stream(s, indent + "  ", v.z);
    s << indent << "frame_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.frame_id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TOPIC_MESSAGE_COORDINATE_H