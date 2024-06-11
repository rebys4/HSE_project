#include <iostream>
#include <utility>
#include "array.h"

int main() {
  Array<char, 3> a{};
  a[0] = '1';
  a[1] = 'z';
  a[2] = '*';

  std::cout << std::as_const(a).Back() << "\n";
  return 0;
}
