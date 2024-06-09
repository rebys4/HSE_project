#include <iostream>
#include <chrono>
#include <exception>

float Divide(int a, int b) noexcept {
  if (b == 0) {
    //    throw 89;
    //    std::cout << "Division by zero\n";
    //    return 1. * a / b;
  }
  return a / b;
}

unsigned int Fibonacci(unsigned int n) {
  if (n < 2) {
    return 1;
  }
  return Fibonacci(n - 1) + Fibonacci(n - 2);
}

unsigned int Fact(unsigned int n) {
  if (n == 1) {
    return 1;
  }
  return n * Fact(n - 1);
}




int main() {
  int a = 9;
  int b = 0;



  auto st = std::chrono::steady_clock::now();
  std::cout << Fibonacci(Fact(5)) << "\n";
  auto end = std::chrono::steady_clock::now();
  auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - st).count();
  std::cout << diff << "\n";
  return 0;

  try {
    auto st = std::chrono::steady_clock::now();
    std::cout << Fibonacci(Fact(5)) << "\n";
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - st).count();
    std::cout << diff << "\n";
    //std::cout << Divide(a, b) << "\n";
  }
  catch (const char* err) {
    std::cout << err << '\n';
  }
  catch (int code) {
    std::cout << code << '\n';
  }
  catch (...) {
    std::cout << "smth went wrong" << '\n';
  }
//  std::cout << Divide(a, b) << "\n";
  //  std::cout << "Hello, World!" << "\n";
  return 0;
}
