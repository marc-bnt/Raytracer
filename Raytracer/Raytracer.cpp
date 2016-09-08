//
//  Raytracer.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include "Raytracer.hpp"

Color Raytracer::shading(Triangle triangle, BRDF &brdf, Ray lray, Color lcolor) {
//    Vector n = local.surfaceNormal;
//    Vector l = lray.direction.normalized(); //surface->light
//
//    float NDotL = n.dot(l);
//    Vector r = -l + 2*NDotL*n; //The reflection ray
//    r = r.normalized();
//    Vector v = makeVec(local.position,eye).normalized(); //The view vector
//    Color diffuse_comp = brdf.kd*lcolor*max<float>(NDotL, 0.0f);
//    Color spec_comp = brdf.ks*lcolor*pow(max<float>(r.dot(v),0.0),brdf.sp);
//    Color ambient_comp = brdf.ka*lcolor;
//    
//    return diffuse_comp + spec_comp + ambient_comp;
    return Color(0.1, 0, 0);
}

void Raytracer::trace(Ray& ray, Color* color) {
    double t;
    
    *color = Color(0, 0, 0);
    
    //    if (depth exceed some threshold) {
    //        Make the color black and return
    //    }

    for (int i = 0; i < triangles.size(); i++) {
        Triangle triangle = triangles[i];
        
        if (!triangle.intersect(ray, &t)) {
            continue;
        }
        
        // Obtain the brdf at intersection point
        BRDF brdf = triangle.brdf;
        
        Ray lray;
        Color lcolor;
        
//        Vector view = (ray.dir * -1).normalize();
        
        // Ambient term
        *color += brdf.ka;
        
        // There is an intersection, loop through all light sources
        for (i = 0; i < lights.size(); i++) {
            lights[i].generateLightRay(triangle, &lray, &lcolor);

//            // Check if the light is blocked or not
//            if (!primitive->intersectP(lray))
//                // If not, do shading calculation for this
//                // light source
//                *color += shading(in.local, brdf, lray, lcolor);

            *color += shading(triangle, brdf, lray, lcolor);

//            // Handle mirror reflection
//            if (brdf.kr > 0) {
//                reflectRay = createReflectRay(in.local, ray);
//
//                // Make a recursive call to trace the reflected ray
//                trace(reflectRay, depth+1, &tempColor);
//                *color += brdf.kr * tempColor;
//            }
        }
    }
}

Raytracer::Raytracer(vector<Triangle> triangles, vector<Light> lights, Point eye) {
    this->triangles = triangles;
    this->lights = lights;
    this->eye = eye;
}