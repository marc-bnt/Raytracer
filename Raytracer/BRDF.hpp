//
//  BRDF.hpp
//  Raytracer
//
//  Created by Marc Bontje on 08-09-16.
//
//

#ifndef BRDF_hpp
#define BRDF_hpp

#include <stdio.h>
#include "Color.hpp"

class BRDF {
public:
    Color kd; // diffuse
    Color ks; // specular
    Color ka; // ambient
    Color ke; // emission
    float shininess;
    BRDF();
    BRDF(Color kd, Color ks, Color ka, Color ke, float emission);
};

#endif /* BRDF_hpp */
