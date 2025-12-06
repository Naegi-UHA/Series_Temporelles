#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TimeSeriesDataset
{
private:
    bool znormalize;
    bool isTrain;
    vector<vector<double>> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;

public:
    TimeSeriesDataset(bool znorm = false, bool isTrain = true);

    void addTimeSeries(const vector<double>& series, int label);
    vector<double> zNormalize(const vector<double>& series);

    // getters utiles
    const vector<vector<double>>& getData() const { return data; }
    const vector<int>& getLabels() const { return labels; }
};

#endif
