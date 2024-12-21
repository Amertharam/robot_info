#include "robotinfo_msgs/RobotInfo.h"
#include "ros/ros.h"
#include <string>

class HydraulicSystemMonitor {
private:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;

public:
  HydraulicSystemMonitor() {}

  void setHydraulicOilTemperature(const std::string &temperature) {
    hydraulic_oil_temperature = temperature;
  }
  void setHydraulicOilTankFillLevel(const std::string &level) {
    hydraulic_oil_tank_fill_level = level;
  }
  void setHydraulicOilPressure(const std::string &pressure) {
    hydraulic_oil_pressure = pressure;
  }

  std::string getHydraulicOilTemperature() { return hydraulic_oil_temperature; }
  std::string getHydraulicOilTankFillLevel() { return hydraulic_oil_tank_fill_level; }
  std::string getHydraulicOilPressure() { return hydraulic_oil_pressure; }
};
