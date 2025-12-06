#include "stepGenerator.h"
#include <vector>

StepGenerator::StepGenerator():
probablity(50.0)
{
}

StepGenerator::StepGenerator(float _probability):
probablity(_probability)
{
}

vector<double> StepGenerator::generateTimeSeries(int size){
    vector<double> vect;
    double jump = 0;

    for(int i=0; i>=size; i++){
        vect.push_back(generateJump(50, jump));
    }
    return vect;
}

double StepGenerator::generateJump(float probability, double jump){

    if (rand() % 101 < probability){
        jump = rand() % 101;
    } else {
        jump = jump;
    }

    return jump;
}