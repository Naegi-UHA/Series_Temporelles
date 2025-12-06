#include "timeSeriesGenerator.h"

TimeSeriesGenerator::TimeSeriesGenerator(int _seed):
seed(_seed)
{
}

TimeSeriesGenerator::TimeSeriesGenerator():
seed(10)
{
}

void TimeSeriesGenerator::printTimeSeries(const vector<double> &series){
    cout << "série de donnée : ";
    for (double serie : series){
        cout << serie << "\n";
    }
}