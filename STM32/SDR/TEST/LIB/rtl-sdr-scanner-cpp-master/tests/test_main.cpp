#include <logger.h>

#include "gtest/gtest.h"

int main(int argc, char **argv) {
  Logger::configure(spdlog::level::off, spdlog::level::off, "");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
