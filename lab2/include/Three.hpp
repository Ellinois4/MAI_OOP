#ifndef SIX_HPP_INCLUDED
#define SIX_HPP_INCLUDED

#include <iostream>
#include <cmath>
#include <algorithm>
#include "containers/Vector.hpp"
#include "../src/containers/Vector.cpp"

class Three {  
private:
  Vector<unsigned char> number;

public:
  Three(uint64_t n);
  Three(const std::string& str);
  Three(const Three& oth) noexcept;
  Three(Three&& oth) noexcept;

  Three& operator=(Three&& oth) noexcept;
  Three& operator=(Three oth) noexcept;

  Three operator+(const Three& oth) const noexcept;
  Three operator-(const Three& oth) const;
  Three& operator++() noexcept;
  Three operator++(int) noexcept;
  Three& operator--();
  Three operator--(int);

  bool operator==(const Three& oth) const;
  bool operator!=(const Three& oth) const;
  bool operator>(const Three& oth) const;
  bool operator<(const Three& oth) const;

  friend std::ostream& operator<< (std::ostream& stream, const Three& six);

  void print() const;

};

#endif // SIX_HPP_INCLUDED