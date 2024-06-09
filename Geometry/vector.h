#ifndef GEOMETRY_VECTOR_H
#define GEOMETRY_VECTOR_H

namespace geometry {
class Vector {
  int x_;
  int y_;

 public:
  Vector();
  Vector(int x, int y);
  Vector operator-() const;
  Vector operator+() const;
  Vector operator+(const Vector& vec) const;
  Vector operator-(const Vector& vec) const;
  Vector& operator+=(const Vector& other);
  Vector& operator-=(const Vector& other);
  Vector operator*(int k) const;
  Vector operator/(int k) const;
  bool operator==(const Vector& vec) const;
  bool operator!=(const Vector& vec) const;
  int GetX() const;
  int GetY() const;
};
}  // namespace geometry

#endif  // GEOMETRY_VECTOR_H
