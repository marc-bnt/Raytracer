//
//  Raytracer.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include <cfloat>
#include "math.h"
#include "Raytracer.hpp"

using namespace std;

Ray Raytracer::createReflectRay(LocalGeo &local, Ray &ray) {
    Vector n = local.normal;
    Vector l = -ray.dir;
    
    return Ray(local.pos, -l + 2 * n.dot(l) * n, 0.001f, FLT_MAX);
}

Color Raytracer::shading(LocalGeo &localGeo, BRDF &brdf, Ray lray, Color lcolor) {
    Vector n = localGeo.normal;
    Vector l = lray.dir.normalize();

    float nDotL = n.dot(l);
    
    Color lambert = brdf.kd * lcolor * max(nDotL, 0.0f);
    
    Vector r = (-l + 2 * nDotL *n).normalize();
    Vector v = (eye - localGeo.pos).normalize();
    
    Color phong = brdf.ks * lcolor * pow(max(r.dot(v), 0.0), brdf.shininess);

    return lambert + phong;
}

void Raytracer::trace(Ray& ray, Color* color) {
    trace(ray, 1, color, Color(1, 1, 1));
}

void Raytracer::trace(Ray& ray, int depth, Color* color, Color component) {
    if (depth > 5) {
        *color = Color(0, 0, 0);
        return;
    }
    
    Intersection intersection = Intersection();
    
    float t;
    
    if (!primitives.intersect(ray, &t, &intersection)) {
        *color = Color(0, 0, 0);
        return;
    }
    
    // Obtain the brdf at intersection point
    BRDF brdf = intersection.primitive->brdf;
    
    // Ambient and emissive term
    *color += brdf.ka + brdf.ke;
    
    // There is an intersection, loop through all light sources
    for (int i = 0; i < lights.size(); i++) {
        Ray lray;
        Color lcolor;

        lights[i].generateLightRay(intersection.localGeo, &lray, &lcolor);

        // Check if the light is blocked or not
        if (!primitives.intersectP(lray))
            // If not, do shading calculation for this
            // light source

            *color += shading(intersection.localGeo, brdf, lray, lcolor);

        }
    
        // Handle mirror reflection
////        if (brdf.kr > 0) {
//            Ray reflectRay = createReflectRay(intersection.localGeo, ray);
//            Color tempColor = Color(0, 0, 0);
//
//            // Make a recursive call to trace the reflected ray
//            trace(reflectRay, depth + 1, &tempColor);
//            *color += tempColor;
////            *color += brdf.kr * tempColor;
////        }
}

Raytracer::Raytracer(AggregatePrimitive& primitives, vector<Light> &lights, Point eye) {
    this->primitives = primitives;
    this->lights = lights;
    this->eye = eye;
}