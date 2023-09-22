#include "../include/solution.hpp"

std::string lab1::change_hour_format(int32_t hour, const int32_t minute, const std::string& period) {
    std::string hours{};
    std::string minutes{};

    if (period == "pm") {
        if (hour == 12) {
            hour = 0;

        } else {
            hour += 12;
        }
    }

    if (hour < 10) {
        hours = "0";
    }

    hours += std::to_string(hour);

    if (minute < 10) {
        minutes = "0";
    }
    
    minutes += std::to_string(minute);

    return hours + minutes; 
}
