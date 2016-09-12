//
//  Transformation.hpp
//  Raytracer
//
//  Created by Marc Bontje on 11-09-16.
//
//

#ifndef Transformation_hpp
#define Transformation_hpp

#include <stdio.h>
#include "Matrix.hpp"
#include "Ray.hpp"
#include "LocalGeo.hpp"

class Transformation
{
public:
    Matrix m;
    
    // The inverse transpose of m
    Matrix minvt;

    Ray operator*(const Ray& other);
    LocalGeo operator*(const LocalGeo& other);

    Transformation();
    Transformation(Matrix m);
};

#endif /* Transformation_hpp */
