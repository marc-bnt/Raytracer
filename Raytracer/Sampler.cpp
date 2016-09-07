
//
//  Sampler.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Sampler.hpp"

bool Sampler::getSample(Sample *sample) {
    if (y > height) {
        return false;
    }
    
    sample->x = x;
    sample->y = y;
    
    if (x == width) {
        x = 0;
        y++;
    } else {
        x++;
    }
    
    return true;
}

Sampler::Sampler(float width, float height) {
    this->x = 0;
    this->y = 0;

    this->width = width;
    this->height = height;
}