#include "../Segment.h"

geometry::Segment::Segment() = default;

geometry::Segment::Segment(geometry::Point x, geometry::Point y) {
  x_ = x;
  y_ = y;
  InitLine();
}
bool geometry::Segment::ContainsPoint(const geometry::Point& point) const {
  if (a_ * point.GetX() + b_ * point.GetY() + c_ != 0) {
    return false;
  }
  return std::min(x_.GetX(), y_.GetX()) <= point.GetX() <= std::max(x_.GetX(), y_.GetX()) &&
         std::min(x_.GetX(), y_.GetX()) <= point.GetY() <= std::max(x_.GetX(), y_.GetX());
}
bool geometry::Segment::CrossesSegment(const geometry::Segment& segment) const {
  return false;
}

geometry::IShape& geometry::Segment::Move(const geometry::Vector& vec) {
  x_.Move(vec);
  y_.Move(vec);
  InitLine();
  return *this;
}

geometry::IShape* geometry::Segment::Clone() const {
  auto new_seg = new Segment(x_, y_);
  return new_seg;
}

std::string geometry::Segment::ToString() const {
  return "Segment(" + std::string("Point(") + std::to_string(x_.GetX()) + std::to_string(x_.GetY()) + ", " +
         std::string("Point(") + std::to_string(y_.GetX()) + std::to_string(y_.GetY());
}

void geometry::Segment::InitLine() {
  auto x1 = x_.GetX();
  auto y1 = x_.GetY();
  auto x2 = y_.GetX();
  auto y2 = y_.GetY();
  a_ = y1 - y2;
  b_ = x2 - x1;
  c_ = y1 * (x1 - x2) - x1 * (y1 - y2);
}

geometry::Point geometry::Segment::GetStart() {
  auto p = Point(x_.GetX(), x_.GetY());
  return p;
}

geometry::Point geometry::Segment::GetEnd() {
  auto p = Point(y_.GetX(), y_.GetY());
  return p;
}