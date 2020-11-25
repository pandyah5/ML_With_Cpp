#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "assign_id.h"
#include "distance.h"
#include "optimize.h"

int main (void){
    int k = 1, dim = 0;
    cout << "Enter the value of \"k\" for training: ";
    cin >> k;
    cout << "Enter dimension of data: ";
    cin >> dim;
    ifstream input;
    input.open("train.log");
    vector<vector<double>> data;

    // Generating data vector
    while(!input.eof()){
        vector <double> entry; double temp = 0;
        for (int i = 0; i < dim; i++){
            input >> temp;
            entry.push_back(temp);
        }
        entry.push_back(0); // Last index is for ID
        if (!input.eof())
            data.push_back(entry);
    }
    cout << data.size() << " data points detected!" << endl;
    input.close();

    // Semantic testing
    if (k > data.size()){
        cout << "[ERROR] Value of 'k' cannot exceed total number of data points." << endl;
        return -1;
    }

    // Generating random centroids
    vector<vector<double>> centroids;
    for (int i = 0; i < k; i++){
        vector <double> coordinate;
        for (int j = 0; j < dim; j++){
            coordinate.push_back((rand() % 200));
        }
        centroids.push_back(coordinate);
    }

    bool iterate = true;
    int iter_count = 0;
    while(iterate){
        assign_IDs(centroids, data);
        iterate = optimize(centroids, data);
        // for (int l = 0; l < centroids.size(); l++){
        //     for (int k = 0; k < centroids[l].size(); k++){
        //         cout << centroids[l][k] << " ";
        //     }
        //     cout << endl;
        // }
        if (iter_count % 100){
            cout << iter_count << endl;
        }
        iter_count++;
    }
    cout << endl << "[MESSAGE] Final centroids: " << endl;
    for (int l = 0; l < centroids.size(); l++){
        for (int k = 0; k < centroids[l].size(); k++){
            cout << centroids[l][k] << " ";
        }
        cout << endl;
    }
    ofstream output;
    output.open("train.csv");
    output << "x,y,id" << endl;
    for (int i = 0; i < data.size(); i++){
        for(int j = 0; j <= dim; j++){
            output << data[i][j];
            if (j != dim){output << ',';}
        }
        output << endl;
    }
    for (int l = 0; l < centroids.size(); l++){
        for (int k = 0; k < centroids[l].size(); k++){
            output << centroids[l][k];
            if (k != centroids[l].size() - 1){output << ',';}
        }
        output << endl;
    }
    output.close();
    return 0;
}
