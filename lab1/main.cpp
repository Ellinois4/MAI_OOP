#include "include/solution.hpp"
#include <iostream>

int main() {
    int32_t hour{};
    int32_t minute{};
    std::string period{};

    std::cin >> hour >> minute >> period;
    std::string new_format = lab1::change_hour_format(hour, minute, period);

    std::cout << new_format << '\n';

    return 0;
}