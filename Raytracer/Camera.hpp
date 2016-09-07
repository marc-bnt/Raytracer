//
//  Camera.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include <math.h>
#import "Ray.hpp"
#import "Sample.hpp"

class Camera
{
private:
    Point eye;
    Point center;
    Vector up;
    double width;
    double height;
public:
    double fovx;
    double fovy;
    
    void generateRay(Sample& sample, Ray* ray);
    
    Camera(Point eye, Point center, Vector up, double fovy, double width, double height);
};
