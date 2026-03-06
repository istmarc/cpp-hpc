#ifndef CPP_HPC_TIMER
#define CPP_HPC_TIMER

#include <chrono>

class Timer {
private:
  using time_t = std::chrono::time_point<std::chrono::system_clock>;

public:
  Timer() : startTime(), stopTime() {}

  time_t start() { return (startTime = std::chrono::system_clock::now()); }
  time_t stop() { return (stopTime = std::chrono::system_clock::now()); }

  double elapased() {
    return std::chrono::duration_cast<std::chrono::microseconds>(stopTime -
                                                                 startTime)
        .count();
  }

private:
  time_t startTime;
  time_t stopTime;
};

#endif
