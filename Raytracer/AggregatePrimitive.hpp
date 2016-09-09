//
//  AggregatePrimitive.hpp
//  Raytracer
//
//  Created by Marc Bontje on 09-09-16.
//
//

#ifndef AggregatePrimitive_hpp
#define AggregatePrimitive_hpp

#include <vector>
#include "Primitive.hpp"

using namespace std;

class AggregatePrimitive : public Primitive {
public:
    vector<Primitive*> list;
    
    bool intersect(Ray& ray, float* thit, Intersection* in);
    bool intersectP(Ray& ray);
    void getBRDF(LocalGeo& local, BRDF* brdf);

    AggregatePrimitive();
    AggregatePrimitive(vector<Primitive*> list);
};

#endif /* AggregatePrimitive_hpp */
