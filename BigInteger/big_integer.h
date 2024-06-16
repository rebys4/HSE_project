#ifndef BIGINTEGER_BIGINTEGER_H
#define BIGINTEGER_BIGINTEGER_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class BigIntegerOverflow : public std::runtime_error {
 public:
  BigIntegerOverflow() : std::runtime_error("BigIntegerOverflow") {
  }
};

class BigIntegerDivisionByZero : public std::runtime_error {
 public:
  BigIntegerDivisionByZero() : std::runtime_error("BigIntegerDivisionByZero") {
  }
};

class Biginteger {
 public:
  Biginteger();
  Biginteger(int);
  Biginteger(const std::string&);

  Biginteger& operator=(const Biginteger&);
  Biginteger& operator+=(const Biginteger&);
  Biginteger& operator-=(const Biginteger&);
  Biginteger& operator*=(const Biginteger&);
  Biginteger& operator++();
  Biginteger& operator++(int);
  Biginteger& operator--();
  Biginteger& operator--(int);

  Biginteger operator+() const;
  Biginteger operator-() const;

  bool operator==(const Biginteger&) const;
  bool operator!=(const Biginteger&) const;
  bool operator<(const Biginteger&) const;
  bool operator>(const Biginteger&) const;
  bool operator>=(const Biginteger&) const;
  bool operator<=(const Biginteger&) const;

  bool IsNegative() const;
  std::string ToString() const;

  friend std::istream& operator>>(std::istream&, Biginteger&);
  friend std::ostream& operator<<(std::ostream&, const Biginteger&);

 private:
  std::vector<int> digits;
  bool is_negative;

  void RemoveLeadingZero();
  void Add(const Biginteger&);
  void Substract(const Biginteger&);
  void Multiply(const Biginteger&);
};


#endif //BIGINTEGER_BIGINTEGER_H
