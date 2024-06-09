#ifndef GEOMETRY_RAY_H
#define GEOMETRY_RAY_H

#include "ishape.h"
#include "point.h"

namespace geometry {
class Ray : public IShape {
  Point p1_;
  Point p2_;

 public:
  Ray();
  Ray(const Point& p1, const Point& p2) : p1_(p1), p2_(p2){};
  //~ray() override = default;
  IShape& Move(const Vector& vec) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif  // GEOMETRY_RAY_H
