#include "knn.h"
#include "similarity.h"
#include <cmath>
#include <algorithm>
using namespace std;

KNN::KNN(int k_, string sim): 
k(k_), similarity_measure(sim)
{
}

vector<int> KNN::predict(const TimeSeriesDataset& train, const TimeSeriesDataset& test) {
    vector<int> predictions;

    const auto& trainData = train.getData();
    const auto& trainLabels = train.getLabels();
    const auto& testData = test.getData();

    for (const auto& tsTest : testData)
    {
        vector<pair<double,int>> distances;

        for (int i = 0; i < trainData.size(); i++)
        {
            double d = 0;

            if (similarity_measure == "ED")
                d = euclidean_distance(tsTest, trainData[i]);

            else if (similarity_measure == "DTW")
                d = dtw(tsTest, trainData[i]);

            else if (similarity_measure == "EDR")
                d = edr(tsTest, trainData[i], 0.1);

            distances.push_back({d, trainLabels[i]});
        }

        sort(distances.begin(), distances.end());

        int count0 = 0, count1 = 0;

        for (int i = 0; i < k; i++)
        {
            if (distances[i].second == 0) count0++;
            else count1++;
        }

        predictions.push_back(count1 > count0 ? 1 : 0);
    }

    return predictions;
}

double KNN::evaluate(const TimeSeriesDataset& train, const TimeSeriesDataset& test, const vector<int>& groundTruth){
    vector<int> ypred = predict(train, test);
    const vector<int>& ytest = test.getLabels();

    int correct = 0;
    for (int i = 0; i < ytest.size(); i++)
        if (ypred[i] == ytest[i])
            correct++;

    return double(correct) / ytest.size();
}
