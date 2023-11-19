#include "../../include/figures/Point.hpp"

#include <cmath>

template <typename T>
Point<T>::Point(const T& x, const T& y): x(x), y(y) {}

template <typename T>
T& Point<T>::get_x() noexcept{
    return x;
}

template <typename T>
T& Point<T>::get_y() noexcept{
    return y;
}

template <typename T>
const T& Point<T>::get_x() const noexcept{
    return x;
}

template <typename T>
const T& Point<T>::get_y() const noexcept{
    return y;
}

template <typename T>
void Point<T>::set_x(const T& x) noexcept {
    this->x = x;
}

template <typename T>
void Point<T>::set_y(const T& y) noexcept {
    this->y = y;
}

template <typename T>
T Point<T>::line_len(const Point<T>& p1, const Point<T>& p2) {
    T x1 = p1.get_x();
    T x2 = p2.get_x();
    
    T y1 = p1.get_y();
    T y2 = p2.get_y();
    
    return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

template <typename U>
bool operator==(const Point<U>& lhs, const Point<U>& rhs) {
    
    if (std::abs(lhs.x - rhs.x) < INACCURACY && std::abs(lhs.y - lhs.y) < INACCURACY) {  
        return true;
    }

    return false;
}

template <typename U>
bool operator!=(const Point<U>& lhs, const Point<U>& rhs) {
    return !(lhs == rhs);
}

template <typename U>
std::istream& operator>>(std::istream& is, Point<U>& p) {
    is >> p.x >> p.y;
    return is;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Point<U>& p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}