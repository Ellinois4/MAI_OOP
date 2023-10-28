#include "../../include/figures/Diamond.hpp"

#include <cmath>

Diamond::Diamond(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    if (!is_valid(p1, p2, p3, p4)){
        throw std::invalid_argument("Invalid points. Diamond can't be created."); 
    }

    coordinates = {p1, p2, p3, p4};

}

Point Diamond::geom_center() const {
    double center_x = 0;
    double center_y = 0;

    for (size_t i = 0; i < coordinates.get_size(); ++i) {
        center_x += coordinates[i].get_x();
        center_y += coordinates[i].get_y();
    }

    return Point::make_point(center_x / 4.0, center_y / 4.0);
}

Diamond::operator double() const {
    
    double diam1 = Point::line_len(coordinates[0], coordinates[2]);
    double diam2 = Point::line_len(coordinates[1], coordinates[3]);

    return (diam1 + diam2) / 2.0; 
}

bool Diamond::is_valid(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {

    double sum_x = p1.get_x() + p2.get_x() + p3.get_x() + p4.get_x();
    double sum_y = p1.get_y() + p2.get_y() + p3.get_y() + p4.get_y();
    Point center = Point::make_point(sum_x / 4.0, sum_y / 4.0);

    double inaccuracy = 1e-5;

    //side length

    double side_p1p2 = Point::line_len(p1, p2);
    double side_p2p3 = Point::line_len(p2, p3);
    double side_p3p4 = Point::line_len(p3, p4);
    double side_p1p4 = Point::line_len(p1, p4);

    //distance from point to center

    double dist_p1 = Point::line_len(center, p1);
    double dist_p2 = Point::line_len(center, p2);
    double dist_p3 = Point::line_len(center, p3);
    double dist_p4 = Point::line_len(center, p4);

    if (side_p1p2 > inaccuracy && side_p2p3 > inaccuracy &&
        side_p3p4 > inaccuracy && side_p1p4 > inaccuracy){

        if (std::abs(side_p1p2 - side_p3p4) < inaccuracy &&
            std::abs(side_p1p4 - side_p2p3) < inaccuracy) {

                if (std::abs(dist_p1 - dist_p3) < inaccuracy &&
                    std::abs(dist_p2 - dist_p4) < inaccuracy) {
                        return true;
                }
        }
    }
    return false;

}

bool operator==(const Diamond& lhs, const Diamond& rhs) {
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

std::ostream& operator<<(std::ostream& os, const Diamond& rhs) {
  for (size_t i = 0; i < rhs.coordinates.get_size(); ++i) {
    os << rhs.coordinates[i];
  }
  return os;
}

std::istream& operator>>(std::istream& is, Diamond& rhs) {
  is >> rhs.coordinates[0] >> rhs.coordinates[1] >> rhs.coordinates[2] >> rhs.coordinates[3];
  return is;
}