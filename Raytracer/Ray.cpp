//
//  Ray.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Ray.hpp"

Ray::Ray() {
}

Ray::Ray(Point pos, Vector dir) {
    this->pos = pos;
    this->dir = dir;
}
