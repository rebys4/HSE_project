#include <iostream>
#include <vector>

#ifndef HW_UNTIL_ISSORTEDUNTIL_H
#define HW_UNTIL_ISSORTEDUNTIL_H

template <typename T>
T *IsSortedUntil(T *begin, T *end) {
  if (begin == end) {
    return end;
  }
  for (T *current = begin + 1; current != end; current++) {
    if (*current < *(current - 1)) {
      return current;
    }
  }
  return end;
}

#endif  // HW_UNTIL_ISSORTEDUNTIL_H
