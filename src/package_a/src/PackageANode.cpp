#include "package_a/PackageANode.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/trigger.hpp"

#include <chrono>
#include <memory>

using namespace std::chrono_literals;

PackageANode::PackageANode() : Node("package_a_node") {
  subsystem_ = std::make_shared<PackageASubsystem>();

  // Publisher
  publisher_ = this->create_publisher<std_msgs::msg::String>("data_topic", 10);
  timer_ = this->create_wall_timer(
    1000ms, std::bind(&PackageANode::publish_message, this));

  // Service client
  client_ = this->create_client<std_srvs::srv::Trigger>("process_data");

  // Try to wait for the service to be available
  while (!client_->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service.");
      return;
    }
    RCLCPP_INFO(this->get_logger(), "Waiting for service...");
  }

  // Call service every 3 seconds
  service_timer_ = this->create_wall_timer(
    3000ms, std::bind(&PackageANode::call_service, this));

  RCLCPP_INFO(this->get_logger(), "Package A Node started.");
}

void PackageANode::publish_message() {
  std_msgs::msg::String msg;
  msg.data = subsystem_->generate_message();
  publisher_->publish(msg);
  RCLCPP_INFO(this->get_logger(), "Published: %s", msg.data.c_str());
}

void PackageANode::call_service() {
  auto request = std::make_shared<std_srvs::srv::Trigger::Request>();

  auto future = client_->async_send_request(request,
    [this](rclcpp::Client<std_srvs::srv::Trigger>::SharedFuture future_response) {
      auto response = future_response.get();
      if (response->success) {
        subsystem_->handle_response(response->message);
      } else {
        RCLCPP_WARN(this->get_logger(), "Service call failed.");
      }
    });
}
