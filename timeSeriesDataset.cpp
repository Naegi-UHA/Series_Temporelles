#include "timeSeriesDataset.h"
#include <cmath>
#include <numeric>

TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool train)
    : znormalize(znorm), isTrain(train), maxLength(0), numberOfSamples(0)
{}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label)
{
    vector<double> toAdd = series;

    if (znormalize)
        toAdd = zNormalize(series);

    data.push_back(toAdd);
    labels.push_back(label);

    numberOfSamples++;
    if ((int)series.size() > maxLength)
        maxLength = series.size();
}

vector<double> TimeSeriesDataset::zNormalize(const vector<double>& series)
{
    vector<double> normalized(series.size());

    double mean = accumulate(series.begin(), series.end(), 0.0) / series.size();

    double variance = 0.0;
    for (double x : series)
        variance += (x - mean) * (x - mean);

    variance /= series.size();
    double stddev = sqrt(variance);

    if (stddev == 0)
        return vector<double>(series.size(), 0.0);

    for (int i = 0; i < (int)series.size(); i++)
        normalized[i] = (series[i] - mean) / stddev;

    return normalized;
}
