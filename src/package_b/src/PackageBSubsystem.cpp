#include "package_b/PackageBSubsystem.hpp"
#include <iostream>

void PackageBSubsystem::display_message(const std::string & msg) {
  std::cout << "[Subsystem] Received message: " << msg << std::endl;
}

std::string PackageBSubsystem::process_logic() {
  return "Processed by Subsystem B";
}
