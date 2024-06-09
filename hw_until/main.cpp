#include "isSortedUntil.h"

int main() {
  int a[]{1, 2, 2, 3, 3, 4, 2, 5, 6};
  //const int result = IsSortedUntil(a, a + 9);
  std::cout << *IsSortedUntil(a, a + 9) << "\n";
  return 0;
}
