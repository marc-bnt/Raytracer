//
//  Vector.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "math.h"
#include "Vector.hpp"
#include "Point.hpp"

double Vector::norm() {
    return (double) sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vector Vector::normalize() {
    double norm = this->norm();
    
    if (norm == 0.0)
        return Vector(0.0, 0.0, 0.0);
    
    return Vector(this->x / norm, this->y / norm, this->z / norm);
}

double Vector::dot(const Vector& other) {
    return (double) x * other.x + y * other.y + z * other.z;
}

Vector Vector::cross(const Vector& other) {
    return Vector(y * other.z - other.y * z,
                  z * other.x - other.z * x,
                  x * other.y - other.x * y);
}

Vector Vector::operator+(const Vector& other) {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator+(const Point& other) {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-() const {
    return Vector(-x, -y, -z);
}

Vector Vector::operator-(const Vector& other) {
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator-(const Point& other) {
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator*(const float other) {
    return Vector(x * other, y * other, z * other);
}

Vector operator*(float x, const Vector& y) {
    return Vector(x * y.x, x * y.y, x * y.z);
}

Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector() {
}
