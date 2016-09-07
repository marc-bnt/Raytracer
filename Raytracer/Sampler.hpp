//
//  Sampler.hpp
//  Raytracer
//
//  Created by Marc Bontje on 06-09-16.
//
//

#import "Sample.hpp"

class Sampler
{
private:
    float width;
    float height;
    float x;
    float y;
public:
    bool getSample(Sample* sample);
    Sampler(float width, float height);
};