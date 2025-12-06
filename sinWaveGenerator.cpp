#include "sinWaveGenerator.h"
#include <math.h>


SinWaveGenerator::SinWaveGenerator():
amplitude(5), omega(2), phase(5)
{
}


SinWaveGenerator::SinWaveGenerator(float _amplitude, float _omega, float _phase):
amplitude(_amplitude), omega(_omega), phase(_phase)
{
}

vector<double> SinWaveGenerator::generateTimeSeries(int size)
{
    vector<double> vect;
    for (int i=0; i <= size; i++){
        vect.push_back(amplitude*sin(omega*i + phase));
    }

    return vect;
}
