//
//  Point.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#ifndef Point_hpp
#define Point_hpp

class Vector;

class Point
{
public:
    float x;
    float y;
    float z;

    double dot(const Vector& other);
    Vector operator+(const Vector& other);
    Vector operator-(const Point& other);
  
    Point();
    Point(float x, float y, float z);
};

#endif /* Point_hpp */
