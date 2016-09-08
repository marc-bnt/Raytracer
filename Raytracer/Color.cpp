//
//  Color.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Color.hpp"

Color Color::operator+(const Color& other) {
    return Color(r + other.r, g + other.g, b + other.b);
}

Color& Color::operator+=(const Color& other) {
    r += other.r; g += other.g; b += other.b;
    return *this;
}

Color::Color() {
}

Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}