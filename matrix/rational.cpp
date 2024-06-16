#include "rational.h"
#include <sstream>
#include <numeric>
#include <string>
#include <algorithm>

Rational::Rational() {
  numerator_ = 0;
  denominator_ = 1;
}

Rational::Rational(const Rational& r) : Rational(r.numerator_, r.denominator_) {
}

Rational::Rational(int32_t value) : numerator_(value), denominator_(1) {  // NOLINT
}                                                                         // NOLINT

Rational::Rational(int32_t numer, int32_t denom) : numerator_(numer), denominator_(denom) {
  Correction();
}
void Rational::Correction() {
  if (denominator_ < 0) {
    numerator_ *= -1;
    denominator_ *= -1;
  } else if (denominator_ == 0) {
    throw RationalDivisionByZero{};
  }
  if (numerator_ == 0) {
    denominator_ = 1;
  } else {
    int32_t gcd = std::gcd(numerator_, denominator_);
    numerator_ = numerator_ / gcd;
    denominator_ = denominator_ / gcd;
  }
};
void Rational::Set(int32_t numer, int32_t denom) {
  if (denom == 0) {
    throw RationalDivisionByZero{};
  }

  if (denom < 0) {
    numer *= -1;
    denom *= -1;
  }

  int32_t gcd_of_numer_and_denom = std::gcd(numer, denom);

  numer /= gcd_of_numer_and_denom;
  denom /= gcd_of_numer_and_denom;

  numerator_ = static_cast<int32_t>(numer);
  denominator_ = static_cast<int32_t>(denom);
}

int32_t Rational::GetNumerator() const {
  return Rational::numerator_;
}
int32_t Rational::GetDenominator() const {
  return Rational::denominator_;
}
void Rational::SetNumerator(int32_t numerator) {
  Set(numerator, denominator_);
}

void Rational::SetDenominator(int32_t denominator) {
  Set(numerator_, denominator);
}

int32_t MultiplyInt32(int32_t numer, int32_t denom) {
  return static_cast<int32_t>(numer) * static_cast<int32_t>(denom);
}

Rational& operator+=(Rational& left, const Rational& right) {
  int32_t numer = MultiplyInt32(left.GetNumerator(), right.GetDenominator()) +
                  MultiplyInt32(left.GetDenominator(), right.GetNumerator());
  int32_t denom = MultiplyInt32(left.GetDenominator(), right.GetDenominator());
  left.Set(numer, denom);
  return left;
}

Rational& operator*=(Rational& left, const Rational& right) {
  int32_t numer = MultiplyInt32(left.GetNumerator(), right.GetNumerator());
  int32_t denom = MultiplyInt32(left.GetDenominator(), right.GetDenominator());
  left.Set(numer, denom);
  return left;
}

Rational& operator++(Rational& rational) {
  int32_t numer = rational.GetNumerator() + rational.GetDenominator();
  rational.SetNumerator(numer);
  return rational;
}

Rational& operator--(Rational& rational) {
  int32_t numer = rational.GetNumerator() - rational.GetDenominator();
  rational.SetNumerator(numer);
  return rational;
}

Rational operator+(const Rational& rational) {
  return rational;
}

Rational operator-(const Rational& rational) {
  return {-rational.GetNumerator(), rational.GetDenominator()};
}

Rational& operator-=(Rational& left, const Rational& right) {
  return left += -right;
}

Rational& operator/=(Rational& left, const Rational& right) {
  Rational divisor = Rational(right.GetDenominator(), right.GetNumerator());
  return left *= divisor;
}

Rational operator+(const Rational& left, const Rational& right) {
  Rational rational = left;
  rational += right;
  return rational;
}

Rational operator-(const Rational& left, const Rational& right) {
  Rational rational = left;
  rational -= right;
  return rational;
}

Rational operator*(const Rational& left, const Rational& right) {
  Rational rational = left;
  rational *= right;
  return rational;
}

Rational operator/(const Rational& left, const Rational& right) {
  Rational rational = left;
  rational /= right;
  return rational;
}

Rational operator++(Rational& rational, int32_t) {
  const Rational r = rational;
  ++rational;
  return r;
}

Rational operator--(Rational& rational, int32_t) {
  const Rational r = rational;
  --rational;
  return r;
}

bool operator<(const Rational& left, const Rational& right) {
  return MultiplyInt32(left.GetNumerator(), right.GetDenominator()) <
         MultiplyInt32(right.GetNumerator(), left.GetDenominator());
}

bool operator>(const Rational& left, const Rational& right) {
  return MultiplyInt32(left.GetNumerator(), right.GetDenominator()) >
         MultiplyInt32(right.GetNumerator(), left.GetDenominator());
}

bool operator<=(const Rational& left, const Rational& right) {
  return MultiplyInt32(left.GetNumerator(), right.GetDenominator()) <=
         MultiplyInt32(right.GetNumerator(), left.GetDenominator());
}

bool operator>=(const Rational& left, const Rational& right) {
  return MultiplyInt32(left.GetNumerator(), right.GetDenominator()) >=
         MultiplyInt32(right.GetNumerator(), left.GetDenominator());
}

bool operator==(const Rational& left, const Rational& right) {
  return MultiplyInt32(left.GetNumerator(), right.GetDenominator()) ==
         MultiplyInt32(right.GetNumerator(), left.GetDenominator());
}

bool operator!=(const Rational& left, const Rational& right) {
  return MultiplyInt32(left.GetNumerator(), right.GetDenominator()) !=
         MultiplyInt32(right.GetNumerator(), left.GetDenominator());
}

std::istream& operator>>(std::istream& is, Rational& rational) {
  std::string text;
  is >> text;
  std::stringstream stringstream;
  stringstream << text;
  int numer = 0;
  int denom = 1;
  if (std::find(text.begin(), text.end(), '/') == text.end()) {
    stringstream >> numer;
  } else {
    char slash = '/';
    stringstream >> numer >> slash >> denom;
  }
  rational.Set(numer, denom);
  return is;
}

std::ostream& operator<<(std::ostream& os, const Rational& rational) {
  if (rational.GetDenominator() == 1) {
    return os << rational.GetNumerator();
  }
  return os << rational.GetNumerator() << "/" << rational.GetDenominator();
}