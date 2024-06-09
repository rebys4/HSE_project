#include <iostream>
#include <string>

int main() {
  std::string str;
  std::getline(std::cin, str);
  int open_bracket_count = 0;
  int result = 0;

  for (char c : str) {
    if (c == '(') {
      open_bracket_count++;
    } else if (c == ')' && open_bracket_count > 0) {
      open_bracket_count--;
    } else {
      result++;
    }
  }
  std::cout << result + open_bracket_count << "\n";
  return 0;
}