//
//  GeometricPrimitive.cpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#include "math.h"
#include "GeometricPrimitive.hpp"

bool GeometricPrimitive::intersect(Ray& ray, float* thit, Intersection* in)  {
    Ray oray = (*worldToObj) * ray;
    LocalGeo olocal;
    
    if (!shape->intersect(oray, thit, &olocal)) {
        return false;
    }
    
    in->primitive = this;
    in->localGeo = (*objToWorld) * olocal;
    return true;
}

bool GeometricPrimitive::intersectP(Ray& ray, float* dist) {
    Ray oray = (*worldToObj) * ray;
    LocalGeo olocal;
    
    if (!shape->intersectP(oray, &olocal)) {
        return false;
    }
    
    LocalGeo local = (*objToWorld) * olocal;
    Point point = local.pos;

    *dist = sqrt(pow(ray.pos.x - point.x, 2) + pow(ray.pos.y - point.y, 2) + pow(ray.pos.z - point.z, 2));
    return true;
}

void GeometricPrimitive::getBRDF(LocalGeo& local, BRDF* brdf) {
    *brdf = this->brdf;
}

GeometricPrimitive::GeometricPrimitive(Transformation *objToWorld, Shape* shape, BRDF brdf) {
    this->objToWorld = objToWorld;
    this->worldToObj = new Transformation((*objToWorld).m.inverse());
    this->shape = shape;
    this->brdf = brdf;
}
