//
//  Color.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#ifndef Color_hpp
#define Color_hpp

class Color
{
public:
    float r;
    float g;
    float b;
    Color();
    Color(float r, float g, float b);
    
    Color operator*(const Color& other);
    Color operator*(const float other);

    Color operator+(const Color& other);
    Color& operator+=(const Color& other);
};

#endif /* Color_hpp */
