#include <vector>
#include <cmath>
#include "distance.h"

double distance(vector<double> & data, vector<double> & centroid){
    double dist = 0;
    for (int i = 0; i < centroid.size(); i++){
        dist += ((data[i] - centroid[i]) * (data[i] - centroid[i]));
    }
    dist = sqrt(dist);
    return dist;
}
