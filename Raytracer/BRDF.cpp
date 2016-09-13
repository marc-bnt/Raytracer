//
//  BRDF.cpp
//  Raytracer
//
//  Created by Marc Bontje on 08-09-16.
//
//

#include "BRDF.hpp"

BRDF::BRDF() {
}

BRDF::BRDF(Color kd, Color ks, Color ka, Color ke, float shininess) {
    this->kd = kd;
    this->ks = ks;
    this->ka = ka;
    this->ke = ke;
    this->shininess = shininess;
}
