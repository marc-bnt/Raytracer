//
//  Sphere.hpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include "Shape.hpp"
#include "BRDF.hpp"

class Sphere : public Shape {
private:
    Point center;
    double radius;
public:
    bool intersect(Ray& ray, float* thit, LocalGeo* local);
    bool intersectP(Ray& ray, LocalGeo* local);

    Sphere();
    Sphere(Point center, double radius);
};

#endif /* Sphere_hpp */
