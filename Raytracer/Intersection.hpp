//
//  Intersection.hpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#ifndef Intersection_hpp
#define Intersection_hpp

#import "LocalGeo.hpp"

class Primitive;

class Intersection  {
public:
    LocalGeo localGeo;
    Primitive* primitive;
    Intersection();
};

#endif /* Intersection_hpp */
