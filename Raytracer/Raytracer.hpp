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
#import "Light.hpp"

using namespace std;

class Raytracer
{
private:
    vector<Triangle> triangles;
    vector<Light> lights;
public:
    Raytracer(vector<Triangle> triangles, vector<Light> ligths);
    void trace(Ray& ray, Color* color);
};