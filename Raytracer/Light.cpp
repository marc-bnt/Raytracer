//
//  Light.cpp
//  Raytracer
//
//  Created by Marc Bontje on 08-09-16.
//
//

#include <cfloat>
#include "Light.hpp"

void Light::generateLightRay(LocalGeo& localGeo, Ray* lray, Color* lcolor) {
    *lcolor = this->color;

    switch (type) {
        case LightDirectional:
            lray->pos = localGeo.pos;
            lray->dir = -direction;
            lray->tMin = 0.01f;
            lray->tMax = FLT_MAX;
            break;
            
        case LightPoint:
            lray->pos = localGeo.pos;
            lray->dir = position - localGeo.pos;
            lray->tMin = 0.01f;
            lray->tMax = 1.0;
            break;
    }
}

Light::Light() {
}

Light::Light(Vector direction, Color color) {
    this->color = color;
    this->position = Point(0, 0, 0);
    this->direction = direction;
    this->type = LightDirectional;
}

Light::Light(Point position, Color color) {
    this->color = color;
    this->position = position;
    this->direction = Vector(0, 0, 0);
    this->type = LightPoint;
}
