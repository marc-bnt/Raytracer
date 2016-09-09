//
//  Vector.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#ifndef Vector_hpp
#define Vector_hpp

class Point;

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
    Vector operator+(const Point& other);
    
    Vector operator-(const Vector& other);
    Vector operator-(const Point& other);
    
    Vector operator*(const float other);

    Vector operator-() const;

    Vector(float x, float y, float z);
    Vector();
};

Vector operator*(float x, const Vector& y);

#endif /* Vector_hpp */
