#ifndef KNN_H
#define KNN_H

#include <vector>
#include <string>
#include "timeSeriesDataset.h"

using namespace std;

class KNN
{
private:
    int k;
    string similarity_measure;

public:
    KNN(int k, string sim);

    vector<int> predict(const TimeSeriesDataset& train,
                             const TimeSeriesDataset& test);

double evaluate(const TimeSeriesDataset& trainData,
                const TimeSeriesDataset& testData,
                const vector<int>& groundTruth);
};

#endif
