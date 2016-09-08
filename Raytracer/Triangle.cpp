//
//  Triangle.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Triangle.hpp"

bool Triangle::intersect(Ray r, double* t) {
    Vector normal = (point2 - point1).cross(point3 - point1).normalize();
    double dirDotN = r.dir.dot(normal);
    
    if (dirDotN == 0)
        return false;
        
    *t = (point1.dot(normal) - r.pos.dot(normal)) / dirDotN;

    Vector point = r.pos + (r.dir*(*t));
    
    if (normal.dot((point2 - point1).cross(point - point1)) < 0) {
        return false;
    }
    
    if (normal.dot((point3 - point2).cross(point - point2)) < 0) {
        return false;
    }
    
    if (normal.dot((point1 - point3).cross(point - point3)) < 0) {
        return false;
    }
 
    return true;
}

Triangle::Triangle(Point point1, Point point2, Point point3) {
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
}
