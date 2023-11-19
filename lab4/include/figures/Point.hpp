#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

#include <iostream>

#define INACCURACY 1e-1

template <typename T>
struct Point {
private:
    T x;
    T y;

public:
    Point(const T& x, const T& y);

    static T line_len(const Point& p1, const Point& p2); 

    T& get_x() noexcept;
    T& get_y() noexcept;
    const T& get_x() const noexcept;
    const T& get_y() const noexcept;
    void set_x(const T& x) noexcept;
    void set_y(const T& y) noexcept;

    template <typename U>
    friend bool operator==(const Point<U>&, const Point<U>&);
    template <typename U>
    friend bool operator!=(const Point<U>&, const Point<U>&);

    template <typename U>
    friend std::istream& operator>>(std::istream&, Point<U>&);
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Point<U>&);
};

#include "../../src/figures/Point.cpp"

#endif