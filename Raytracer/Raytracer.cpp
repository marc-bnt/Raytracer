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
#include "Transformation.hpp"

using namespace std;

Ray Raytracer::createReflectRay(LocalGeo &local, Ray &ray) {
    Vector n = local.normal;
    Vector l = -ray.dir;
    
    return Ray(local.pos, -l + 2 * n.dot(l) * n, 0.001f, FLT_MAX);
}

Color Raytracer::shading(LocalGeo &localGeo, BRDF &brdf, Ray lray, Color lcolor, float attenuation) {
    Vector n = localGeo.normal;
    Vector l = lray.dir.normalize();

    float nDotL = n.dot(l);
    
    Color lambert = (brdf.kd / attenuation) * lcolor * max(nDotL, 0.0f);
    
    Vector v = (eye - localGeo.pos).normalize();
    Vector halfVec = (lray.dir + v).normalize() ;
    
    float nDotH = n.dot(halfVec);
    
    Color phong = (brdf.ks / attenuation) * lcolor * pow(max(nDotH, 0.0f), brdf.shininess);

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
        Light light = lights[i];
        Ray lray;
        Color lcolor;

        light.generateLightRay(intersection.localGeo, &lray, &lcolor);
        
        float dist = (light.position - intersection.localGeo.pos).norm();
        eye = ray.pos;
        
        // Check if the light is blocked or not
        if (!primitives.intersectP(lray, &dist)) {
            // If not, do shading calculation for this
            // light source
            float attenuation = 1;
            
            if (lights[i].type == LightPoint) {
                attenuation = light.attenuation.r + light.attenuation.g * dist + light.attenuation.b * pow(dist, 2);
            }
            
            Color pointColor = shading(intersection.localGeo, brdf, lray, lcolor, attenuation);
            *color += component * pointColor;
        }
    }
    
    if (brdf.ks > 0) {
        // Handle mirror reflection
        Ray reflected = createReflectRay(intersection.localGeo, ray);
        Color reflectionColor = Color(0, 0, 0);
        
        // Make a recursive call to trace the reflected ray
        trace(reflected, depth + 1, &reflectionColor, component * brdf.ks);
        
        *color += reflectionColor;
    }
}

Raytracer::Raytracer(AggregatePrimitive& primitives, vector<Light> &lights, Point eye) {
    this->primitives = primitives;
    this->lights = lights;
    this->eye = eye;
}
