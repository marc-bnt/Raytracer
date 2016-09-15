//
//  Ray.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include <float.h>
#include "Point.hpp"
#include "Vector.hpp"

class Ray
{
public:
    Point pos;
    Vector dir;
    float tMin = 0.0;
    float tMax = FLT_MAX;
    Ray();
    Ray(Point pos, Vector dir);
    Ray(Point pos, Vector dir, float tMin, float tMax);
};
