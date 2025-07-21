#include "rclcpp/rclcpp.hpp"
#include "package_b/PackageBNode.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PackageBNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
