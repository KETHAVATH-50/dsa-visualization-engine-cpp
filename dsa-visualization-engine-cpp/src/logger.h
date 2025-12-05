#pragma once
#include <string>
#include <vector>

enum class SpeedMode { FAST, NORMAL, SLOW, NONE };

class Logger {
public:
    Logger(SpeedMode mode = SpeedMode::NORMAL, bool color = true);
    void logStep(const std::string &tag, const std::vector<int> &state);
    void logMsg(const std::string &msg);
    void setSpeed(SpeedMode mode);
private:
    SpeedMode speed;
    bool useColor;
    void sleepForMode() const;
    static std::string vecToString(const std::vector<int> &v);
};