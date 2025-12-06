#include "gaussianGenerator.h"
#include "timeSeriesGenerator.h"

#include <math.h>
#include <vector>

#define _USE_MATH_DEFINES
# define M_PI           3.14159265358979323846  /* pi */


GaussianGenerator::GaussianGenerator(int _seed, float _moyenne, float _ecartType):
TimeSeriesGenerator(_seed), moyenne(_moyenne), ecartType(_ecartType)
{
}

GaussianGenerator::GaussianGenerator():
TimeSeriesGenerator(10), moyenne(0), ecartType(1)
{
}

double GaussianGenerator::boxMuller(){


    double u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 2.0);

    double Z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

    return Z;
}

vector<double> GaussianGenerator::generateTimeSeries(int size){

    vector<double> vect;
    vect.reserve(size);

    for (int i = 0; i < size; ++i) {
       
        vect.push_back(moyenne + ecartType * boxMuller());
    }
    return vect;
}


int GaussianGenerator::getSeed(){
    return seed;
}