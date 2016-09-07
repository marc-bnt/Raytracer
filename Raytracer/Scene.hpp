//
//  Scene.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include <vector>
#include <sstream>
#include "Camera.hpp"
#include "Triangle.hpp"

using namespace std;

class Scene
{
private:
    const char* output;
    float width;
    float height;
    Camera* camera;
    
    vector<Triangle*> triangles;
    
    bool readvals(stringstream &s, const int numvals, double* values);

public:
    Scene(const char* input, const char* output);
    void render();
};