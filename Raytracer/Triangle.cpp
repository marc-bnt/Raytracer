//
//  Triangle.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Triangle.hpp"

bool Triangle::intersect(Ray r, double* t) {
    return true;
}

Triangle::Triangle(Point *point1, Point* point2, Point* point3) {
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
}
