#include "string_view.h"

int main() {
  StringView sv("Hello, World!");
  std::cout << "StringView: " << sv.Data() << std::endl;
  std::cout << "Size: " << sv.Size() << std::endl;
  std::cout << "First character: " << sv.Front() << std::endl;
  std::cout << "Last character: " << sv.Back() << std::endl;
  return 0;
}