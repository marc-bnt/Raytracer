//
//  test.cpp
//  Raytracer
//
//  Created by Marc Bontje on 07-09-16.
//
//

#include <cassert>
#include "test.hpp"
#include "Camera.hpp"

#define EPSILON 0.000001

bool compare(double a, double b) {
    return fabs(a - b) < EPSILON;
}

void testVector() {
    printf("Testing vector\n");
    
    float norm;
    
    norm = Vector(1.0, 0.0, 0.0).norm();
    assert(compare(1.0, norm));
    
    norm = Vector(0.5, 0.5, 0.5).norm();
    assert(compare(norm, 0.866025));
    
    norm = Vector(0.0, 0.0, 0.0).norm();
    assert(compare(norm, 0.0));
    
    Vector normalized;
    
    normalized = Vector(1.0, 0.0, 0.0).normalize();
    assert(compare(normalized.x, 1.0));
    assert(compare(normalized.y, 0.0));
    assert(compare(normalized.z, 0.0));
    
    normalized = Vector(1.0, 0.0, 1.0).normalize();
    assert(compare(normalized.x, 1 / sqrt(2)));
    assert(compare(normalized.y, 0.0));
    assert(compare(normalized.z, 1 / sqrt(2)));
    
    normalized = Vector(0.0, 0.0, 0.0).normalize();
    assert(compare(normalized.x, 0.0));
    assert(compare(normalized.y, 0.0));
    assert(compare(normalized.z, 0.0));
    
    assert(compare(Vector(1.0, 0.0, 0.0).dot(Vector(0.0, 1.0, 0.0)), 0.0));
    assert(compare(Vector(1.0, 0.0, 0.0).dot(Vector(0.5, 0.5, 0.0)), 0.5));
    assert(compare(Vector(1.0, 0.0, 0.0).dot(Vector(1.0, 0.0, 0.0)), 1.0));

    Vector cross;
    
    cross = Vector(1.0, 0.0, 0.0).cross(Vector(0.0, 1.0, 0.0));
    assert(compare(cross.x, 0.0));
    assert(compare(cross.y, 0.0));
    assert(compare(cross.z, 1.0));
    
    cross = Vector(1.0, 0.0, 0.0).cross(Vector(0.5, 0.5, 0.0));
    assert(compare(cross.x, 0.0));
    assert(compare(cross.y, 0.0));
    assert(compare(cross.z, 0.5));
    
    cross = Vector(1.0, 0.0, 0.0).cross(Vector(1.0, 0.0, 0.0));
    assert(compare(cross.x, 0.0));
    assert(compare(cross.y, 0.0));
    assert(compare(cross.z, 0.0));
    
    Vector add = Vector(0.1, 0.2, 0.3) + Vector(0.4, 0.5, 0.6);
    assert(compare(add.x, 0.5));
    assert(compare(add.y, 0.7));
    assert(compare(add.z, 0.9));
    
    Vector subtract = Vector(0.4, 0.5, 0.6) - Vector(0.1, 0.2, 0.3);
    assert(compare(subtract.x, 0.3));
    assert(compare(subtract.y, 0.3));
    assert(compare(subtract.z, 0.3));
}

void testPoint() {
    printf("Testing point\n");
    
    Vector subtract = Point(0.4, 0.5, 0.6) - Point(0.1, 0.2, 0.3);
    assert(compare(subtract.x, 0.3));
    assert(compare(subtract.y, 0.3));
    assert(compare(subtract.z, 0.3));
}

void testCamera() {
    printf("Testing camera\n");
    
    Point eye = Point(0, 0, 4);
    Point center = Point(0, 0, 0);
    Vector up = Vector(0, 1, 0);

    double fovy = 30;
    double width = 640;
    double height = 480;

    Camera* camera = new Camera(eye, center, up, fovy, width, height);

    assert(compare(camera->fovy, M_PI / 6));
    assert(compare(camera->fovx, 0.686265));

    Ray ray;
    Sample sample;
    
    sample = Sample(0,0);
    camera->generateRay(sample, &ray);
    
    assert(compare(ray.pos.x, 0));
    assert(compare(ray.pos.y, 0));
    assert(compare(ray.pos.z, 4));
    
    sample = Sample(320, 240);
    camera->generateRay(sample, &ray);
    
    sample = Sample(640, 480);
    camera->generateRay(sample, &ray);
}

void testAll() {
    printf("Runnig tests\n");
    
    testVector();
    testPoint();
    testCamera();
    
    printf("All tests passed\n");
}