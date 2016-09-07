//
//  Triangle.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Ray.hpp"

class Triangle {
private:
    Point* point1;
    Point* point2;
    Point* point3;
public:
    Triangle();
    Triangle(Point *point1, Point* point2, Point* point3);
    bool intersect(Ray r, double* t);
    bool trace(Ray r, double distance);
};