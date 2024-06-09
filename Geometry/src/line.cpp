#include "../line.h"

geometry::Line::Line() = default;

geometry::Line::Line(const geometry::Point& p1, const geometry::Point& p2) {
  p1_ = p1;
  p2_ = p2;
  InitLine();
}

void geometry::Line::InitLine() {
  auto x1 = p1_.GetX();
  auto y1 = p1_.GetY();
  auto x2 = p2_.GetX();
  auto y2 = p2_.GetY();
  a_ = y1 - y2;
  b_ = x2 - x1;
  c_ = y1 * (x1 - x2) - x1 * (y1 - y2);
}

geometry::IShape& geometry::Line::Move(const geometry::Vector& vec) {
  p1_.Move(vec);
  p2_.Move(vec);
  InitLine();
  return *this;
}

bool geometry::Line::ContainsPoint(const geometry::Point& point) const {
  if (a_ * point.GetX() + b_ * point.GetY() + c_ != 0) {
    return false;
  }
  return std::min(p1_.GetX(), p2_.GetX()) <= point.GetX() <= std::max(p1_.GetX(), p2_.GetX()) &&
         std::min(p1_.GetX(), p2_.GetX()) <= point.GetY() <= std::max(p1_.GetX(), p2_.GetX());
}

bool geometry::Line::CrossesSegment(const geometry::Segment& segment) const {
  return false;
}

geometry::IShape* geometry::Line::Clone() const {
  auto new_line = new Line(p1_, p2_);
  return new_line;
}

std::string geometry::Line::ToString() const {
  return std::string("line(") + std::to_string(a_) + ", " + std::to_string(b_) + ", " + std::to_string(c_);
}
