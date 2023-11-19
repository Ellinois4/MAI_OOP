#include "../include/functions.hpp"

inline double calculate_all_area(Vector<std::shared_ptr<Figure<double>>>& vec) {
  double area = 0;
  for (size_t i = 0; i < vec.get_size(); ++i) {
    area += static_cast<double>(*vec[i]);
  }

  return area;
}

inline void print_all_areas(Vector<std::shared_ptr<Figure<double>>>& vec) {
  std::cout << "areas of all figures: " << std::endl;
  
  for (size_t i = 0; i < vec.get_size(); ++i) {
    std::cout << static_cast<double>(*vec[i]) << ", ";
  }

  std::cout << std::endl;
}

inline void print_all_centres(Vector<std::shared_ptr<Figure<double>>>& vec) {
  std::cout << "centres of all figures: " << std::endl;

  for (size_t i = 0; i < vec.get_size(); ++i) {
    std::cout << vec[i]->geom_center() << ", ";
  }

  std::cout << std::endl;
}