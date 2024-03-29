// Generated by gencpp from file ublox_msgs/NavHPPOSECEF.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_NAVHPPOSECEF_H
#define UBLOX_MSGS_MESSAGE_NAVHPPOSECEF_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ublox_msgs
{
template <class ContainerAllocator>
struct NavHPPOSECEF_
{
  typedef NavHPPOSECEF_<ContainerAllocator> Type;

  NavHPPOSECEF_()
    : version(0)
    , reserved0()
    , iTOW(0)
    , ecefX(0)
    , ecefY(0)
    , ecefZ(0)
    , ecefXHp(0)
    , ecefYHp(0)
    , ecefZHp(0)
    , flags(0)
    , pAcc(0)  {
      reserved0.assign(0);
  }
  NavHPPOSECEF_(const ContainerAllocator& _alloc)
    : version(0)
    , reserved0()
    , iTOW(0)
    , ecefX(0)
    , ecefY(0)
    , ecefZ(0)
    , ecefXHp(0)
    , ecefYHp(0)
    , ecefZHp(0)
    , flags(0)
    , pAcc(0)  {
  (void)_alloc;
      reserved0.assign(0);
  }



   typedef uint8_t _version_type;
  _version_type version;

   typedef boost::array<uint8_t, 3>  _reserved0_type;
  _reserved0_type reserved0;

   typedef uint32_t _iTOW_type;
  _iTOW_type iTOW;

   typedef int32_t _ecefX_type;
  _ecefX_type ecefX;

   typedef int32_t _ecefY_type;
  _ecefY_type ecefY;

   typedef int32_t _ecefZ_type;
  _ecefZ_type ecefZ;

   typedef int8_t _ecefXHp_type;
  _ecefXHp_type ecefXHp;

   typedef int8_t _ecefYHp_type;
  _ecefYHp_type ecefYHp;

   typedef int8_t _ecefZHp_type;
  _ecefZHp_type ecefZHp;

   typedef uint8_t _flags_type;
  _flags_type flags;

   typedef uint32_t _pAcc_type;
  _pAcc_type pAcc;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(CLASS_ID)
  #undef CLASS_ID
#endif
#if defined(_WIN32) && defined(MESSAGE_ID)
  #undef MESSAGE_ID
#endif

  enum {
    CLASS_ID = 1u,
    MESSAGE_ID = 19u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> const> ConstPtr;

}; // struct NavHPPOSECEF_

typedef ::ublox_msgs::NavHPPOSECEF_<std::allocator<void> > NavHPPOSECEF;

typedef boost::shared_ptr< ::ublox_msgs::NavHPPOSECEF > NavHPPOSECEFPtr;
typedef boost::shared_ptr< ::ublox_msgs::NavHPPOSECEF const> NavHPPOSECEFConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator1> & lhs, const ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator2> & rhs)
{
  return lhs.version == rhs.version &&
    lhs.reserved0 == rhs.reserved0 &&
    lhs.iTOW == rhs.iTOW &&
    lhs.ecefX == rhs.ecefX &&
    lhs.ecefY == rhs.ecefY &&
    lhs.ecefZ == rhs.ecefZ &&
    lhs.ecefXHp == rhs.ecefXHp &&
    lhs.ecefYHp == rhs.ecefYHp &&
    lhs.ecefZHp == rhs.ecefZHp &&
    lhs.flags == rhs.flags &&
    lhs.pAcc == rhs.pAcc;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator1> & lhs, const ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> >
{
  static const char* value()
  {
    return "41fbf0937e53f84ca89afe3287f85e50";
  }

  static const char* value(const ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x41fbf0937e53f84cULL;
  static const uint64_t static_value2 = 0xa89afe3287f85e50ULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/NavHPPOSECEF";
  }

  static const char* value(const ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# NAV-HPPOSECEF (0x01 0x13)\n"
"# High Precision Position Solution in ECEF\n"
"#\n"
"# See important comments concerning validity of position given in section\n"
"# Navigation Output Filters.\n"
"#\n"
"\n"
"uint8 CLASS_ID = 1\n"
"uint8 MESSAGE_ID = 19\n"
"\n"
"uint8 version\n"
"uint8[3] reserved0\n"
"\n"
"uint32 iTOW             # GPS Millisecond Time of Week [ms]\n"
"\n"
"int32 ecefX             # ECEF X coordinate [cm]\n"
"int32 ecefY             # ECEF Y coordinate [cm]\n"
"int32 ecefZ             # ECEF Z coordinate [cm]\n"
"\n"
"int8 ecefXHp            # ECEF X high precision component [0.1mm]\n"
"int8 ecefYHp            # ECEF Y high precision component [0.1mm]\n"
"int8 ecefZHp            # ECEF Z high precision component [0.1mm]\n"
"uint8 flags\n"
"\n"
"uint32 pAcc             # Position Accuracy Estimate [0.1mm]\n"
;
  }

  static const char* value(const ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.version);
      stream.next(m.reserved0);
      stream.next(m.iTOW);
      stream.next(m.ecefX);
      stream.next(m.ecefY);
      stream.next(m.ecefZ);
      stream.next(m.ecefXHp);
      stream.next(m.ecefYHp);
      stream.next(m.ecefZHp);
      stream.next(m.flags);
      stream.next(m.pAcc);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NavHPPOSECEF_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::NavHPPOSECEF_<ContainerAllocator>& v)
  {
    s << indent << "version: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.version);
    s << indent << "reserved0[]" << std::endl;
    for (size_t i = 0; i < v.reserved0.size(); ++i)
    {
      s << indent << "  reserved0[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.reserved0[i]);
    }
    s << indent << "iTOW: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.iTOW);
    s << indent << "ecefX: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ecefX);
    s << indent << "ecefY: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ecefY);
    s << indent << "ecefZ: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ecefZ);
    s << indent << "ecefXHp: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ecefXHp);
    s << indent << "ecefYHp: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ecefYHp);
    s << indent << "ecefZHp: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ecefZHp);
    s << indent << "flags: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.flags);
    s << indent << "pAcc: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.pAcc);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_NAVHPPOSECEF_H
