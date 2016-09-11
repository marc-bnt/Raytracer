//
//  Matrix.cpp
//  Raytracer
//
//  Created by Marc Bontje on 11-09-16.
//
//

#include "Matrix.hpp"

Matrix Matrix::inverse() {
    return *this;  // TODO
}

Point Matrix::operator*(const Point& point) {
    return Point(mat[0][0] * point.x + mat[0][1] * point.y + mat[0][2] * point.z + mat[0][3],
                 mat[1][0] * point.x + mat[1][1] * point.y + mat[1][2] * point.z + mat[1][3],
                 mat[2][0] * point.x + mat[2][1] * point.y + mat[2][2] * point.z + mat[2][3]);
}

Vector Matrix::operator*(const Vector& vector) {
    return Vector(mat[0][0] * vector.x + mat[0][1] * vector.y + mat[0][2] * vector.z + mat[0][3],
                  mat[1][0] * vector.x + mat[1][1] * vector.y + mat[1][2] * vector.z + mat[1][3],
                  mat[2][0] * vector.x + mat[2][1] * vector.y + mat[2][2] * vector.z + mat[2][3]);
}

Matrix::Matrix() {
}

Matrix::Matrix(float r0c0, float r0c1, float r0c2, float r0c3,
       float r1c0, float r1c1, float r1c2, float r1c3,
       float r2c0, float r2c1, float r2c2, float r2c3,
       float r3c0, float r3c1, float r3c2, float r3c3) {
    
    mat[0][0] = r0c0;
    mat[0][1] = r0c1;
    mat[0][2] = r0c2;
    mat[0][3] = r0c3;
    
    mat[1][0] = r1c0;
    mat[1][1] = r1c1;
    mat[1][2] = r1c2;
    mat[1][3] = r1c3;
    
    mat[2][0] = r2c0;
    mat[2][1] = r2c1;
    mat[2][2] = r2c2;
    mat[2][3] = r2c3;
    
    mat[3][0] = r3c0;
    mat[3][1] = r3c1;
    mat[3][2] = r3c2;
    mat[3][3] = r3c3;
}

