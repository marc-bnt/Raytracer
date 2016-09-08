//
//  Raytracer.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Raytracer.hpp"

void Raytracer::trace(Ray& ray, Color* color) {
    double t;
    
    color->r = 0.0;
    color->g = 0.0;
    color->b = 0.0;
    
    //    if (depth exceed some threshold) {
    //        Make the color black and return
    //    }

    for (int i = 0; i < triangles.size(); i++) {
        Triangle triangle = triangles[i];
        
        if (!triangle.intersect(ray, &t)) {
            continue;
        }
        
        *color = triangle.brdf.kd;
    }
    
    //    // Obtain the brdf at intersection point
    //    in.primitive->getBRDF(in.local, &brdf);
    //
    //    // There is an intersection, loop through all light source
    //    for (i = 0; i < #lights; i++) {
    //        lights[i].generateLightRay(in.local, &lray, &lcolor);
    //
    //        // Check if the light is blocked or not
    //        if (!primitive->intersectP(lray))
    //            // If not, do shading calculation for this
    //            // light source
    //            *color += shading(in.local, brdf, lray, lcolor);
    //    }
    //
    //    // Handle mirror reflection
    //    if (brdf.kr > 0) {
    //        reflectRay = createReflectRay(in.local, ray);
    //
    //        // Make a recursive call to trace the reflected ray
    //        trace(reflectRay, depth+1, &tempColor);
    //        *color += brdf.kr * tempColor;
    //    }
    
}

Raytracer::Raytracer(vector<Triangle> triangles, vector<Light> lights) {
    this->triangles = triangles;
    this->lights = lights;
}