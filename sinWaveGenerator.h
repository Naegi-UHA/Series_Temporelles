#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include <iostream>
#include <string>
#include <vector>

#include "timeSeriesGenerator.h"

using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator
{   
    private:
        float amplitude;
        float omega;
        float phase;

    public:
        SinWaveGenerator();
        SinWaveGenerator(float amplitude, float omega, float phase);
        virtual ~SinWaveGenerator() = default;

        vector<double> generateTimeSeries(int size) override;
};

#endif