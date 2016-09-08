//
//  Ray.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Point.hpp"
#include "Vector.hpp"

class Ray
{
public:
    Point pos;
    Vector dir;
    float tMin = 0.0;
    float tMax = 1.0;
    Ray();
    Ray(Point pos, Vector dir);
};