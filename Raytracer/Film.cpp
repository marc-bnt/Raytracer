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
    colors[(int) sample.y][(int) sample.x] = color;
}

void Film::writeImage() {
    FIBITMAP *bitmap = FreeImage_Allocate(width, height, 24);
    
    if (!bitmap) {
        cerr << "Unable to create file" << output << "\n";
        throw 2;
    }
    
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            Color color = colors[j][i];
            RGBQUAD pixelColor;
            
            pixelColor.rgbBlue = color.r * 255.0;
            pixelColor.rgbGreen = color.g * 255.0;
            pixelColor.rgbRed = color.b * 255.0;
            
            FreeImage_SetPixelColor(bitmap, i, j, &pixelColor);
        }
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
