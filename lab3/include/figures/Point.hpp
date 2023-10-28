#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

#include <iostream>

struct Point {
private:
    double x;
    double y;

public:
    Point(double x, double y);

    static Point make_point(double x, double y);
    static double line_len(const Point& p1, const Point& p2); 

    double get_x() const noexcept;
    double get_y() const noexcept;
    void set_x(double x) noexcept;
    void set_y(double y) noexcept;

    friend bool operator==(const Point&, const Point&);
    friend bool operator!=(const Point&, const Point&);
    friend std::istream& operator>>(std::istream&, Point&);
    friend std::ostream& operator<<(std::ostream&, const Point&);

};

#endif