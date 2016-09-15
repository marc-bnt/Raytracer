//
//  GeometricPrimitive.hpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#ifndef GeometricPrimitive_hpp
#define GeometricPrimitive_hpp

#include "Primitive.hpp"
#include "Transformation.hpp"

class GeometricPrimitive : public Primitive {
private:
    Shape* shape;
public:
    Transformation *objToWorld;
    Transformation *worldToObj;

    bool intersect(Ray& ray, float* thit, Intersection* in);
    bool intersectP(Ray& ray, float* dist);
    void getBRDF(LocalGeo& local, BRDF* brdf);
    
    GeometricPrimitive(Transformation *objToWorld, Shape* shape, BRDF brdf);
};

#endif /* GeometricPrimitive_hpp */
