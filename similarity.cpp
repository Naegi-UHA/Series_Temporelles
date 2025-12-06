#include "similarity.h"
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

double euclidean_distance(const vector<double>& x, const vector<double>& y) {
    double sum = 0.0;
    int n = min(x.size(), y.size());
    for (int i = 0; i < n; i++)
        sum += (x[i] - y[i]) * (x[i] - y[i]);
    return sqrt(sum);
}

double edr(const vector<double>& x, const vector<double>& y, double epsilon) {
    int n = x.size();
    int m = y.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            bool match = fabs(x[i-1] - y[j-1]) <= epsilon;

            if (match)
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] });
        }
    }

    return dp[n][m];
}

double dtw(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    int m = y.size();

    vector<vector<double>> dp(n+1, vector<double>(m+1, numeric_limits<double>::infinity()));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            double cost = (x[i-1] - y[j-1]) * (x[i-1] - y[j-1]);

            dp[i][j] = cost + min({
                dp[i-1][j],     // insertion
                dp[i][j-1],     // suppression
                dp[i-1][j-1]    // match
            });
        }
    }

    return sqrt(dp[n][m]);
}