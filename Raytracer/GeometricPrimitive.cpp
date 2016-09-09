//
//  GeometricPrimitive.cpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#include "GeometricPrimitive.hpp"

bool GeometricPrimitive::intersect(Ray& ray, float* thit, Intersection* in)  {
//    Ray oray = worldToObj*ray;
    Ray oray = ray;
    LocalGeo olocal;
    if (!shape->intersect(oray, thit, &olocal))  return false;
    in->primitive = this;
//    in->local = objToWorld*olocal;
    in->localGeo = olocal;
    return true;
}

bool GeometricPrimitive::intersectP(Ray& ray) {
//    Ray oray = worldToObj*ray;
//    return shape->intersectP(oray);
    return false;
}

void GeometricPrimitive::getBRDF(LocalGeo& local, BRDF* brdf) {
    *brdf = this->brdf;
}

GeometricPrimitive::GeometricPrimitive(Shape* shape, BRDF brdf) {
    this->shape = shape;
    this->brdf = brdf;
}
