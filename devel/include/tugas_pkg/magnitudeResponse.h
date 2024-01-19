// Generated by gencpp from file tugas_pkg/magnitudeResponse.msg
// DO NOT EDIT!


#ifndef TUGAS_PKG_MESSAGE_MAGNITUDERESPONSE_H
#define TUGAS_PKG_MESSAGE_MAGNITUDERESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace tugas_pkg
{
template <class ContainerAllocator>
struct magnitudeResponse_
{
  typedef magnitudeResponse_<ContainerAllocator> Type;

  magnitudeResponse_()
    : magnitude(0.0)  {
    }
  magnitudeResponse_(const ContainerAllocator& _alloc)
    : magnitude(0.0)  {
  (void)_alloc;
    }



   typedef double _magnitude_type;
  _magnitude_type magnitude;





  typedef boost::shared_ptr< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct magnitudeResponse_

typedef ::tugas_pkg::magnitudeResponse_<std::allocator<void> > magnitudeResponse;

typedef boost::shared_ptr< ::tugas_pkg::magnitudeResponse > magnitudeResponsePtr;
typedef boost::shared_ptr< ::tugas_pkg::magnitudeResponse const> magnitudeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::tugas_pkg::magnitudeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::tugas_pkg::magnitudeResponse_<ContainerAllocator1> & lhs, const ::tugas_pkg::magnitudeResponse_<ContainerAllocator2> & rhs)
{
  return lhs.magnitude == rhs.magnitude;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::tugas_pkg::magnitudeResponse_<ContainerAllocator1> & lhs, const ::tugas_pkg::magnitudeResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace tugas_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f3a902f9783110e2b8fe7c475e26788e";
  }

  static const char* value(const ::tugas_pkg::magnitudeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf3a902f9783110e2ULL;
  static const uint64_t static_value2 = 0xb8fe7c475e26788eULL;
};

template<class ContainerAllocator>
struct DataType< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "tugas_pkg/magnitudeResponse";
  }

  static const char* value(const ::tugas_pkg::magnitudeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 magnitude\n"
"\n"
;
  }

  static const char* value(const ::tugas_pkg::magnitudeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.magnitude);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct magnitudeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::tugas_pkg::magnitudeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::tugas_pkg::magnitudeResponse_<ContainerAllocator>& v)
  {
    s << indent << "magnitude: ";
    Printer<double>::stream(s, indent + "  ", v.magnitude);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TUGAS_PKG_MESSAGE_MAGNITUDERESPONSE_H
