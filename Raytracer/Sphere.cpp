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
    float c = (ray.pos - center).dot(ray.pos - center) - pow(radius, 2);
    
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
    } else {
        *thit = thit1;
    }
    
    Vector point = ray.pos + (ray.dir*(*thit));
    Vector normal = (point - center).normalize();
    
    local->pos = Point(point.x, point.y, point.z);
    local->normal = normal;
    
    return *thit > ray.tMin && *thit < ray.tMax;
}

bool Sphere::intersectP(Ray& ray) {
    float a = ray.dir.dot(ray.dir);
    float b = 2 * (ray.dir.dot(ray.pos - center));
    float c = (ray.pos - center).dot(ray.pos - center) - pow(radius, 2);
    
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
    
    float thit;
    
    if (thit1 < 0) {
        thit = thit2;
    } else {
        thit = thit1;
    }
    
    return thit > ray.tMin && thit < ray.tMax;
}

Sphere::Sphere() {
}

Sphere::Sphere(Point center, double radius) {
    this->center = center;
    this->radius = radius;
}
