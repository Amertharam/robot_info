#include "robot_info_class.cpp"
#include "hydraulic_system_monitor.cpp"

class AGVRobotInfo : public RobotInfo {
private:
    std::string maximum_payload;
    HydraulicSystemMonitor *hydraulic_system_monitor_obj;

public:
    AGVRobotInfo(ros::NodeHandle& nh) : RobotInfo(nh) {  hydraulic_system_monitor_obj =  new HydraulicSystemMonitor();}

    void setMaximumPayload(const std::string& payload) { maximum_payload = payload; }
    HydraulicSystemMonitor& getHydraulicSystemMonitorObject() { return *hydraulic_system_monitor_obj; }

    void publish_data() override {
        robotinfo_msgs::RobotInfo msg;
        
        msg.data_field_01 = "robot_description: " + robot_description;
        msg.data_field_02 = "serial_number: " + serial_number;
        msg.data_field_03 = "ip_address: " + ip_address;
        msg.data_field_04 = "firmware_version: " + firmware_version;
        msg.data_field_05 = "maximum_payload: " + maximum_payload;
        msg.data_field_06 = "hydraulic_oil_temperature: " + hydraulic_system_monitor_obj->getHydraulicOilTemperature();
        msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + hydraulic_system_monitor_obj->getHydraulicOilTankFillLevel();
        msg.data_field_08 = "hydraulic_oil_pressure: " + hydraulic_system_monitor_obj->getHydraulicOilPressure();
        pub.publish(msg);
    }
};
