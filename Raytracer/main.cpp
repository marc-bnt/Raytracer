//
//  main.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include <iostream>
#include "FreeImage.h"
#include "Scene.hpp"
#include "test.hpp"

int main(int argc, const char * argv[]) {
//    testAll();
//    return 0;
    
    Scene *scene;
    
    FreeImage_Initialise();
    
    if (argc < 2) {
        std::cout << "Please provide a scene file.\n";
        return 1;
    }
    
    if (argc < 3) {
        std::cout << "Please provide an output file.\n";
        return 1;
    }
    
    scene = new Scene(argv[1], argv[2]);
    scene->render();

    return 0;
}
