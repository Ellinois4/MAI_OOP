#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include "../containers/Vector.hpp"
#include "../../src/containers/Vector.cpp"
#include "../figures/Point.hpp"

#include <iostream>

class Figure {
protected:
    Vector<Point> coordinates;

public:
    virtual operator double() const = 0;
    virtual Point geom_center() const = 0;
    
};

#endif