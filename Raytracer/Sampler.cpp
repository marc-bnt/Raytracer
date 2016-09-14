
//
//  Sampler.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Sampler.hpp"

bool Sampler::getSample(Sample *sample) {
//    sample->x = 190.5;
//    sample->y = 403.5;
//    return true;

    if (y > height) {
        return false;
    }
    
    sample->x = x;
    sample->y = y;
    
    if (x == width + 0.5) {
        x = 0.5;
        y++;
    } else {
        x++;
    }
    
    return true;
}

Sampler::Sampler(float width, float height) {
    this->x = 0.5;
    this->y = 0.5;

    this->width = width;
    this->height = height;
}