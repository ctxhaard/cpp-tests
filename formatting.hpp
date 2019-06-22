#pragma once

#include <string>
#include <spdlog/spdlog.h>

class Formatting
{
public:
    template<typename T>
    std::string format(const std::string& fmt, const T& val) const {
            return fmt::format(fmt, val);
    }
};

