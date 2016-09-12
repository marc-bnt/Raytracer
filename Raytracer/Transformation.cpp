//
//  Transformation.cpp
//  Raytracer
//
//  Created by Marc Bontje on 11-09-16.
//
//

#include "Transformation.hpp"

Ray Transformation::operator*(const Ray& other) {
    return Ray(m * other.pos, (m.linear() * other.dir));
}

LocalGeo Transformation::operator*(const LocalGeo& other) {
    return LocalGeo(m * other.pos, (minvt.linear() * other.normal).normalize());
}

Transformation::Transformation() {
}

Transformation::Transformation(Matrix m) {
    this->m = m;
    this->minvt = m.linear().inverse().transpose();
}
