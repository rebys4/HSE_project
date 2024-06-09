#include <iostream>
#include <cstdint>
#include <numeric>
#include <stdexcept>
#ifndef HW_RATIONAL_RATIONAL_H
#define HW_RATIONAL_RATIONAL_H

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Rational {
 private:
  int32_t numerator_;
  int32_t denominator_;
  void Set(int32_t numerator, int32_t denominator);

 public:
  Rational();
  Rational(int32_t value); // NOLINT
  Rational(const Rational& r);
  Rational(int32_t numerator, int32_t denominator);
  ~Rational() = default;
  int32_t GetNumerator() const;
  int32_t GetDenominator() const;
  void SetNumerator(int32_t numerator);
  void SetDenominator(int32_t denominator);
  void Correction();

  friend Rational& operator++(Rational& rational);
  friend Rational& operator--(Rational& rational);
  friend Rational operator+(const Rational& rational);
  friend Rational operator-(const Rational& rational);
  friend Rational& operator+=(Rational& left, const Rational& right);
  friend Rational& operator*=(Rational& left, const Rational& right);

  friend std::istream& operator>>(std::istream& is, Rational& r);
};

Rational& operator/=(Rational& left, const Rational& right);
Rational& operator-=(Rational& left, const Rational& right);

Rational operator+(const Rational& left, const Rational& right);
Rational operator-(const Rational& left, const Rational& right);
Rational operator/(const Rational& left, const Rational& right);
Rational operator*(const Rational& left, const Rational& right);

Rational operator++(Rational& rational, int32_t);
Rational operator--(Rational& rational, int32_t);

bool operator==(const Rational& left, const Rational& right);
bool operator!=(const Rational& left, const Rational& right);
bool operator>(const Rational& left, const Rational& right);
bool operator>=(const Rational& left, const Rational& right);
bool operator<(const Rational& left, const Rational& right);
bool operator<=(const Rational& left, const Rational& right);

Rational operator/(const Rational& left, const Rational& right);
Rational operator*(const Rational& left, const Rational& right);
std::ostream& operator<<(std::ostream& os, const Rational& rational);
#endif  // HW_RATIONAL_RATIONAL_H
