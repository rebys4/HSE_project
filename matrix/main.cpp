#include <iostream>
#include "matrix.h"

int main() {
  Matrix<int, 2, 3> a{};
  a.At(0, 0) = 1;
  a.At(1, 1) = -1;
  a.At(0, 2) = 7;
  std::cout << a;
  return 0;
}