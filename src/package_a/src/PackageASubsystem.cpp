#include "package_a/PackageASubsystem.hpp"
#include <chrono>
#include <iostream>

std::string PackageASubsystem::generate_message() {
  return "Hello from Package A!";
}

void PackageASubsystem::handle_response(const std::string & result) {
  std::cout << "[Subsystem A] Received service response: " << result << std::endl;
}
