//
//  Primitive.hpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#ifndef Primitive_hpp
#define Primitive_hpp

#import "Ray.hpp"
#import "Intersection.hpp"
#import "LocalGeo.hpp"
#import "BRDF.hpp"
#import "Shape.hpp"

class Primitive {
public:
    // XXX
    BRDF brdf;

    virtual bool intersect(Ray& ray, float* thit, Intersection* in) = 0;
    virtual bool intersectP(Ray& ray) = 0;
    virtual void getBRDF(LocalGeo& local, BRDF* brdf) = 0;
};

#endif /* Primitive_hpp */
