#include <iostream>
#include <map>
#include "include/Allocator.hpp"
#include "include/Queue.hpp"

int main() {
  std::map<int, int, std::less<int>, mystd::allocator<std::pair<const int, int>, 1000>> m;

  for (size_t i = 0; i < 10; ++i) {
    m.insert({i + 10, i});
  }

  for (auto& e : m) {
    std::cout << '{' << e.first << ", " << e.second << "}, ";
  }

  std::cout << std::endl;
    {
        Queue<int, mystd::allocator<int, 1000>> queue;
        queue.push(123);
        Queue<int, mystd::allocator<int, 1000>> a = queue;
        // a = queue;
        a.push(228);

        queue.push(123);
        a.push(228);

        std::cout << a.get_size() << std::endl;
        std::cout << a.back() << std::endl;
        std::cout << queue.get_size() << std::endl;
        std::cout << queue.back() << std::endl;
    }
   std::cout << 123;
    std::cout << 123;

    std::cout << 123;
    std::cout << 123;

    return 0;
}