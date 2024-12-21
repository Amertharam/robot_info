#include "robot_info_class.cpp"

int main(int argc, char** argv) {
    ros::init(argc, argv, "robot_info_node");
    ros::NodeHandle nh;

    RobotInfo robot_info(nh);
    robot_info.setRobotDescription("BrandX");
    robot_info.setSerialNumber("123ABC");
    robot_info.setIpAddress("192.168.1.1");
    robot_info.setFirmwareVersion("1.0.0");

    ros::Rate rate(1); // 1 Hz
    while (ros::ok()) {
        robot_info.publish_data();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
