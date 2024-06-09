#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H

#include "IShape.h"

namespace geometry {

    class Point : public IShape {
        int x_;
        int y_;
    public:
        Point();
        Point(int x, int y);
        //~Point() override = default;
        IShape& Move(const Vector& vec) override;
        bool ContainsPoint(const Point& point) const override;
        bool CrossesSegment(const Segment& segment) const override;
        IShape* Clone() const override;
        std::string ToString() const override;
        int GetX() const;
        int GetY() const;
        Vector operator-(const Point &p) const;

    };
}

#endif //GEOMETRY_POINT_H
