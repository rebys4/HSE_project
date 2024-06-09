#ifndef GEOMETRY_POLYGON_H
#define GEOMETRY_POLYGON_H

#include <vector>
#include "ishape.h"
#include "point.h"
#include "ray.h"

namespace geometry {
class Polygon : public IShape {
  std::vector<Point> pts_;

 public:
  Polygon();
  explicit Polygon(const std::vector<Point>& points) : pts_(points){};
  //~polygon() override = default;
  IShape& Move(const Vector& vec) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif  // GEOMETRY_POLYGON_H
