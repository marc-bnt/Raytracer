//
//  LocalGeo.cpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#include "LocalGeo.hpp"

LocalGeo::LocalGeo() {
    pos = Point(0, 0, 0);
    normal = Vector(0, 0, 0);
}

LocalGeo::LocalGeo(Point pos, Vector normal) {
    this->pos = pos;
    this->normal = normal;
}

