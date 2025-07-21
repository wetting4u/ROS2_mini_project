#pragma once

#include "rclcpp/rclcpp.hpp"
#include "package_b/PackageBSubsystem.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/trigger.hpp"

class PackageBNode : public rclcpp::Node {
public:
  PackageBNode();

private:
  std::shared_ptr<PackageBSubsystem> subsystem_;

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr service_;

  void topic_callback(const std_msgs::msg::String::SharedPtr msg);
  void handle_service(
    const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
    std::shared_ptr<std_srvs::srv::Trigger::Response> response);
};
