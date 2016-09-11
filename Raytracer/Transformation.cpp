//
//  Transformation.cpp
//  Raytracer
//
//  Created by Marc Bontje on 11-09-16.
//
//

#include "Transformation.hpp"

Transformation::Transformation() {
}

Transformation::Transformation(Matrix m) {
    this->m = m;
    //this->minvt = m.linear().inverse().transpose();
}
