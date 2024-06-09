#include <memory>
#include "../polygon.h"
#include "../segment.h"

namespace geometry {

Polygon::Polygon() = default;

bool Polygon::ContainsPoint(const geometry::Point &point) const {
  auto p2 = point;
  p2.Move(Vector(1, 0));
  Ray ray = Ray(point, p2);
  unsigned int counter = 0;
  for (int i = 0; i < pts_.size(); i++) {
    if (ray.CrossesSegment(Segment(pts_[i], pts_[(i + 1) % pts_.size()]))) {
      if (ray.ContainsPoint(pts_[i]) && ray.ContainsPoint(pts_[(i + 1) % pts_.size()])) {
        continue;
      }
      if (pts_[i].GetY() > pts_[(i + 1) % pts_.size()].GetY()) {
        counter += ray.ContainsPoint(pts_[i]);
      } else {
        counter += ray.ContainsPoint(pts_[(i + 1) % pts_.size()]);
      }
    }
  }
  return counter % 2;
}

bool Polygon::CrossesSegment(const geometry::Segment &segment) const {
  for (int i = 0; i < pts_.size(); i++) {
    if (Segment(pts_[i], pts_[(i + 1) & pts_.size()]).CrossesSegment(segment)) {
      return true;
    }
  }
  return false;
}

IShape &Polygon::Move(const geometry::Vector &vec) {
  for (int i = 0; i < pts_.size(); i++) {
    pts_[i].Move(vec);
  }
  return *this;
}

IShape *Polygon::Clone() const {
  auto new_polygon = new Polygon(pts_);
  return new_polygon;
}

std::string Polygon::ToString() const {
  auto str = std::string("polygon(");
  for (int i = 0; i < pts_.size(); i++) {
    if (i != pts_.size() - 1) {
      str += std::string("Point(") + std::to_string(pts_[i].GetX()) + ", " + std::to_string(pts_[i].GetY()) + ")";
    } else {
      str += std::string("Point(") + std::to_string(pts_[i].GetX()) + ", " + std::to_string(pts_[i].GetY()) + "))";
    }
  }
  return str;
}
}  // namespace geometry