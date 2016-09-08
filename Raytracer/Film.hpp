//
//  Film.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#import "Color.hpp"
#import "Sample.hpp"

class Film
{
private:
    const char* output;
    float width;
    float height;

    Color colors[480][640];
public:
    // Will write the color to (sample.x, sample.y) on the image
    void commit(Sample& sample, Color& color);
    // Output image to a file
    void writeImage();
    
    Film(const char* output, float widht, float height);
};
