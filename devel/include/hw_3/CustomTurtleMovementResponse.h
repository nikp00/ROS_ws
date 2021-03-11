// Generated by gencpp from file hw_3/CustomTurtleMovementResponse.msg
// DO NOT EDIT!


#ifndef HW_3_MESSAGE_CUSTOMTURTLEMOVEMENTRESPONSE_H
#define HW_3_MESSAGE_CUSTOMTURTLEMOVEMENTRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace hw_3
{
template <class ContainerAllocator>
struct CustomTurtleMovementResponse_
{
  typedef CustomTurtleMovementResponse_<ContainerAllocator> Type;

  CustomTurtleMovementResponse_()
    : movementType()  {
    }
  CustomTurtleMovementResponse_(const ContainerAllocator& _alloc)
    : movementType(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _movementType_type;
  _movementType_type movementType;





  typedef boost::shared_ptr< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> const> ConstPtr;

}; // struct CustomTurtleMovementResponse_

typedef ::hw_3::CustomTurtleMovementResponse_<std::allocator<void> > CustomTurtleMovementResponse;

typedef boost::shared_ptr< ::hw_3::CustomTurtleMovementResponse > CustomTurtleMovementResponsePtr;
typedef boost::shared_ptr< ::hw_3::CustomTurtleMovementResponse const> CustomTurtleMovementResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator1> & lhs, const ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator2> & rhs)
{
  return lhs.movementType == rhs.movementType;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator1> & lhs, const ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace hw_3

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ac49684d4a5e21fbcd6d1912075a031f";
  }

  static const char* value(const ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xac49684d4a5e21fbULL;
  static const uint64_t static_value2 = 0xcd6d1912075a031fULL;
};

template<class ContainerAllocator>
struct DataType< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hw_3/CustomTurtleMovementResponse";
  }

  static const char* value(const ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string movementType\n"
;
  }

  static const char* value(const ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.movementType);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CustomTurtleMovementResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hw_3::CustomTurtleMovementResponse_<ContainerAllocator>& v)
  {
    s << indent << "movementType: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.movementType);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HW_3_MESSAGE_CUSTOMTURTLEMOVEMENTRESPONSE_H