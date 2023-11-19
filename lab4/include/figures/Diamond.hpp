#ifndef DIAMOND_HPP_INCLUDED
#define DIAMOND_HPP_INCLUDED

#include "../interface/Figure.hpp"

#include <iostream>

// #define INACCURACY 1e-3

template <typename T>
class Diamond: public Figure<T> {
public:    
    Diamond(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&);
    operator double() const override;
    Point<T> geom_center() const override;

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Diamond<U>&);
    template <typename U>
    friend std::istream& operator>>(std::istream&, Diamond<U>&);
    template <typename U>
    friend bool operator==(const Diamond<U>&, const Diamond<U>&);

private:
    bool is_valid(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&);
};

#include "../../src/figures/Diamond.cpp"

#endif