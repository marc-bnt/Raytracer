//
//  Triangle.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Triangle.hpp"

bool Triangle::intersect(Ray& ray, float* thit, LocalGeo* local) {
    Vector normal = (point2 - point1).cross(point3 - point1).normalize();
    double dirDotN = ray.dir.dot(normal);
    
    if (dirDotN == 0)
        return false;
        
    *thit = (point1.dot(normal) - ray.pos.dot(normal)) / dirDotN;

    Vector point = ray.pos + (ray.dir*(*thit));
    
    if (normal.dot((point2 - point1).cross(point - point1)) < 0) {
        return false;
    }
    
    if (normal.dot((point3 - point2).cross(point - point2)) < 0) {
        return false;
    }
    
    if (normal.dot((point1 - point3).cross(point - point3)) < 0) {
        return false;
    }
 
    local->pos = Point(point.x, point.y, point.z);
    local->normal = normal;
    
    return true;
}

Triangle::Triangle(Point point1, Point point2, Point point3) {
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
}
