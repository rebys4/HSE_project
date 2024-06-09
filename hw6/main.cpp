#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::unordered_map<std::string, int> word_count;
  std::string line;
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
      std::cout << word_count[word] << " ";
      word_count[word]++;
    }
  }
  std::cout << "\n";
  return 0;
}