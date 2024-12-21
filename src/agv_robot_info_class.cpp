#include "robot_info_class.cpp"

class AGVRobotInfo : public RobotInfo {
private:
    std::string maximum_payload;

public:
    AGVRobotInfo(ros::NodeHandle& nh) : RobotInfo(nh) {}

    void setMaximumPayload(const std::string& payload) { maximum_payload = payload; }

    void publish_data() override {
        robotinfo_msgs::RobotInfo msg;
        msg.data_field_01 = "robot_description: " + robot_description;
        msg.data_field_02 = "serial_number: " + serial_number;
        msg.data_field_03 = "ip_address: " + ip_address;
        msg.data_field_04 = "firmware_version: " + firmware_version;
        msg.data_field_05 = "maximum_payload: " + maximum_payload;
        pub.publish(msg);
    }
};
