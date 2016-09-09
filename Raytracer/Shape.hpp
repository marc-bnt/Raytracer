//
//  Shape.hpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#ifndef Shape_hpp
#define Shape_hpp

#import "Ray.hpp"
#import "LocalGeo.hpp"
#import "BRDF.hpp"

class Shape {
public:
    // XXX
    BRDF brdf;

    // Test if ray intersects with the shape or not (in object space), if so,
    // return intersection point and normal
    virtual bool intersect(Ray& ray, float* thit, LocalGeo* local) = 0;
    
    // Same as intersect, but just return whether there is any intersection or
    // not
//    virtual bool intersectP(Ray& ray) = 0;
};

#endif /* Shape_hpp */
