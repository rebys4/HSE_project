#include <iostream>
#include <vector>
#include <string>

class Stack {
 private:
  std::vector<int> data_;

 public:
  void Push(int n) {
    data_.push_back(n);
    std::cout << "ok\n";
  }
  void Pop() {
    int top = data_.back();
    data_.pop_back();
    std::cout << top << "\n";
  }
  void Back() {
    std::cout << data_.back() << "\n";
  }
  void Size() {
    std::cout << data_.size() << "\n";
  }
  void Clear() {
    data_.clear();
    std::cout << "ok\n";
  }
};

int main() {
  int n = 0;
  std::cin >> n;
  Stack stack;

  while (n != 0) {
    std::string command;
    std::cin >> command;

    if (command == "push") {
      int m = 0;
      std::cin >> m;
      stack.Push(m);
    } else if (command == "pop") {
      stack.Pop();
    } else if (command == "back") {
      stack.Back();
    } else if (command == "size") {
      stack.Size();
    } else if (command == "clear") {
      stack.Clear();
    } else if (command == "exit") {
      std::cout << "bye\n";
      break;
    }
    n--;
  }
  return 0;
}