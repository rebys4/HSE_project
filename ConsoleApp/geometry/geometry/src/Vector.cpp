#include "../Vector.h"
#include <iostream>

geometry::Vector::Vector() {
  x_ = 0;
  y_ = 0;
}
geometry::Vector::Vector(int x, int y) {
  x_ = x;
  y_ =y;
}
geometry::Vector geometry::Vector::operator-() const {
  return {-x_, -y_};
}

geometry::Vector geometry::Vector::operator+() const {
  return {x_, y_};
}
geometry::Vector geometry::Vector::operator+(const Vector& vec) const {
  int new_x = x_ + vec.x_;
  int new_y = y_ + vec.y_;
  return {new_x, new_y};
}
geometry::Vector geometry::Vector::operator-(const Vector& vec) const {
  int new_x = x_ - vec.x_;
  int new_y = y_ - vec.y_;
  return {new_x, new_y};
}

geometry::Vector& geometry::Vector::operator+=(const Vector& other) {
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}

geometry::Vector& geometry::Vector::operator-=(const Vector& other) {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}

geometry::Vector geometry::Vector::operator*(int k) const {
  int new_x = x_ * k;
  int new_y = y_ * k;
  return {new_x, new_y};
}

geometry::Vector geometry::Vector::operator/(int k) const {
  if (k == 0) {
    throw std::exception();
  }
  return {x_ / k, y_ / k};
}

bool geometry::Vector::operator==(const Vector& vec) const {
  return x_ == vec.x_ && y_ == vec.y_;
}

bool geometry::Vector::operator!=(const Vector& vec) const {
  return x_ != vec.x_ || y_ == vec.y_;
}

int geometry::Vector::GetX() const {
  return x_;
}

int geometry::Vector::GetY() const {
  return y_;
}