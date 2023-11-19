#include "../../include/figures/Pentagon.hpp"

#include <cmath>

template <typename T>
bool Pentagon<T>::is_valid(    
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5
    ) noexcept {
    
    T sum_x = p1.get_x() + p2.get_x() + p3.get_x() + p4.get_x() + p5.get_x();
    T sum_y = p1.get_y() + p2.get_y() + p3.get_y() + p4.get_y() + p5.get_y();
    Point<T> center = Point<T>(sum_x / 5.0, sum_y / 5.0);

    //side length

    T side_p1p2 = Point<T>::line_len(p1, p2);
    T side_p2p3 = Point<T>::line_len(p2, p3);
    T side_p3p4 = Point<T>::line_len(p3, p4);
    T side_p4p5 = Point<T>::line_len(p4, p5);
    T side_p1p5 = Point<T>::line_len(p1, p5);

    //distance from point to center

    T dist_p1 = Point<T>::line_len(center, p1);
    T dist_p2 = Point<T>::line_len(center, p2);
    T dist_p3 = Point<T>::line_len(center, p3);
    T dist_p4 = Point<T>::line_len(center, p4);
    T dist_p5 = Point<T>::line_len(center, p5);


    if (std::abs(side_p1p2 - side_p2p3) < INACCURACY &&
        std::abs(side_p2p3 - side_p3p4) < INACCURACY &&
        std::abs(side_p3p4 - side_p4p5) < INACCURACY &&
        std::abs(side_p4p5 - side_p1p5) < INACCURACY
    ) {
        if (
            std::abs(dist_p1 - dist_p2) < INACCURACY &&
            std::abs(dist_p2 - dist_p3) < INACCURACY &&
            std::abs(dist_p3 - dist_p4) < INACCURACY &&
            std::abs(dist_p4 - dist_p5) < INACCURACY
        ) {
            return true;
        }
    }
    
    return false;
}

template <typename T>
Pentagon<T>::Pentagon(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5
    ) {
    
    bool is_pentagon = is_valid(p1, p2, p3, p4, p5);

    if (!is_pentagon) {
        throw std::invalid_argument("Invalid points. Pentagon can't be created!");
    }

    this->coordinates = {p1, p2, p3, p4, p5};
}

template <typename T>
Point<T> Pentagon<T>::geom_center() const {
  T center_x = 0;
  T center_y = 0;

  for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
    center_x += this->coordinates[i].get_x();
    center_y += this->coordinates[i].get_y();
  }

  return Point<T>(center_x / 5.0, center_y / 5.0);
}

template <typename T>
Pentagon<T>::operator double() const {
  T side_len = Point<T>::line_len(this->coordinates[0], this->coordinates[1]);

  return std::sqrt(5) * std::sqrt(5 + 2 * std::sqrt(5)) * std::pow(side_len, 2) / 4.0;
}

template <typename U>
bool operator==(const Pentagon<U>& lhs, const Pentagon<U>& rhs) {
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
std::ostream& operator<<(std::ostream& os, const Pentagon<U>& rhs) {
  for (size_t i = 0; i < rhs.coordinates.get_size(); ++i) {
    os << rhs.coordinates[i];
  }
  return os;
}

template <typename U>
std::istream& operator>>(std::istream& is, Pentagon<U>& rhs) {
  is >> rhs.coordinates[0] >> rhs.coordinates[1] >> rhs.coordinates[2] >> 
        rhs.coordinates[3] >> rhs.coordinates[4];
  return is;
}