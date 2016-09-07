//
//  Raytracer.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#import <vector>
#import "Color.hpp"
#import "Ray.hpp"
#import "Triangle.hpp"

using namespace std;

class Raytracer
{
private:
    vector<Triangle*> triangles;
public:
    Raytracer(vector<Triangle*> triangles);
    void trace(Ray& ray, int depth, Color* color);
};