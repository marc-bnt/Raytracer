//
//  Raytracer.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "math.h"
#include "Raytracer.hpp"

using namespace std;

Color Raytracer::shading(LocalGeo &localGeo, BRDF &brdf, Ray lray, Color lcolor) {
    Vector n = localGeo.normal;
    Vector l = lray.dir.normalize();

    float nDotL = n.dot(l);
    
    Color lambert = brdf.kd * lcolor * max(nDotL, 0.0f);
    
    Vector r = (-l + 2 * nDotL *n).normalize();
    Vector v = (eye - localGeo.pos).normalize();
    
    Color phong = brdf.ks * lcolor * pow(max(r.dot(v), 0.0), 2);

    return lambert + phong;
}

void Raytracer::trace(Ray& ray, Color* color) {
    //    if (depth exceed some threshold) {
    //        Make the color black and return
    //    }
    
    Intersection intersection = Intersection();
    
    float t;
    
    if (!primitives.intersect(ray, &t, &intersection)) {
        *color = Color(0, 0, 0);
        return;
    }
    
    // Obtain the brdf at intersection point
    BRDF brdf = intersection.primitive->brdf;
    
    // Ambient term
    *color += brdf.ka;
    
    // There is an intersection, loop through all light sources
    for (int i = 0; i < lights.size(); i++) {
        Ray lray;
        Color lcolor;

        lights[i].generateLightRay(intersection.localGeo, &lray, &lcolor);

//            // Check if the light is blocked or not
//            if (!primitive->intersectP(lray))
//                // If not, do shading calculation for this
//                // light source
//                *color += shading(in.local, brdf, lray, lcolor);

                *color += shading(intersection.localGeo, brdf, lray, lcolor);

//            // Handle mirror reflection
//            if (brdf.kr > 0) {
//                reflectRay = createReflectRay(in.local, ray);
//
//                // Make a recursive call to trace the reflected ray
//                trace(reflectRay, depth+1, &tempColor);
//                *color += brdf.kr * tempColor;
//            }
    }

//    for (int i = 0; i < triangles.size(); i++) {
//        Triangle triangle = triangles[i];
//        
////        if (!triangle.intersect(ray, &t)) {
//            continue;
////        }
//        
//        if (lights.size() == 0)
//            continue;
//            


}

Raytracer::Raytracer(AggregatePrimitive& primitives, vector<Light> &lights, Point eye) {
    this->primitives = primitives;
    this->lights = lights;
    this->eye = eye;
}