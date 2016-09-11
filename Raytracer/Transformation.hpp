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

class Transformation
{
public:
    Matrix m;
    
    // The inverse transpose of m
    Matrix minvt;

    Transformation();
    Transformation(Matrix m);
};

#endif /* Transformation_hpp */
