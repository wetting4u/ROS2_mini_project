#pragma once

#include "rclcpp/rclcpp.hpp"
#include "package_a/PackageASubsystem.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/trigger.hpp"

class PackageANode : public rclcpp::Node {
public:
  PackageANode();

private:
  std::shared_ptr<PackageASubsystem> subsystem_;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;

  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr client_;
  rclcpp::TimerBase::SharedPtr service_timer_;

  void publish_message();
  void call_service();
};
