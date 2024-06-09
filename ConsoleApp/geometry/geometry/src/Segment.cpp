#include "../Segment.h"

geometry::Segment::Segment() {

}
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

}

void geometry::Segment::InitLine() {
  auto x1 = x_.GetX(), y1 = x_.GetY(), x2 = y_.GetX(), y2 = y_.GetY();
  a_ = y1 - y2;
  b_ = x2 - x1;
  c_ = y1 * (x1 - x2) - x1 * (y1 - y2);
}