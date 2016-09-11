//
//  Scene.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include <iostream>
#include <fstream>
#include "Scene.hpp"
#include "Film.hpp"
#include "Ray.hpp"
#include "Sampler.hpp"
#include "Raytracer.hpp"
#include "BRDF.hpp"
#include "Transformation.hpp"

using namespace std;

// This is the main rendering loop
void Scene::render() {
    Sampler* sampler = new Sampler(width, height);
    Film* film = new Film(output, width, height);
    
    Raytracer *raytracer = new Raytracer(aggregate, lights, camera->eye);
    
    Ray ray;
    Sample sample;
    while (sampler->getSample(&sample)) {
        Color color = Color(0, 0, 0);

        camera->generateRay(sample, &ray);
        raytracer->trace(ray, &color);
        film->commit(sample, color);
    }
    
    film->writeImage();
}

Scene::Scene(const char* input, const char* output) {
    this->output = output;
    
    string str, cmd;
    ifstream in;
    
    vector<Point> vertices;
    BRDF brdf;
    
    in.open(input);
    
    if (in.is_open()) {
        getline(in, str);
        
        while (in) {
            // Rule out comment and blank lines
            if ((str.find_first_not_of(" \t\r\n") != std::string::npos) && (str[0] != '#')) {
                stringstream s(str);
                
                s >> cmd;

                // Position and color for light, colors for others
                double values[10];
                bool validinput;
                
                if (cmd == "directional") {
                    validinput = readvals(s, 6, values);
                    if (validinput) {
//                        vec3 posn = vec3(values[0],values[1],values[2]);
//                        vec3 col = vec3(values[3],values[4],values[5]);
//                        vec3 dir = vec3(transfstack.top() * vec4(posn, 0), 3);
//                        Light light = Light(dir,col,0);
                        
                        Vector direction = Vector(values[0],values[1],values[2]);
                        Color color = Color(values[3],values[4],values[5]);

                        lights.push_back(Light(direction, color));
                    }
                    
                }
                
                else if (cmd == "point") {
                    validinput = readvals(s, 6, values);
                    if (validinput) {
//                        
//                        vec3 posn = vec3(values[0],values[1],values[2]);
//                        vec3 col = vec3(values[3],values[4],values[5]);
//                        vec3 dir = vec3(transfstack.top() * vec4(posn, 1));
//                        Light light = Light(dir,col,1,attenuation);
//                        
                        Point position = Point(values[0],values[1],values[2]);
                        Color color = Color(values[3],values[4],values[5]);
                        
                        lights.push_back(Light(position, color));
                    }
                }
                else if (cmd == "attenuation") {
                    validinput = readvals(s, 3, values);
                    if (validinput) {
//                        attenuation = vec3(values[0],values[1],values[2]);
                    }
                }
                
                else if (cmd == "maxdepth") {
                    validinput = readvals(s,1,values);
                    if (validinput) {
//                        maxdepth = values[0];
                    }
                }
                
                else if (cmd == "size") {
                    validinput = readvals(s,2,values);
                    if (validinput) {
                        width = values[0];
                        height = values[1];
                        
//                        pixels = vec2(values[0],values[1]);
//                        film = new Film(pixels);
                    }
                }
                else if (cmd == "output") {
//                    s>>name;
                }
                else if (cmd == "camera") {
                    validinput = readvals(s,10,values);
                    if (validinput) {
                        camera = new Camera(Point(values[0],values[1],values[2]), Point(values[3],values[4],values[5]), Vector(values[6],values[7],values[8]), values[9], width, height);
                    }
                }
                
                else if (cmd == "sphere") {
                    validinput = readvals(s,4,values);
                    if (validinput) {
//                        Sphere sphere = Sphere( vec3(values[0],values[1],values[2]), values[3]);
//                        sphere.setBSDF(ambient, diffuse, specular, emission, shininess);
//                        sphere.setTransform(transfstack.top());
//                        spheres.push_back (sphere);
                        
                        Sphere* sphere = new Sphere(Point(values[0],values[1],values[2]), values[3]);
                        Matrix transform = Matrix();

                        GeometricPrimitive *primitive = new GeometricPrimitive(new Transformation(transform), sphere, BRDF(brdf.kd, brdf.ks, brdf.ka, brdf.kr));

                        aggregate.list.push_back(primitive);
                    }
                }
                else if (cmd == "tri") {
                    validinput = readvals(s,3,values);
                    if (validinput) {
//                        vec4 temp0 = vec4(vertices[(int)values[0]]);
//                        vec4 temp1 = vec4(vertices[(int)values[1]]);
//                        vec4 temp2 = vec4(vertices[(int)values[2]]);
//                        
//                        vec3 vert0 = vec3(transfstack.top() * temp0);
//                        vec3 vert1 = vec3(transfstack.top() * temp1);
//                        vec3 vert2 = vec3(transfstack.top() * temp2);
//                        
                        Point vert0 = vertices[(int) values[0]];
                        Point vert1 = vertices[(int) values[1]];
                        Point vert2 = vertices[(int) values[2]];

                        Triangle* triangle = new Triangle(vert0, vert1, vert2);
                        
                        Vector translation = Vector(1, 0, 0);
                        Matrix transform = Matrix(1, 0, 0, translation.x,
                                                  0, 1, 0, translation.y,
                                                  0, 0, 1, translation.z,
                                                  1, 0, 0, 1);
                        
                        GeometricPrimitive *primitive = new GeometricPrimitive(new Transformation(transform), triangle, BRDF(brdf.kd, brdf.ks, brdf.ka, brdf.kr));
                        aggregate.list.push_back(primitive);
                    }
                }
                else if(cmd == "maxverts"){
                    validinput = readvals(s,1,values);
                    if (validinput){
                    }
                }
                else if(cmd == "vertex") {
                    validinput = readvals(s,3,values);
                    if (validinput){
                        vertices.push_back(Point(values[0],values[1],values[2]));
                    }
                }
                else if (cmd == "ambient") {
                    validinput = readvals(s, 3, values); // colors
                    if (validinput) {
                        brdf.ka = Color(values[0],values[1],values[2]);
                    }
                } else if (cmd == "diffuse") {
                    validinput = readvals(s, 3, values);
                    if (validinput) {
                        brdf.kd = Color(values[0],values[1],values[2]);
                    }
                } else if (cmd == "specular") {
                    validinput = readvals(s, 3, values);
                    if (validinput) {
                        brdf.ks = Color(values[0],values[1],values[2]);
                    }
                } else if (cmd == "emission") {
                    validinput = readvals(s, 3, values);
                    if (validinput) {
//                        emission = vec3(values[0],values[1],values[2]);
                    }
                } else if (cmd == "shininess") {
                    validinput = readvals(s, 1, values);
                    if (validinput) {
//                        shininess = values[0];
                    }
                }
                else if (cmd == "translate") {
                    validinput = readvals(s,3,values);
                    if (validinput) {
//                        vec3 t = vec3(values[0],values[1],values[2]);
//                        
//                        
//                        mat4 m = transfstack.top() * translation3D(t);
//                        transfstack.pop();
//                        transfstack.push(m);
                    }
                }
                else if (cmd == "scale") {
                    validinput = readvals(s,3,values); 
                    if (validinput) {
//                        vec3 t = vec3(values[0],values[1],values[2]);
//                        
//                        
//                        mat4 m = transfstack.top() * scaling3D(t);
//                        transfstack.pop();
//                        transfstack.push(m);
                    }
                }
                else if (cmd == "rotate") {
                    validinput = readvals(s,4,values); 
                    if (validinput) {
//                        vec3 axis = vec3(values[0],values[1],values[2]);
//                        double ang = values[3];
//                        
//                        mat4 m = transfstack.top() *  rotation3D(axis, ang);
//                        transfstack.pop();
//                        transfstack.push(m);
                    }
                }
                else if (cmd == "pushTransform") {
//                    transfstack.push(transfstack.top()); 
                }
                else if (cmd == "popTransform") {
//                    if (transfstack.size() <= 1) {
//                        cerr << "Stack has no elements.  Cannot Pop\n"; 
//                    } else {
//                        transfstack.pop(); 
//                    }
                }
                else {
                    cerr << "Unknown Command: " << cmd << " Skipping \n"; 
                }  
            }
            
            getline(in, str);
        }
    } else {
        cerr << "Unable to open file" << input << "\n";
        throw 2;
    }
}

bool Scene::readvals(stringstream &s, const int numvals, double* values) {
    for (int i = 0; i < numvals; i++) {
        s >> values[i];
        
        if (s.fail()) {
            cout << "Failed reading value " << i << " will skip\n";
            return false;
        }
    }
    return true; 
}
