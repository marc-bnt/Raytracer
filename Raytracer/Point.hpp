//
//  Point.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

class Vector;

class Point
{
public:
    float x;
    float y;
    float z;

    Vector operator-(const Point& other);
  
    Point();
    Point(float x, float y, float z);
};