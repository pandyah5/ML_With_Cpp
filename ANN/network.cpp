#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node{
    public:
        double weight;
        double bias;
};

double tanh(double input){
    double num = exp(2*input) - 1;
    double den = exp(2*input) + 1;

    return num/den;
}

int main(void){
    double i = 5.25;
    cout << "Tanh: " << tanh(i) << endl;
    return 0;
}
