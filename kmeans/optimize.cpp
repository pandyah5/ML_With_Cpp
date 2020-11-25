#include <iostream>
using namespace std;
#include "distance.h"
#include "optimize.h"

bool optimize(vector<vector<double>>& centroids, vector<vector<double>>& data){
    int count = 0; bool iterate = false;
    vector<double> sum;
    for (int i = 0; i < (data[0]).size(); i++){sum.push_back(0);}

    for (int i = 1; i <= centroids.size(); i++){
        for (int j = 0; j < data.size(); j++){
            if ((data[j])[(int)((data[j]).size()) - 1] == i){
                count++;
                for(int k = 0; k < (data[j]).size() - 1; k++){
                    sum[k] += data[j][k];
                }
            }
        }
        //cout << "SUM: ";
        for (int k = 0; k < (data[0]).size(); k++){
            if (count != 0){
                sum[k] = sum[k]/count;
                cout << sum[k] << " ";
            }
            else{
                sum[k] = 0;
            }
        }
        cout << endl;
        //cout << "The distance is: " << distance(sum, centroids[i-1]) << endl;
        if (distance(sum, centroids[i-1]) > 0.25){
            for(int k = 0; k < (data[0]).size() - 1; k++){
                centroids[i-1][k] = (sum[k]);
                sum[k] = 0;
            }
            count = 0;
            iterate = true;
        }
        else{
            count = 0;
            for(int k = 0; k < (data[0]).size(); k++)
                sum[k] = 0;
        }
    }
    return iterate;
}
