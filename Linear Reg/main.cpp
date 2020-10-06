#include <iostream>
#include <vector>
#define LRATE 0.00001
#include "cost_func.h"
#include "grad_desc.h"

int main(void){
    vector<double> x = {1, 2, 3, 4, 5, 6, 7};
    vector<double> y = {10, 20, 30, 40, 50, 60, 70};
    vector<double> pred;
    double m = 9, c = 0;
    int iter = 0, count = 1;

    // Getting number of iterations

    cout << "Please enter the number of iterations you desire: ";
    while(true){
        cin >> iter;
        if (cin.fail()){
            cout << "We received incorrect input, please try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            break;
    }
    cout << "Received: " << iter << endl;
    cout << "Please enter the initial values of m and c respectively: ";
    while(true){
        cin >> m >> c;
        if (cin.fail()){
            cout << "We received incorrect input, please try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            break;
    }
    cout << "Received: " << m << " & " << c << endl;

    // Setting up the while loop for training

    while(iter--){
        for (int i = 0; i < (int)y.size(); i++){
            pred.push_back((m * x[i]) + c);
        }
        if (iter % 50 == 0)
            cout << ">>> Iteration number: " << count << " <<>> Error: " << cost_function(pred, y) << endl;
        grad_desc(pred, y, x, LRATE, m, c);
        pred.clear();
        count++;
    }

    // Print the result

    cout << "Training ended!" << endl;
    cout << "The line is: y = " << m << "x + " << c << endl;

    return 0;
}
