#ifndef GEOMETRY_LINE_H
#define GEOMETRY_LINE_H

#include "ishape.h"
#include "point.h"

namespace geometry {
class Line : public IShape {
  int a_;
  int b_;
  int c_;
  Point p1_;
  Point p2_;
  void InitLine();

 public:
  Line();
  Line(const Point& p1, const Point& p2);
  //~line() override = default;
  IShape& Move(const Vector& vec) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif  // GEOMETRY_LINE_H
