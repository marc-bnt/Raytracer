//
//  Triangle.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include "Ray.hpp"
#include "BRDF.hpp"

class Triangle {
private:
    Point point1;
    Point point2;
    Point point3;
public:
    Point position;
    Vector normal;
    
    BRDF brdf;
    bool intersect(Ray r, double* t);
    bool trace(Ray r, double distance);
    Triangle();
    Triangle(Point point1, Point point2, Point point3);
};

#endif /* Triangle_hpp */
