#include "../../include/figures/Diamond.hpp"

#include <cmath>

template <typename T>
Diamond<T>::Diamond(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) {
    if (!is_valid(p1, p2, p3, p4)){
        throw std::invalid_argument("Invalid points. Diamond can't be created."); 
    }

    this->coordinates = {p1, p2, p3, p4};

}

template <typename T>
Point<T> Diamond<T>::geom_center() const {
    T center_x = 0;
    T center_y = 0;

    for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
        center_x += this->coordinates[i].get_x();
        center_y += this->coordinates[i].get_y();
    }

    return Point<T>(center_x / 4.0, center_y / 4.0);
}

template <typename T>
Diamond<T>::operator double() const {
    
    T diam1 = Point<T>::line_len(this->coordinates[0], this->coordinates[2]);
    T diam2 = Point<T>::line_len(this->coordinates[1], this->coordinates[3]);

    return (diam1 + diam2) / 2.0; 
}

template <typename T>
bool Diamond<T>::is_valid(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) {

    T sum_x = p1.get_x() + p2.get_x() + p3.get_x() + p4.get_x();
    T sum_y = p1.get_y() + p2.get_y() + p3.get_y() + p4.get_y();
    Point<T> center = Point<T>(sum_x / 4.0, sum_y / 4.0);

    //side length

    T side_p1p2 = Point<T>::line_len(p1, p2);
    T side_p2p3 = Point<T>::line_len(p2, p3);
    T side_p3p4 = Point<T>::line_len(p3, p4);
    T side_p1p4 = Point<T>::line_len(p1, p4);

    //distance from point to center

    T dist_p1 = Point<T>::line_len(center, p1);
    T dist_p2 = Point<T>::line_len(center, p2);
    T dist_p3 = Point<T>::line_len(center, p3);
    T dist_p4 = Point<T>::line_len(center, p4);

    if (side_p1p2 > INACCURACY && side_p2p3 > INACCURACY &&
        side_p3p4 > INACCURACY && side_p1p4 > INACCURACY){

        if (std::abs(side_p1p2 - side_p3p4) < INACCURACY &&
            std::abs(side_p1p4 - side_p2p3) < INACCURACY) {

                if (std::abs(dist_p1 - dist_p3) < INACCURACY &&
                    std::abs(dist_p2 - dist_p4) < INACCURACY) {
                        return true;
                }
        }
    }
    return false;

}

template <typename U>
bool operator==(const Diamond<U>& lhs, const Diamond<U>& rhs) {
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

template <typename U>
std::ostream& operator<<(std::ostream& os, const Diamond<U>& rhs) {
  for (size_t i = 0; i < rhs.coordinates.get_size(); ++i) {
    os << rhs.coordinates[i];
  }
  return os;
}

template <typename U>
std::istream& operator>>(std::istream& is, Diamond<U>& rhs) {
  is >> rhs.coordinates[0] >> rhs.coordinates[1] >> rhs.coordinates[2] >> rhs.coordinates[3];
  return is;
}