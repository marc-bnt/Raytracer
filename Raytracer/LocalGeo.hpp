//
//  LocalGeo.hpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#ifndef LocalGeo_hpp
#define LocalGeo_hpp

#include <stdio.h>
#include "Point.hpp"
#include "Vector.hpp"

class LocalGeo {
public:
    Point pos;
    Vector normal;
    LocalGeo();
    LocalGeo(Point pos, Vector normal);
};

#endif /* LocalGeo_hpp */
