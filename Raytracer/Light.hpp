//
//  Light.hpp
//  Raytracer
//
//  Created by Marc Bontje on 08-09-16.
//
//

#ifndef Light_hpp
#define Light_hpp

#include <stdio.h>
#include "Point.hpp"
#include "Color.hpp"
#include "Vector.hpp"
#include "Triangle.hpp"

typedef enum {
    LightDirectional,
    LightPoint
} LightType;

class Light {
public:
    Color color;
    Point position;
    Vector direction;
    LightType type;
    
    void generateLightRay(Triangle& triangle, Ray* lray, Color* lcolor);
    
    Light();

    // Directional light
    Light(Vector direction, Color color);
    
    // Point light
    Light(Point position, Color color);
};

#endif /* Light_hpp */
