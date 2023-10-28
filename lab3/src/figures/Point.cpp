#include "../../include/figures/Point.hpp"

#include <cmath>

Point::Point(double x, double y): x(x), y(y) {}

Point Point::make_point(double x, double y) {
    return Point(x, y);
}

double Point::get_x() const noexcept{
    return x;
}

double Point::get_y() const noexcept{
    return y;
}

void Point::set_x(double x) noexcept {
    this->x = x;
}

void Point::set_y(double y) noexcept {
    this->y = y;
}

double Point::line_len(const Point& p1, const Point& p2) {
    double x1 = p1.get_x();
    double x2 = p2.get_x();
    
    double y1 = p1.get_y();
    double y2 = p2.get_y();
    
    return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

bool operator==(const Point& lhs, const Point& rhs) {

    double inaccuracy = 1e-5; 

    if (std::abs(lhs.x - rhs.x) < inaccuracy && std::abs(lhs.y - lhs.y) < inaccuracy) {  
        return true;
    }

    return false;
}

bool operator!=(const Point& lhs, const Point& rhs) {
    return !(lhs == rhs);
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}