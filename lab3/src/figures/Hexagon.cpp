#include "../../include/figures/Hexagon.hpp"

#include <cmath>

bool Hexagon::is_valid(    
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6
    ) noexcept {
    
    double sum_x = p1.get_x() + p2.get_x() + p3.get_x() + p4.get_x() + p5.get_x() + p6.get_x();
    double sum_y = p1.get_y() + p2.get_y() + p3.get_y() + p4.get_y() + p5.get_y() + p6.get_y();
    Point center = Point::make_point(sum_x / 6.0, sum_y / 6.0);

    double inaccuracy = 1e-5;

    //side length

    double side_p1p2 = Point::line_len(p1, p2);
    double side_p2p3 = Point::line_len(p2, p3);
    double side_p3p4 = Point::line_len(p3, p4);
    double side_p4p5 = Point::line_len(p4, p5);
    double side_p5p6 = Point::line_len(p5, p6);
    double side_p1p6 = Point::line_len(p1, p6);

    //distance from point to center

    double dist_p1 = Point::line_len(center, p1);
    double dist_p2 = Point::line_len(center, p2);
    double dist_p3 = Point::line_len(center, p3);
    double dist_p4 = Point::line_len(center, p4);
    double dist_p5 = Point::line_len(center, p5);
    double dist_p6 = Point::line_len(center, p6);


    if (side_p1p2 > inaccuracy && side_p2p3 > inaccuracy &&
        side_p3p4 > inaccuracy && side_p4p5 > inaccuracy &&
        side_p5p6 > inaccuracy && side_p1p6 > inaccuracy
    ) {
        if (std::abs(side_p1p2 - side_p2p3) < inaccuracy &&
            std::abs(side_p2p3 - side_p3p4) < inaccuracy &&
            std::abs(side_p3p4 - side_p4p5) < inaccuracy &&
            std::abs(side_p4p5 - side_p5p6) < inaccuracy &&
            std::abs(side_p4p5 - side_p1p6) < inaccuracy
        ) {
            if (
                std::abs(dist_p1 - dist_p2) < inaccuracy &&
                std::abs(dist_p2 - dist_p3) < inaccuracy &&
                std::abs(dist_p3 - dist_p4) < inaccuracy &&
                std::abs(dist_p4 - dist_p5) < inaccuracy && 
                std::abs(dist_p5 - dist_p6) < inaccuracy
            ) {
                return true;
            }
        }
    }

    return false;
}

Hexagon::Hexagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6
    ) {
    
    bool is_hexagon = is_valid(p1, p2, p3, p4, p5, p6);

    if (!is_hexagon) {
        throw std::invalid_argument("Invalid points. Hexagon can't be created!");
    }

    coordinates = {p1, p2, p3, p4, p5, p6};
}

Point Hexagon::geom_center() const {
  double center_x = 0;
  double center_y = 0;

  for (size_t i = 0; i < coordinates.get_size(); ++i) {
    center_x += coordinates[i].get_x();
    center_y += coordinates[i].get_y();
  }

  return Point(center_x / 6.0, center_y / 6.0);
}

Hexagon::operator double() const {
  double side_len = Point::line_len(coordinates[0], coordinates[1]);

  return 3.0 * std::sqrt(3) * std::pow(side_len, 2) / 2.0;
}

bool operator==(const Hexagon& lhs, const Hexagon& rhs) {
  bool flag = false;

  for (size_t i = 0; i < lhs.coordinates.get_size(); ++i) {
    flag = false;

    for (size_t j = 0; i < rhs.coordinates.get_size(); ++i) {
      if (lhs.coordinates[i] == rhs.coordinates[j]) {
        flag = true;
        continue;
      }
    }

    if (!flag) {
      return false;
    }
  }

  return true;
}

std::ostream& operator<<(std::ostream& os, const Hexagon& rhs) {
  for (size_t i = 0; i < rhs.coordinates.get_size(); ++i) {
    os << rhs.coordinates[i];
  }
  return os;
}

std::istream& operator>>(std::istream& is, Hexagon& rhs) {
  is >> rhs.coordinates[0] >> rhs.coordinates[1] >> rhs.coordinates[2] >> 
        rhs.coordinates[3] >> rhs.coordinates[4] >> rhs.coordinates[5];
  return is;
}