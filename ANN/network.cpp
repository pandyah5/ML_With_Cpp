#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class neuron{
    public:
        vector<double> weight;
        double bias;
        vector<double> delta;

    public:
        vector<double> feed_forward(vector<double> input){
            vector<double> output;
            for (int index = 0; index < input.size(); index++){
                output.push_back(input[index] * weight[index] + bias);
            }
            return output;
        }

        
};

double mse_loss(vector<double> target, vector<double> output){
    if (target.size() != output.size()){
        cout << "ERROR: Target size does not match output\n";
        return -1;
    }

    double err = 0;
    for (int i = 0; i < target.size(); i++){
        err += pow(abs(target[i] - output[i]), 2);
    }
    return err / target.size();
}

double tanh(double input){
    double num = exp(2*input) - 1;
    double den = exp(2*input) + 1;

    return num/den;
}

int main(void){
    vector<double> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<double> output = {4, 6, 10, 13, 16, 19, 22, 25, 28, 31};

    cout << mse_loss(input, output) << endl;

    return 0;
}
