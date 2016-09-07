
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
    Vector v = w.cross(up);
    
    ray->pos = eye;
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
