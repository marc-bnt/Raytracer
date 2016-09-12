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
#include "Triangle.hpp"
#include "LocalGeo.hpp"
#include "Matrix.hpp"

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
    
    Vector multiply = Vector(0.4, 0.5, 0.6) * 2;
    assert(compare(multiply.x, 0.8));
    assert(compare(multiply.y, 1.0));
    assert(compare(multiply.z, 1.2));
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
    
    assert(compare(ray.dir.x, -0.326214));
    assert(compare(ray.dir.y, -0.244661));
    assert(compare(ray.dir.z, -0.913086));

    sample = Sample(320, 240);
    camera->generateRay(sample, &ray);
    
    assert(compare(ray.pos.x, 0));
    assert(compare(ray.pos.y, 0));
    assert(compare(ray.pos.z, 4));
    
    assert(compare(ray.dir.x, 0));
    assert(compare(ray.dir.y, 0));
    assert(compare(ray.dir.z, -1));
    
    sample = Sample(640, 480);
    camera->generateRay(sample, &ray);

    assert(compare(ray.pos.x, 0));
    assert(compare(ray.pos.y, 0));
    assert(compare(ray.pos.z, 4));
    
    assert(compare(ray.dir.x, 0.326214));
    assert(compare(ray.dir.y, 0.244661));
    assert(compare(ray.dir.z, -0.913086));
}

void testTriangle() {
    printf("Testing triangle\n");
    
    Triangle triangle = Triangle(Point(-1, -1, 0), Point(1, -1, 0), Point(1, 1, 0));
    float t;
    
    LocalGeo local;
    Ray ray;
    
    ray = Ray(Point(0, 0, 4), Vector(-0.326214, -0.244661, -0.913086));
    assert(!triangle.intersect(ray, &t, &local));
    assert(compare(t, 4.380748));

    ray = Ray(Point(0, 0, 4), Vector(0, 0, -1));
    assert(triangle.intersect(ray, &t, &local));
    assert(compare(t, 4));

    ray = Ray(Point(0, 0, 4), Vector(0.326214, 0.244661, -0.913086));
    assert(!triangle.intersect(ray, &t, &local));
    assert(compare(t, 4.380748));
}

void testMatrix() {
    printf("Testing matrix\n");
    
    Matrix m;
    Point p;
    Vector v;

    Point mp;
    Vector mv;
    
    m = Matrix(0, 1, 2, 3,
               4, 5, 6, 7,
               8, 9, 10, 11,
               12, 13, 14, 15);
    
    assert(compare(0, m.mat[0][0]));
    assert(compare(1, m.mat[0][1]));
    assert(compare(2, m.mat[0][2]));
    assert(compare(3, m.mat[0][3]));

    assert(compare(4, m.mat[1][0]));
    assert(compare(5, m.mat[1][1]));
    assert(compare(6, m.mat[1][2]));
    assert(compare(7, m.mat[1][3]));

    assert(compare(8, m.mat[2][0]));
    assert(compare(9, m.mat[2][1]));
    assert(compare(10, m.mat[2][2]));
    assert(compare(11, m.mat[2][3]));

    assert(compare(12, m.mat[3][0]));
    assert(compare(13, m.mat[3][1]));
    assert(compare(14, m.mat[3][2]));
    assert(compare(15, m.mat[3][3]));
    
    // Matrix point translation
    m = Matrix(1, 0, 0, 2,
               0, 1, 0, 3,
               0, 0, 1, 4,
               0, 0, 0, 1);
    
    p = Point(1, 1, 1);
    mp = m * p;
    
    assert(compare(3, mp.x));
    assert(compare(4, mp.y));
    assert(compare(5, mp.z));

    // Matrix vector translation
    m = Matrix(1, 0, 0, 2,
               0, 1, 0, 3,
               0, 0, 1, 4,
               0, 0, 0, 1);
    
    v = Vector(1, 1, 1);
    mv = m * v;
    
    assert(compare(3, mv.x));
    assert(compare(4, mv.y));
    assert(compare(5, mv.z));
    
    Matrix inverse;
    
//    // Matrix inverse translation
//    m = Matrix(1, 0, 0, 2,
//               0, 1, 0, 3,
//               0, 0, 1, 4,
//               0, 0, 0, 1);
//    
//    inverse = m.inverse();
//    
//    assert(compare(1, inverse.mat[0][0]));
//    assert(compare(0, inverse.mat[0][1]));
//    assert(compare(0, inverse.mat[0][2]));
//    assert(compare(-2, inverse.mat[0][3]));
//    
//    assert(compare(0, inverse.mat[1][0]));
//    assert(compare(1, inverse.mat[1][1]));
//    assert(compare(0, inverse.mat[1][2]));
//    assert(compare(-3, inverse.mat[1][3]));
//    
//    assert(compare(0, inverse.mat[2][0]));
//    assert(compare(0, inverse.mat[2][1]));
//    assert(compare(1, inverse.mat[2][2]));
//    assert(compare(-4, inverse.mat[2][3]));
//    
//    assert(compare(0, inverse.mat[3][0]));
//    assert(compare(0, inverse.mat[3][1]));
//    assert(compare(0, inverse.mat[3][2]));
//    assert(compare(1, inverse.mat[3][3]));
    
    // Matrix transpose translation
    m = Matrix(1, 0, 0, 2,
               0, 1, 0, 3,
               0, 0, 1, 4,
               0, 0, 0, 1);
    
    Matrix transpose = m.transpose();
    
    assert(compare(1, transpose.mat[0][0]));
    assert(compare(0, transpose.mat[0][1]));
    assert(compare(0, transpose.mat[0][2]));
    assert(compare(0, transpose.mat[0][3]));
    
    assert(compare(0, transpose.mat[1][0]));
    assert(compare(1, transpose.mat[1][1]));
    assert(compare(0, transpose.mat[1][2]));
    assert(compare(0, transpose.mat[1][3]));
    
    assert(compare(0, transpose.mat[2][0]));
    assert(compare(0, transpose.mat[2][1]));
    assert(compare(1, transpose.mat[2][2]));
    assert(compare(0, transpose.mat[2][3]));
    
    assert(compare(2, transpose.mat[3][0]));
    assert(compare(3, transpose.mat[3][1]));
    assert(compare(4, transpose.mat[3][2]));
    assert(compare(1, transpose.mat[3][3]));
    
    m = Matrix(1, 0, 0, 2,
               0, 1, 0, 3,
               0, 0, 1, 4,
               0, 0, 0, 1);
    
    Matrix multiplied = m * m;

    assert(compare(1, multiplied.mat[0][0]));
    assert(compare(0, multiplied.mat[0][1]));
    assert(compare(0, multiplied.mat[0][2]));
    assert(compare(4, multiplied.mat[0][3]));
    
    assert(compare(0, multiplied.mat[1][0]));
    assert(compare(1, multiplied.mat[1][1]));
    assert(compare(0, multiplied.mat[1][2]));
    assert(compare(6, multiplied.mat[1][3]));
    
    assert(compare(0, multiplied.mat[2][0]));
    assert(compare(0, multiplied.mat[2][1]));
    assert(compare(1, multiplied.mat[2][2]));
    assert(compare(8, multiplied.mat[2][3]));
    
    assert(compare(0, multiplied.mat[3][0]));
    assert(compare(0, multiplied.mat[3][1]));
    assert(compare(0, multiplied.mat[3][2]));
    assert(compare(1, multiplied.mat[3][3]));

    m = Matrix(3, 0, 0, 2,
               0, 1, 0, 3,
               0, 0, 0.5, 4,
               0, 0, 0, 1);
    
    multiplied = m * m;
    
    assert(compare(9, multiplied.mat[0][0]));
    assert(compare(0, multiplied.mat[0][1]));
    assert(compare(0, multiplied.mat[0][2]));
    assert(compare(8, multiplied.mat[0][3]));
    
    assert(compare(0, multiplied.mat[1][0]));
    assert(compare(1, multiplied.mat[1][1]));
    assert(compare(0, multiplied.mat[1][2]));
    assert(compare(6, multiplied.mat[1][3]));
    
    assert(compare(0, multiplied.mat[2][0]));
    assert(compare(0, multiplied.mat[2][1]));
    assert(compare(0.25, multiplied.mat[2][2]));
    assert(compare(6, multiplied.mat[2][3]));
    
    assert(compare(0, multiplied.mat[3][0]));
    assert(compare(0, multiplied.mat[3][1]));
    assert(compare(0, multiplied.mat[3][2]));
    assert(compare(1, multiplied.mat[3][3]));
    
    // Transformation matrix inverse
    m = Matrix(0.707, -0.177, 0, 0,
               0.707, 0.177, 0, 0,
               0, 0, 0.25, 0.5,
               0, 0, 0, 1);
    
    inverse = m.inverse();
    
    assert(compare(0.707214, inverse.mat[0][0]));
    assert(compare(0.707214, inverse.mat[0][1]));
    assert(compare(0, inverse.mat[0][2]));
    assert(compare(0, inverse.mat[0][3]));
    
    assert(compare(-2.824858, inverse.mat[1][0]));
    assert(compare(2.824858, inverse.mat[1][1]));
    assert(compare(0, inverse.mat[1][2]));
    assert(compare(0, inverse.mat[1][3]));
    
    assert(compare(0, inverse.mat[2][0]));
    assert(compare(0, inverse.mat[2][1]));
    assert(compare(4, inverse.mat[2][2]));
    assert(compare(-2, inverse.mat[2][3]));
    
    assert(compare(0, inverse.mat[3][0]));
    assert(compare(0, inverse.mat[3][1]));
    assert(compare(0, inverse.mat[3][2]));
    assert(compare(1, inverse.mat[3][3]));
}

void testAll() {
    printf("Runnig tests\n");
    
    testVector();
    testPoint();
    testCamera();
    testTriangle();
    testMatrix();
    
    printf("All tests passed\n");
}