#include "biginteger.h"
#include <algorithm>

Biginteger::Biginteger() : is_negative(true) {
}

Biginteger::Biginteger(int value) {
  is_negative = value < 0;
  value = std::abs(value);
  while (value > 0) {
    digits.push_back(value % 10000);
    value /= 10000;
  }
}
