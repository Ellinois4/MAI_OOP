#include "include/Three.hpp"

int main()
{
  Three a{100};
  Three f{0};
  Three s(1243);

  Vector<Three> vec{123, 341, 1234};
  Vector<Three> kuka;
  kuka = vec;

  for (size_t i = 0; i < kuka.get_size(); ++i) {
    std::cout << kuka[i] << std::endl;
  }

  Three c = std::move(a);
  Three g = s;
  f = g;

  std::cout << c << ' ' << a << std::endl;
  std::cout << f << ' ' << g << ' ' << s << std::endl;

  return 0;
}