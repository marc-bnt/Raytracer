//
//  Sphere.cpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#include "Sphere.hpp"
#include "math.h"

bool Sphere::intersect(Ray& ray, float* thit, LocalGeo* local) {
    float a = ray.dir.dot(ray.dir);
    float b = 2 * (ray.dir.dot(ray.pos - center));
    float c = (ray.pos - center) .dot(ray.pos - center) - pow(radius, 2);
    
    float discriminant = pow(b, 2) - 4 * a * c;
    
    if (discriminant < 0)
        return false;
    
    float thit1 = (-b - sqrt(discriminant)) / 2 * a;
    float thit2 = (-b + sqrt(discriminant)) / 2 * a;
    
    if (thit1 > thit2) {
        float temp = thit1;
        thit1 = thit2;
        thit2 = temp;
    }
    
    if (thit2 < 0) {
        return false;
    }
    
    if (thit1 < 0) {
        *thit = thit2;
        return true;
    }
    
    *thit = thit1;
    return true;
}

bool Sphere::trace(Ray r, double distance) {
    return false;
}

Sphere::Sphere() {
}

Sphere::Sphere(Point center, double radius) {
    this->center = center;
    this->radius = radius;
}
