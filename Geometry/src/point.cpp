#include "../Point.h"
#include "../segment.h"

geometry::Point::Point() {
  x_ = 0;
  y_ = 0;
}

geometry::Point::Point(int x, int y) {
  x_ = x;
  y_ = y;
}

geometry::IShape& geometry::Point::Move(const geometry::Vector& vec) {
  x_ += vec.GetX();
  y_ += vec.GetY();
  return *this;
}

bool geometry::Point::ContainsPoint(const geometry::Point& point) const {
  return x_ == point.x_ && y_ == point.y_;
}

bool geometry::Point::CrossesSegment(const geometry::Segment& segment) const {
  return segment.ContainsPoint(*this);
  // return true;
}

geometry::IShape* geometry::Point::Clone() const {
  auto p = new Point(x_, y_);
  return p;
}

std::string geometry::Point::ToString() const {
  return "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}

int geometry::Point::GetX() const {
  return x_;
}

int geometry::Point::GetY() const {
  return y_;
}

geometry::Vector geometry::Point::operator-(const Point& p) const {
  return {x_ - p.x_, y_ - p.y_};
}