#ifndef HEXAGON_HPP_INCLUDED
#define HEXAGON_HPP_INCLUDED

#include "../interface/Figure.hpp"

#include <iostream>

class Hexagon: public Figure {
public:    
    Hexagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6
    );
    operator double() const override;
    Point geom_center() const override;

    friend std::ostream& operator<<(std::ostream&, const Hexagon&);
    friend std::istream& operator>>(std::istream&, Hexagon&);
    friend bool operator==(const Hexagon&, const Hexagon&);

private:
    bool is_valid(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6
    ) noexcept;
};

#endif