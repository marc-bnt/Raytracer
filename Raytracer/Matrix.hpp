//
//  Matrix.hpp
//  Raytracer
//
//  Created by Marc Bontje on 11-09-16.
//
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include "Point.hpp"
#include "Vector.hpp"

class Matrix
{
public:
    float mat[4][4];
    
    Matrix inverse();
    Matrix transpose();
    
    Point operator*(const Point& point);
    Vector operator*(const Vector& vector);
    Matrix operator*(const Matrix& other);

    Matrix operator-() const;

    Matrix();
    
    Matrix(float r0c0, float r0c1, float r0c2, float r0c3,
           float r1c0, float r1c1, float r1c2, float r1c3,
           float r2c0, float r2c1, float r2c2, float r2c3,
           float r3c0, float r3c1, float r3c2, float r3c3);
};

#endif /* Matrix_hpp */
