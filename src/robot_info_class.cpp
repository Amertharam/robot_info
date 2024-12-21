#include "ros/ros.h"
#include "robotinfo_msgs/RobotInfo.h"

class RobotInfo {
protected:
    std::string robot_description;
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;
    ros::Publisher pub;

public:
    RobotInfo(ros::NodeHandle& nh) {
        pub = nh.advertise<robotinfo_msgs::RobotInfo>("robot_info", 10);
    }

    void setRobotDescription(const std::string& description) { robot_description = description; }
    void setSerialNumber(const std::string& serial) { serial_number = serial; }
    void setIpAddress(const std::string& ip) { ip_address = ip; }
    void setFirmwareVersion(const std::string& version) { firmware_version = version; }

    virtual void publish_data() {
      robotinfo_msgs::RobotInfo msg;
      msg.data_field_01 = "robot_description: " + robot_description;
      msg.data_field_02 = "serial_number: " + serial_number;
      msg.data_field_03 = "ip_address: " + ip_address;
      msg.data_field_04 = "firmware_version: " + firmware_version;
      pub.publish(msg);
    }
};
