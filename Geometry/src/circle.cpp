#include "../circle.h"

geometry::Circle::Circle() = default;

geometry::Circle::Circle(geometry::Point p1, int r) {
  p_ = p1;
  r_ = r;
}

geometry::IShape &geometry::Circle::Move(const geometry::Vector &vec) {
  p_.Move(vec);
  return *this;
}

geometry::IShape *geometry::Circle::Clone() const {
  auto new_circle = new Circle(p_, r_);
  return new_circle;
}

bool geometry::Circle::ContainsPoint(const geometry::Point &point) const {
  return (point.GetX() - p_.GetX()) * (point.GetX() - p_.GetX()) + (point.GetY() - p_.GetY()) * (point.GetY() - p_.GetY()) <=
      r_ * r_;
}

bool geometry::Circle::CrossesSegment(const geometry::Segment &segment) const {
  return false;
}

std::string geometry::Circle::ToString() const {
  return std::string("Circle(") + std::string("Point(") + std::to_string(p_.GetX()) + ", " + std::to_string(p_.GetY()) +
         "), " + std::to_string(r_) + ")";
}