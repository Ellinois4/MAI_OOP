#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "containers/Vector.hpp"
#include "interface/Figure.hpp"

inline double calculate_all_area(Vector<std::shared_ptr<Figure<double>>>& vec);

inline void print_all_areas(Vector<std::shared_ptr<Figure<double>>>& vec);

inline void print_all_centres(Vector<std::shared_ptr<Figure<double>>>& vec);

#include "../src/functions.cpp"

#endif