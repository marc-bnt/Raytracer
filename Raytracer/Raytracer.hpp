//
//  Raytracer.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#import <vector>
#import "Color.hpp"
#import "Ray.hpp"
#import "Sphere.hpp"
#import "Triangle.hpp"
#import "Light.hpp"
#import "AggregatePrimitive.hpp"

using namespace std;

class Raytracer
{
private:
    AggregatePrimitive primitives;
    vector<Light> lights;
    Point eye;
    
    Ray createReflectRay(LocalGeo &local, Ray &ray);
    Color shading(LocalGeo &localGeo, BRDF &brdf, Ray lray, Color lcolor, float attenuation);
    
    void trace(Ray& ray, int depth, Color* color, Color component);
public:
    void trace(Ray& ray, Color* color);

    Raytracer(AggregatePrimitive& primitives, vector<Light> &lights, Point eye);
};
