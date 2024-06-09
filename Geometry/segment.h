#ifndef GEOMETRY_SEGMENT_H
#define GEOMETRY_SEGMENT_H

#include "ishape.h"
#include "point.h"

namespace geometry {
class Segment : public IShape {
  Point x_;
  Point y_;
  int a_ = 0;
  int b_ = 0;
  int c_ = 0;
  void InitLine();

 public:
  Segment();
  Segment(Point x, Point y);
  //~Segment() override = default;
  IShape& Move(const Vector& vec) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossesSegment(const Segment& segment) const override;
  IShape* Clone() const override;
  std::string ToString() const override;
  Point GetStart();
  Point GetEnd();
};
}  // namespace geometry

#endif  // GEOMETRY_SEGMENT_H
