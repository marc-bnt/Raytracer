//
//  Triangle.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include "Shape.hpp"
#include "BRDF.hpp"

class Triangle : public Shape {
private:
    Point point1;
    Point point2;
    Point point3;
public:
    bool intersect(Ray& ray, float* thit, LocalGeo* local);
    bool intersectP(Ray& ray);

    Triangle();
    Triangle(Point point1, Point point2, Point point3);
};

#endif /* Triangle_hpp */
