#include <iostream>
#include <fstream>
#include "sign.h"
#include <string>
#define PARAM 2
#define EPOCH 1000
#define FORCE_STOP true

using namespace std;

void print(double[], int );

int main(void){
    double weight[PARAM + 1];
    double data[PARAM + 1];
    data[0] = 1.0;
    for (int i = 0; i < PARAM + 1; i++){
        weight[i] = -1;
    }
    for (int i = 1; i < PARAM + 1; i++){
        data[i] = 0;
    }
    string labels[PARAM + 1];
    int output = 0, pred = 0, iterations = 0;
    bool misclassified = true;

    while(misclassified){
        // Implementing force stop after certain iterations
        if (FORCE_STOP && (iterations + 1 >= EPOCH)){
            cout << "[MESSAGE] Force stop implemented - epoch limit violated" << endl;
            break;
        }
        ifstream input;
        input.open("train_custom.log");
        for (int j = 0; j < PARAM + 1; j++){
            input >> labels[j];
        }
        int iter = 0;
        cout << endl;

        misclassified = false;
        // Traversing through all data points
        while(!input.eof())
        {
            // Prediction
            for (int i = 0; i < PARAM; i++){
                input >> data[i + 1];
            }
            input >> output;
            pred = sign(weight, data, PARAM + 1);

            // Learning algorithm
            if (pred != output){
                misclassified = true;
                for (int i = 0; i < PARAM + 1; i++){
                    weight[i] += data[i] * output;
                }
            }
            // Status update
            if (iter%100 == 0)
                cout << "[MESSAGE]Data point: " << iter << endl;
            iter++;
        }
        iterations++;
        cout << "Step: " << iterations << endl;
        input.close();
    }
    cout << "LABELS: ";
    for (int i = 0; i < PARAM + 1; i++){
        cout << labels[i] << " ";
    }
    // Printing the final weight vector
    cout << "Weight Vector: ";
    print(weight, PARAM + 1);
    cout << endl;
    return 0;
}

// Utility function to print arrays
void print(double* arr, int len){
    for (int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
