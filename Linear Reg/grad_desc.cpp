#include <vector>
using namespace std;
#include "grad_desc.h"

void grad_desc(vector<double> pred, vector<double> label, vector<double> data, double l_rate, double & m, double & c){
    double d_m = 0, d_c = 0;
    for (int i = 0; i < (int)label.size(); i++){
        d_m += (data[i] * (pred[i] - label[i]));
        d_c += (pred[i] - label[i]);
    }
    d_m = (2 * d_m) / (double)(pred.size());
    d_c = (2 * d_c) / (double)(pred.size());
    m = m - l_rate * d_m;
    c = c - l_rate * d_m;
}
