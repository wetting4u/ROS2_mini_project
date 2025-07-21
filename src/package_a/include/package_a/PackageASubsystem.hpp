#pragma once

#include <string>

class PackageASubsystem {
public:
  std::string generate_message();
  void handle_response(const std::string & result);
};
