#pragma once

#include <chrono>
#include <string>

class PerformanceLogger {
 public:
  PerformanceLogger(const std::string& name);
  void newSample();

 private:
  const std::string m_name;
  uint64_t m_samplesCount;
  std::chrono::milliseconds m_lastLog;
};
