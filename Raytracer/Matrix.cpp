//
//  Matrix.cpp
//  Raytracer
//
//  Created by Marc Bontje on 11-09-16.
//
//

#include "Matrix.hpp"
#include "math.h"

Matrix Matrix::linear() {
    return Matrix(mat[0][0], mat[0][1], mat[0][2], 0,
                  mat[1][0], mat[1][1], mat[1][2], 0,
                  mat[2][0], mat[2][1], mat[2][2], 0,
                  0, 0, 0, 0);
}

Matrix Matrix::inverse() {
    Matrix a(*this);
    Matrix b(1, 0, 0, 0,
             0, 1, 0, 0,
             0, 0, 1, 0,
             0, 0, 0, 1);
    
    int i, j, i1;
    
    for (j = 0; j < 4; j++) {
        i1 = j;
        
        for (i = j + 1; i < 4; i++) {
            if (fabs(a.mat[i][j]) > fabs(a.mat[i1][j]))
                i1 = i;
        }
        
        float tmp[4];
        
        tmp[0] = a.mat[i1][0];
        tmp[1] = a.mat[i1][1];
        tmp[2] = a.mat[i1][2];
        tmp[3] = a.mat[i1][3];
        
        a.mat[i1][0] = a.mat[j][0];
        a.mat[i1][1] = a.mat[j][1];
        a.mat[i1][2] = a.mat[j][2];
        a.mat[i1][3] = a.mat[j][3];
        
        a.mat[j][0] = tmp[0];
        a.mat[j][1] = tmp[1];
        a.mat[j][2] = tmp[2];
        a.mat[j][3] = tmp[3];

        tmp[0] = b.mat[i1][0];
        tmp[1] = b.mat[i1][1];
        tmp[2] = b.mat[i1][2];
        tmp[3] = b.mat[i1][3];
        
        b.mat[i1][0] = b.mat[j][0];
        b.mat[i1][1] = b.mat[j][1];
        b.mat[i1][2] = b.mat[j][2];
        b.mat[i1][3] = b.mat[j][3];
        
        b.mat[j][0] = tmp[0];
        b.mat[j][1] = tmp[1];
        b.mat[j][2] = tmp[2];
        b.mat[j][3] = tmp[3];

        float div = a.mat[j][j];
        
        b.mat[j][0] /= div;
        b.mat[j][1] /= div;
        b.mat[j][2] /= div;
        b.mat[j][3] /= div;
        
        a.mat[j][0] /= div;
        a.mat[j][1] /= div;
        a.mat[j][2] /= div;
        a.mat[j][3] /= div;
        
        for (i = 0; i < 4; i++) {
            if (i != j) {
                float tmpB[4];
                float tmpA[4];
                
                tmpB[0] = a.mat[i][j] * b.mat[j][0];
                tmpB[1] = a.mat[i][j] * b.mat[j][1];
                tmpB[2] = a.mat[i][j] * b.mat[j][2];
                tmpB[3] = a.mat[i][j] * b.mat[j][3];
                
                tmpA[0] = a.mat[i][j] * a.mat[j][0];
                tmpA[1] = a.mat[i][j] * a.mat[j][1];
                tmpA[2] = a.mat[i][j] * a.mat[j][2];
                tmpA[3] = a.mat[i][j] * a.mat[j][3];
                
                b.mat[i][0] -= tmpB[0];
                b.mat[i][1] -= tmpB[1];
                b.mat[i][2] -= tmpB[2];
                b.mat[i][3] -= tmpB[3];

                a.mat[i][0] -= tmpA[0];
                a.mat[i][1] -= tmpA[1];
                a.mat[i][2] -= tmpA[2];
                a.mat[i][3] -= tmpA[3];
            }
        }
    }

    return b;
}

Matrix Matrix::transpose() {
    return Matrix(mat[0][0], mat[1][0], mat[2][0], mat[3][0],
                  mat[0][1], mat[1][1], mat[2][1], mat[3][1],
                  mat[0][2], mat[1][2], mat[2][2], mat[3][2],
                  mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
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

Matrix Matrix::operator*(const Matrix& other) {
    return Matrix(mat[0][0] * other.mat[0][0] + mat[0][1] * other.mat[1][0] + mat[0][2] * other.mat[2][0] + mat[0][3] * other.mat[3][0],
                  mat[0][0] * other.mat[0][1] + mat[0][1] * other.mat[1][1] + mat[0][2] * other.mat[2][1] + mat[0][3] * other.mat[3][1],
                  mat[0][0] * other.mat[0][2] + mat[0][1] * other.mat[1][2] + mat[0][2] * other.mat[2][2] + mat[0][3] * other.mat[3][2],
                  mat[0][0] * other.mat[0][3] + mat[0][1] * other.mat[1][3] + mat[0][2] * other.mat[2][3] + mat[0][3] * other.mat[3][3],
                  
                  mat[1][0] * other.mat[0][0] + mat[1][1] * other.mat[1][0] + mat[1][2] * other.mat[2][0] + mat[1][3] * other.mat[3][0],
                  mat[1][0] * other.mat[0][1] + mat[1][1] * other.mat[1][1] + mat[1][2] * other.mat[2][1] + mat[1][3] * other.mat[3][1],
                  mat[1][0] * other.mat[0][2] + mat[1][1] * other.mat[1][2] + mat[1][2] * other.mat[2][2] + mat[1][3] * other.mat[3][2],
                  mat[1][0] * other.mat[0][3] + mat[1][1] * other.mat[1][3] + mat[1][2] * other.mat[2][3] + mat[1][3] * other.mat[3][3],
                  
                  mat[2][0] * other.mat[0][0] + mat[2][1] * other.mat[1][0] + mat[2][2] * other.mat[2][0] + mat[2][3] * other.mat[3][0],
                  mat[2][0] * other.mat[0][1] + mat[2][1] * other.mat[1][1] + mat[2][2] * other.mat[2][1] + mat[2][3] * other.mat[3][1],
                  mat[2][0] * other.mat[0][2] + mat[2][1] * other.mat[1][2] + mat[2][2] * other.mat[2][2] + mat[2][3] * other.mat[3][2],
                  mat[2][0] * other.mat[0][3] + mat[2][1] * other.mat[1][3] + mat[2][2] * other.mat[2][3] + mat[2][3] * other.mat[3][3],
                  
                  mat[3][0] * other.mat[0][0] + mat[3][1] * other.mat[1][0] + mat[3][2] * other.mat[2][0] + mat[3][3] * other.mat[3][0],
                  mat[3][0] * other.mat[0][1] + mat[3][1] * other.mat[1][1] + mat[3][2] * other.mat[2][1] + mat[3][3] * other.mat[3][1],
                  mat[3][0] * other.mat[0][2] + mat[3][1] * other.mat[1][2] + mat[3][2] * other.mat[2][2] + mat[3][3] * other.mat[3][2],
                  mat[3][0] * other.mat[0][3] + mat[3][1] * other.mat[1][3] + mat[3][2] * other.mat[2][3] + mat[3][3] * other.mat[3][3]);
}

Matrix Matrix::operator-() const {
    return Matrix(-mat[0][0], -mat[0][1], -mat[0][2], -mat[0][3],
                  -mat[1][0], -mat[1][1], -mat[1][2], -mat[1][3],
                  -mat[2][0], -mat[2][1], -mat[2][2], -mat[2][3],
                  -mat[3][0], -mat[3][1], -mat[3][2], -mat[3][3]);
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

