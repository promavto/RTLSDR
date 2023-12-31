#pragma once

#include <algorithms/decimator.h>
#include <algorithms/signal_mediator.h>
#include <algorithms/transmission_detector.h>
#include <network/data_controller.h>
#include <performance_logger.h>
#include <radio/recorder_worker.h>
#include <radio/samples_processor.h>
#include <utils.h>

#include <complex>
#include <condition_variable>
#include <deque>
#include <map>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

class Recorder {
 public:
  Recorder(const Config& config, int32_t offset, DataController& dataController);
  ~Recorder();

  void clear();
  bool isTransmission(const std::chrono::milliseconds& time, const FrequencyRange& frequencyRange, std::vector<uint8_t>&& samples);
  bool isTransmissionInProgress() const;
  void processSamples(const std::chrono::milliseconds& time, const FrequencyRange& frequencyRange, std::vector<uint8_t>&& samples);

 private:
  void processSignals(const std::chrono::milliseconds& time, const FrequencyRange& frequencyRange, const std::vector<Signal>& signals);
  const Config& m_config;
  const int32_t m_offset;
  DataController& m_dataController;
  TransmissionDetector m_transmissionDetector;
  SamplesProcessor m_samplesProcessor;
  PerformanceLogger m_performanceLogger;
  std::vector<std::complex<float>> m_rawBuffer;
  std::chrono::milliseconds m_lastDataTime;
  std::chrono::milliseconds m_lastActiveDataTime;

  struct RecorderInputSamples {
    std::chrono::milliseconds time;
    std::vector<uint8_t> samples;
    FrequencyRange frequencyRange;
  };

  struct RecorderWorkerStruct {
    std::deque<WorkerInputSamples> samples;
    std::condition_variable cv;
    std::mutex mutex;
    std::unique_ptr<RecorderWorker> worker;
  };

  std::map<FrequencyRange, std::unique_ptr<RecorderWorkerStruct>> m_workers;
  std::map<FrequencyRange, std::unique_ptr<SignalMediator>> m_signalMediators;
};
