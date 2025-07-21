#include "package_b/PackageBNode.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/trigger.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

PackageBNode::PackageBNode() : Node("package_b_node") {
  subsystem_ = std::make_shared<PackageBSubsystem>();

  // Subscriber: listens to data_topic
  subscription_ = this->create_subscription<std_msgs::msg::String>(
    "data_topic", 10,
    std::bind(&PackageBNode::topic_callback, this, _1)
  );

  // Service: handles process_data
  service_ = this->create_service<std_srvs::srv::Trigger>(
    "process_data",
    std::bind(&PackageBNode::handle_service, this, _1, _2)
  );

  RCLCPP_INFO(this->get_logger(), "Package B Node started.");
}

void PackageBNode::topic_callback(const std_msgs::msg::String::SharedPtr msg) {
  subsystem_->display_message(msg->data);
}

void PackageBNode::handle_service(
  const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
  std::shared_ptr<std_srvs::srv::Trigger::Response> response
) {
  (void)request; // not used
  std::string result = subsystem_->process_logic();
  response->success = true;
  response->message = result;

  RCLCPP_INFO(this->get_logger(), "Handled service request. Sent back: %s", result.c_str());
}
