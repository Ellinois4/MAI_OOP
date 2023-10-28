#ifndef DIAMOND_HPP_INCLUDED
#define DIAMOND_HPP_INCLUDED

#include "../interface/Figure.hpp"

#include <iostream>

class Diamond: public Figure {
public:    
    Diamond(const Point&, const Point&, const Point&, const Point&);
    operator double() const override;
    Point geom_center() const override;

    friend std::ostream& operator<<(std::ostream&, const Diamond&);
    friend std::istream& operator>>(std::istream&, Diamond&);
    friend bool operator==(const Diamond&, const Diamond&);

private:
    bool is_valid(const Point&, const Point&, const Point&, const Point&);
};


#endif