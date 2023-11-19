#include <iostream>

#include "include/figures/Diamond.hpp"
#include "include/figures/Hexagon.hpp"
#include "include/figures/Pentagon.hpp"
#include "include/containers/Vector.hpp"
#include "include/figures/Point.hpp"
#include "include/functions.hpp"
#include <cmath>
#include <memory>

using diamond = Diamond<double>;
using pentagon = Pentagon<double>;
using point = Point<double>;

int main() {
  std::shared_ptr<diamond> d1 = std::make_shared<diamond>(point(4, 4), point(7, 2), point(4, 0), point(1, 2));
  std::shared_ptr<diamond> d2 = std::make_shared<diamond>(point(3, 0), point(0, -2), point(-3, 0), point(0, 2));
  std::shared_ptr<pentagon> p1 = std::make_shared<pentagon>(point(0, 100), 
                                point(std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5)),
                                point(25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5)),
                                point(-25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5)),
                                point(-std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5))); 
  
  Vector<std::shared_ptr<Figure<double>>> v = {d1, d2, p1};
  print_all_areas(v);
  print_all_centres(v);
  double all_area = calculate_all_area(v);
  std::cout << "Sum of areas: " << all_area << std::endl;
}
