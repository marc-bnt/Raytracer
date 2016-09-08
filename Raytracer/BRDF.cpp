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

BRDF::BRDF(Color kd, Color ks, Color ka, float kr) {
    this->kd = kd;
    this->ks = ks;
    this->ka = ka;
    this->kr = kr;
}
