//
//  Light.cpp
//  Raytracer
//
//  Created by Marc Bontje on 08-09-16.
//
//

#include "Light.hpp"

Light::Light() {
}

Light::Light(Color color, Vector direction, LightType type) {
    this->color = color;
    this->direction = direction;
    this->type = type;
}
