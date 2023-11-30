#include <iostream>

#include "include/figures/Diamond.hpp"
#include "include/figures/Hexagon.hpp"
#include "include/figures/Pentagon.hpp"
#include "include/containers/Vector.hpp"
#include <cmath>
  
int main() {
    Diamond* t0 = new Diamond(Point(4, 4), Point(7, 2), Point(4, 0), Point(1, 2));
    Diamond* t1 = new Diamond(Point(3, 0), Point(0, -2), Point(-3, 0), Point(0, 2));
    Pentagon* s0 = new Pentagon(Point(0, 100), 
                                Point(std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5)),
                                Point(25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5)),
                                Point(-25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5)),
                                Point(-std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5)));
    Vector<Figure*> v = {t0, t1, s0};
    double area = 0;

    for (size_t i = 0; i < v.get_size(); ++i) {
        area += static_cast<double>(*v[i]);
    }

    std::cout << area << std::endl;
    delete t0;
    delete t1;
    delete s0;
}