//
//  Point.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Point.hpp"
#include "Vector.hpp"

Vector Point::operator-(const Point& other) {
    return Vector(x - other.x, y - other.y, z - other.z);
}

Point::Point() {
}

Point::Point(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}