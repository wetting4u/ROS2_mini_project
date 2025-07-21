#include "rclcpp/rclcpp.hpp"
#include "package_a/PackageANode.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PackageANode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
