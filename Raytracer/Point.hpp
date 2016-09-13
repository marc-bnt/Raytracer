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
    float w = 1;

    double dot(const Vector& other);
    Point operator+(const Point& other);
    
    Vector operator+(const Vector& other);
    Vector operator-(const Point& other);
  
    Point();
    Point(float x, float y, float z);
};

#endif /* Point_hpp */
