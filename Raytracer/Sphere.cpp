//
//  Sphere.cpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#include "Sphere.hpp"

bool Sphere::intersect(Ray& ray, float* thit, LocalGeo* local) {
    return false;
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
