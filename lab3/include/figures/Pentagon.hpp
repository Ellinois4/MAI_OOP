#ifndef PENTAGON_HPP_INCLUDED
#define PENTAGON_HPP_INCLUDED

#include "../interface/Figure.hpp"

#include <iostream>

class Pentagon: public Figure {
public:    
    Pentagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5
    );
    operator double() const override;
    Point geom_center() const override;

    friend std::ostream& operator<<(std::ostream&, const Pentagon&);
    friend std::istream& operator>>(std::istream&, Pentagon&);
    friend bool operator==(const Pentagon&, const Pentagon&);


private:
    bool is_valid(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5
    ) noexcept;
};


#endif