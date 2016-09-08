
//  Camera.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Camera.hpp"

void Camera::generateRay(Sample& sample, Ray* ray) {
    Vector w = (eye - center).normalize();
    Vector u = up.cross(w).normalize();
    Vector v = u.cross(w);
    
    float alpha = tan(fovx / 2) * ((sample.x - (width / 2)) / (width / 2));
    float beta = tan(fovy / 2) * (((height / 2) - sample.y) / (height / 2));
    
    ray->pos = eye;
    ray->dir = (u * alpha + v * beta - w).normalize();
}

Camera::Camera(Point eye, Point center, Vector up, double fovy, double width, double height) {
    this->eye = eye;
    this->center = center;
    this->up = up;

    this->fovy = fovy * M_PI / 180;
    this->fovx = 2 * atan(tan(this->fovy / 2) * (width / height));
    
    this->width = width;
    this->height = height;
}
