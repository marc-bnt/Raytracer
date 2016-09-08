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
    float kr; // mirror reflection coefficient
    BRDF();
    BRDF(Color kd, Color ks, Color ka, float kr);
};

#endif /* BRDF_hpp */
