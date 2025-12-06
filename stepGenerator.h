#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include <iostream>
#include <string>
#include <vector>

#include "timeSeriesGenerator.h"

using namespace std;

class StepGenerator : public TimeSeriesGenerator
{
    private:
        double generateJump(float, double);
    protected:
       float probablity;
       
    public:
        StepGenerator();
        StepGenerator(float);
        virtual ~StepGenerator() = default;

        vector<double> generateTimeSeries(int size) override;
};

#endif