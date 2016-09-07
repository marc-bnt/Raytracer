//
//  Vector.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

class Vector
{
public:
    float x;
    float y;
    float z;

    double norm();
    Vector normalize();
        
    double dot(const Vector& other);
    Vector cross(const Vector& other);
    
    Vector operator+(const Vector& other);
    Vector operator-(const Vector& other);
    
    Vector operator*(const float other);

    Vector(float x, float y, float z);
    Vector();
};