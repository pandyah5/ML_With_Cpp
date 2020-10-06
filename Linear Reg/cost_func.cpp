#include <vector>
using namespace std;
#include "cost_func.h"

double cost_function(vector<double> pred, vector<double> label){
    double cost = 0;
    for (int i = 0; i < (int)pred.size(); i++){
        cost += (pred[i] - label[i]) * (pred[i] - label[i]);
    }
    cost = cost / (int)(pred.size());
    return cost;
}
