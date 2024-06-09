#ifndef GEOMETRY_CIRCLE_H
#define GEOMETRY_CIRCLE_H

#include "ishape.h"
#include "point.h"

namespace geometry {
class Circle : public IShape {
  int r_;
  Point p_;

 public:
  Circle();
  Circle(Point p1, int radius);
  //~circle() override = default;
  IShape& Move(const Vector& vec) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
#endif  // GEOMETRY_CIRCLE_H
