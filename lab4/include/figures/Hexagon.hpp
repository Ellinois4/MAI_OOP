#ifndef HEXAGON_HPP_INCLUDED
#define HEXAGON_HPP_INCLUDED

#include "../interface/Figure.hpp"

#include <iostream>

// #define INACCURACY 1e-3

template <typename T>
class Hexagon: public Figure<T> {
public:    
    Hexagon(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6
    );
    operator double() const override;
    Point<T> geom_center() const override;

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Hexagon<U>&);
    template <typename U>
    friend std::istream& operator>>(std::istream&, Hexagon<U>&);
    template <typename U>
    friend bool operator==(const Hexagon<U>&, const Hexagon<U>&);

private:
    bool is_valid(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6
    ) noexcept;
};

#include "../../src/figures/Hexagon.cpp"

#endif