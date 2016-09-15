//
//  AggregatePrimitive.cpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#include <stdlib.h> 
#include "float.h"
#include "math.h"
#include "AggregatePrimitive.hpp"

bool AggregatePrimitive::intersect(Ray& ray, float* thit, Intersection* in) {
    bool intersects = false;
    
    *thit = FLT_MAX;
    float dhit = FLT_MAX;
    
    for (int i = 0; i < list.size(); i++) {
        Primitive *primitive = list[i];
        
        float geometricThit;
        Intersection geometricIntersection;
        
        if (primitive->intersect(ray, &geometricThit, &geometricIntersection)) {
            intersects = true;
            
            Point point = geometricIntersection.localGeo.pos;
            
            // Get the closest hit
            float dist = sqrt(pow(ray.pos.x - point.x, 2) + pow(ray.pos.y - point.y, 2) + pow(ray.pos.z - point.z, 2));
            
            if(dist < dhit && geometricThit > 0) {
                dhit = dist;
                *thit = geometricThit;
                *in = geometricIntersection;
            }
        }
    }
    return intersects;
}

bool AggregatePrimitive::intersectP(Ray& ray, float* dist) {
    for (int i = 0; i < list.size(); i++) {
        Primitive *primitive = list[i];
        
        float geometricDist;

        if (primitive->intersectP(ray, &geometricDist)) {
            if (geometricDist < *dist)
                return true;
        }
    }
    
    return false;
}

void AggregatePrimitive::getBRDF(LocalGeo& local, BRDF* brdf) {
    exit(1);
    // This should never get called, because in->primitive will
    // never be an aggregate primitive
}

AggregatePrimitive::AggregatePrimitive() {
}

AggregatePrimitive::AggregatePrimitive(vector<Primitive*> list) {
    this->list = list;
}

