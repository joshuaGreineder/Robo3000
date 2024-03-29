// Generated by gencpp from file ublox_msgs/NavHPPOSLLH.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_NAVHPPOSLLH_H
#define UBLOX_MSGS_MESSAGE_NAVHPPOSLLH_H


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
struct NavHPPOSLLH_
{
  typedef NavHPPOSLLH_<ContainerAllocator> Type;

  NavHPPOSLLH_()
    : version(0)
    , reserved1()
    , invalid_llh(0)
    , iTOW(0)
    , lon(0)
    , lat(0)
    , height(0)
    , hMSL(0)
    , lonHp(0)
    , latHp(0)
    , heightHp(0)
    , hMSLHp(0)
    , hAcc(0)
    , vAcc(0)  {
      reserved1.assign(0);
  }
  NavHPPOSLLH_(const ContainerAllocator& _alloc)
    : version(0)
    , reserved1()
    , invalid_llh(0)
    , iTOW(0)
    , lon(0)
    , lat(0)
    , height(0)
    , hMSL(0)
    , lonHp(0)
    , latHp(0)
    , heightHp(0)
    , hMSLHp(0)
    , hAcc(0)
    , vAcc(0)  {
  (void)_alloc;
      reserved1.assign(0);
  }



   typedef uint8_t _version_type;
  _version_type version;

   typedef boost::array<uint8_t, 2>  _reserved1_type;
  _reserved1_type reserved1;

   typedef int8_t _invalid_llh_type;
  _invalid_llh_type invalid_llh;

   typedef uint32_t _iTOW_type;
  _iTOW_type iTOW;

   typedef int32_t _lon_type;
  _lon_type lon;

   typedef int32_t _lat_type;
  _lat_type lat;

   typedef int32_t _height_type;
  _height_type height;

   typedef int32_t _hMSL_type;
  _hMSL_type hMSL;

   typedef int8_t _lonHp_type;
  _lonHp_type lonHp;

   typedef int8_t _latHp_type;
  _latHp_type latHp;

   typedef int8_t _heightHp_type;
  _heightHp_type heightHp;

   typedef int8_t _hMSLHp_type;
  _hMSLHp_type hMSLHp;

   typedef uint32_t _hAcc_type;
  _hAcc_type hAcc;

   typedef uint32_t _vAcc_type;
  _vAcc_type vAcc;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(CLASS_ID)
  #undef CLASS_ID
#endif
#if defined(_WIN32) && defined(MESSAGE_ID)
  #undef MESSAGE_ID
#endif

  enum {
    CLASS_ID = 1u,
    MESSAGE_ID = 20u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> const> ConstPtr;

}; // struct NavHPPOSLLH_

typedef ::ublox_msgs::NavHPPOSLLH_<std::allocator<void> > NavHPPOSLLH;

typedef boost::shared_ptr< ::ublox_msgs::NavHPPOSLLH > NavHPPOSLLHPtr;
typedef boost::shared_ptr< ::ublox_msgs::NavHPPOSLLH const> NavHPPOSLLHConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator1> & lhs, const ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator2> & rhs)
{
  return lhs.version == rhs.version &&
    lhs.reserved1 == rhs.reserved1 &&
    lhs.invalid_llh == rhs.invalid_llh &&
    lhs.iTOW == rhs.iTOW &&
    lhs.lon == rhs.lon &&
    lhs.lat == rhs.lat &&
    lhs.height == rhs.height &&
    lhs.hMSL == rhs.hMSL &&
    lhs.lonHp == rhs.lonHp &&
    lhs.latHp == rhs.latHp &&
    lhs.heightHp == rhs.heightHp &&
    lhs.hMSLHp == rhs.hMSLHp &&
    lhs.hAcc == rhs.hAcc &&
    lhs.vAcc == rhs.vAcc;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator1> & lhs, const ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9da6664837183254bd840fe05c8c1e4b";
  }

  static const char* value(const ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9da6664837183254ULL;
  static const uint64_t static_value2 = 0xbd840fe05c8c1e4bULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/NavHPPOSLLH";
  }

  static const char* value(const ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# NAV-HPPOSLLH (0x01 0x14)\n"
"# High Precision Geodetic Position Solution\n"
"#\n"
"# See important comments concerning validity of position given in section\n"
"# Navigation Output Filters.\n"
"# This message outputs the Geodetic position in the currently selected\n"
"# Ellipsoid. The default is the WGS84 Ellipsoid, but can be changed with the\n"
"# message CFG-DAT.\n"
"#\n"
"\n"
"uint8 CLASS_ID = 1\n"
"uint8 MESSAGE_ID = 20\n"
"\n"
"uint8 version\n"
"uint8[2] reserved1\n"
"int8 invalid_llh\n"
"\n"
"uint32 iTOW             # GPS Millisecond Time of Week [ms]\n"
"\n"
"int32 lon               # Longitude [deg / 1e-7]\n"
"int32 lat               # Latitude [deg / 1e-7]\n"
"int32 height            # Height above Ellipsoid [mm]\n"
"int32 hMSL              # Height above mean sea level [mm]\n"
"int8 lonHp              # Longitude [deg / 1e-9, range -99 to +99]\n"
"int8 latHp              # Latitude [deg / 1e-9, range -99 to +99]\n"
"int8 heightHp          # Height above Ellipsoid [mm / 0.1, range -9 to +9]\n"
"int8 hMSLHp            # Height above mean sea level [mm / 0.1, range -9 to +9]\n"
"uint32 hAcc             # Horizontal Accuracy Estimate [mm / 0.1]\n"
"uint32 vAcc             # Vertical Accuracy Estimate [mm / 0.1]\n"
;
  }

  static const char* value(const ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.version);
      stream.next(m.reserved1);
      stream.next(m.invalid_llh);
      stream.next(m.iTOW);
      stream.next(m.lon);
      stream.next(m.lat);
      stream.next(m.height);
      stream.next(m.hMSL);
      stream.next(m.lonHp);
      stream.next(m.latHp);
      stream.next(m.heightHp);
      stream.next(m.hMSLHp);
      stream.next(m.hAcc);
      stream.next(m.vAcc);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NavHPPOSLLH_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::NavHPPOSLLH_<ContainerAllocator>& v)
  {
    s << indent << "version: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.version);
    s << indent << "reserved1[]" << std::endl;
    for (size_t i = 0; i < v.reserved1.size(); ++i)
    {
      s << indent << "  reserved1[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.reserved1[i]);
    }
    s << indent << "invalid_llh: ";
    Printer<int8_t>::stream(s, indent + "  ", v.invalid_llh);
    s << indent << "iTOW: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.iTOW);
    s << indent << "lon: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lon);
    s << indent << "lat: ";
    Printer<int32_t>::stream(s, indent + "  ", v.lat);
    s << indent << "height: ";
    Printer<int32_t>::stream(s, indent + "  ", v.height);
    s << indent << "hMSL: ";
    Printer<int32_t>::stream(s, indent + "  ", v.hMSL);
    s << indent << "lonHp: ";
    Printer<int8_t>::stream(s, indent + "  ", v.lonHp);
    s << indent << "latHp: ";
    Printer<int8_t>::stream(s, indent + "  ", v.latHp);
    s << indent << "heightHp: ";
    Printer<int8_t>::stream(s, indent + "  ", v.heightHp);
    s << indent << "hMSLHp: ";
    Printer<int8_t>::stream(s, indent + "  ", v.hMSLHp);
    s << indent << "hAcc: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.hAcc);
    s << indent << "vAcc: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.vAcc);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_NAVHPPOSLLH_H
