#include <iostream>
#include <climits>
#include "assign_id.h"
#include "distance.h"

using namespace std;

void assign_IDs(vector<vector<double>>& centroids, vector<vector<double>>& data){
    for (int i = 0; i < data.size(); i++){
        int min = INT_MAX, id = 0, count = 1;
        double temp = 0;
        for (int j = 0; j < centroids.size(); j++){
            temp = distance(data[i], centroids[j]);
            if (temp < min){
                min = temp;
                id = count;
            }
            count++;
        }
        (data[i]).pop_back();
        (data[i]).push_back(id);
    }
}
