//
//  Raytracer.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Raytracer.hpp"

void Raytracer::trace(Ray& ray, int depth, Color* color) {
    for (int i = 0; i < triangles.size(); i++) {
        Triangle *triangle = triangles[i];
        
    	double t1 =-2;
    
        if (triangle->intersect(ray, &t1)) {
            color->g = 1.0;
        }
    }
    
    //    if (depth exceed some threshold) {
    //        Make the color black and return
    //    }
    //    if (!primitive.intersect(ray, &thit, &in) {
    //        // No intersection
    //        Make the color black and return
    //    }
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

Raytracer::Raytracer(vector<Triangle*> triangles) {
    this->triangles = triangles;
}