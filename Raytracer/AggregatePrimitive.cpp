//
//  AggregatePrimitive.cpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#include <stdlib.h> 
#include "float.h"
#include "AggregatePrimitive.hpp"

bool AggregatePrimitive::intersect(Ray& ray, float* thit, Intersection* in) {
    bool intersects = false;
    
    *thit = FLT_MAX;
    
    for (int i = 0; i < list.size(); i++) {
        Primitive *primitive = list[i];
        
        float geometricThit;
        Intersection geometricIntersection;
        
        if (primitive->intersect(ray, &geometricThit, &geometricIntersection)) {
            intersects = true;
            
            // Get the closest hit
            if (geometricThit < *thit) {
                *thit = geometricThit;
                *in = geometricIntersection;
            }
        }
    }
    return intersects;
}

bool AggregatePrimitive::intersectP(Ray& ray) {
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

