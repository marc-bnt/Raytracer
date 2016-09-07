//
//  Film.cpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#include <iostream>
#include "FreeImage.h"
#include "Film.hpp"

using namespace std;

void Film::commit(Sample& sample, Color& color) {
    
}

void Film::writeImage() {
    FIBITMAP *bitmap = FreeImage_Allocate(width, height, 24);
    
    if (!bitmap) {
        cerr << "Unable to create file" << output << "\n";
        throw 2;
    }
    
    if (!FreeImage_Save(FIF_PNG, bitmap, output, 0)) {
        cerr << "Unable to save file" << output << "\n";
        throw 2;
    }
}

Film::Film(const char* output, float width, float height) {
    this->output = output;
    this->width = width;
    this->height = height;
}
