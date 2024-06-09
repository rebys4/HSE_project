#include "string_view.h"

int main() {
  StringView sv = "abcdefghjkl";
  if (sv.Size() == sv.Length()) {
    std::cout << "yes" << "\n";
  } else {
    std::cout << "no" << "\n";
  }
  return 0;
}