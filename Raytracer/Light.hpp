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

typedef enum {
    LightDirectional,
    LightPoint
} LightType;

class Light {
public:
    Color color;
    Vector direction;
    LightType type;
    Light();
    Light(Color color, Vector direction, LightType type);
};

#endif /* Light_hpp */
