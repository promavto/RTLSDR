#pragma once

#include <performance_logger.h>
#include <radio/help_structures.h>
#include <ring_buffer.h>

#include <boost/circular_buffer.hpp>
#include <condition_variable>
#include <cstdint>
#include <functional>
#include <mutex>

class SdrDevice {
 public:
  struct Samples {
    std::chrono::milliseconds time;
    std::vector<uint8_t> data;
  };

  SdrDevice(const std::string& name);
  virtual ~SdrDevice() = default;

  virtual SdrDevice::Samples readData(const FrequencyRange& frequencyRange) = 0;

  virtual void startStream(const FrequencyRange& frequencyRange) = 0;
  virtual void stopStream() = 0;
  void waitForData();
  bool isDataAvailable();
  Samples getStreamData();

  virtual std::string name() const = 0;
  virtual std::string serial() const = 0;
  virtual int32_t offset() const = 0;

 protected:
  uint32_t m_samplesSize;
  uint32_t m_readSize;
  PerformanceLogger m_performanceLogger;
  RingBuffer m_dataBuffer;
  boost::circular_buffer<std::chrono::milliseconds> m_timeBuffer;
  std::mutex m_mutex;
  std::condition_variable m_cv;
};
