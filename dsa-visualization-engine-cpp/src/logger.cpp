#include "logger.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

using namespace std;

Logger::Logger(SpeedMode mode, bool color)
    : speed(mode), useColor(color) {}

void Logger::setSpeed(SpeedMode mode) {
    speed = mode;
}

string Logger::vecToString(const vector<int> &v) {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << v[i];
        if (i + 1 < v.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

void Logger::sleepForMode() const {
    using namespace chrono;
    switch (speed) {
        case SpeedMode::FAST:
            this_thread::sleep_for(milliseconds(60));
            break;
        case SpeedMode::NORMAL:
            this_thread::sleep_for(milliseconds(200));
            break;
        case SpeedMode::SLOW:
            this_thread::sleep_for(milliseconds(400));
            break;
        case SpeedMode::NONE:
        default:
            break;
    }
}

void Logger::logStep(const string &tag, const vector<int> &state) {
    static long long stepCount = 0;
    cout << "Step " << stepCount++ << ": " << tag
         << " -> " << vecToString(state) << "\n";
    cout.flush();
    sleepForMode();
}

void Logger::logMsg(const string &msg) {
    cout << msg << "\n";
    cout.flush();
    sleepForMode();
}