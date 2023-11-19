#ifndef PENTAGON_HPP_INCLUDED
#define PENTAGON_HPP_INCLUDED

#include "../interface/Figure.hpp"

#include <iostream>

// #define INACCURACY 1e-1

template <typename T>
class Pentagon: public Figure<T> {
public:    
    Pentagon(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5
    );
    operator double() const override;
    Point<T> geom_center() const override;

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Pentagon<U>&);
    template <typename U>
    friend std::istream& operator>>(std::istream&, Pentagon<U>&);
    template <typename U>
    friend bool operator==(const Pentagon&, const Pentagon<U>&);


private:
    bool is_valid(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5
    ) noexcept;
};

#include "../../src/figures/Pentagon.cpp"

#endif