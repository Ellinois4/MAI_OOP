#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include "../containers/Vector.hpp"
// #include "../../src/containers/Vector.cpp"
#include "../figures/Point.hpp"
// #include "../../src/figures/Point.cpp"

#include <iostream>

template<typename T>
class Figure {
protected:
    Vector<Point<T>> coordinates;

public:
    virtual operator double() const = 0;
    virtual Point<T> geom_center() const = 0;
    
};

#endif