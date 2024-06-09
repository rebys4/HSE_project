#include "../ray.h"

geometry::Ray::Ray() = default;

geometry::IShape *geometry::Ray::Clone() const {
  auto new_ray = new Ray(p1_, p2_);
  return new_ray;
}

geometry::IShape &geometry::Ray::Move(const geometry::Vector &vec) {
  p1_.Move(vec);
  p2_.Move(vec);
  return *this;
}

bool geometry::Ray::CrossesSegment(const geometry::Segment &segment) const {
  return false;
}

bool geometry::Ray::ContainsPoint(const geometry::Point &point) const {
  return p1_.ContainsPoint(point) || p2_.ContainsPoint(point);
}

std::string geometry::Ray::ToString() const {
  return std::string("ray(") + std::string("Point(") + std::to_string(p1_.GetX()) + ", " + std::to_string(p1_.GetY()) +
         "), " + std::string("Vector(") + std::to_string(p2_.GetX()) + std::to_string(p2_.GetY()) + "))";
}