#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include <iostream>
#include <string>
#include <vector>

#include "timeSeriesGenerator.h"

using namespace std;

class GaussianGenerator : public TimeSeriesGenerator
{
    private:
        double boxMuller();

    protected:
       float moyenne;
       float ecartType;
       
    public:
        GaussianGenerator();
        GaussianGenerator(int seed, float moyenne, float ecartType);
        virtual ~GaussianGenerator() = default;

        vector<double> generateTimeSeries(int size) override;
        int getSeed();
};

#endif