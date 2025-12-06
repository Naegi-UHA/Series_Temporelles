#ifndef SIMILARITY_H
#define SIMILARITY_H

#include <vector>

using namespace std;

double euclidean_distance(const vector<double>& x, const vector<double>& y);
double dtw(const vector<double>& x, const vector<double>& y);
double edr(const vector<double>& x, const vector<double>& y, double epsilon);

#endif
