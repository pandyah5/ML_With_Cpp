#include <iostream>
#include <fstream>
#include <vector>
#define LRATE 0.00001
#include "cost_func.h"
#include "grad_desc.h"

int main(void){
    double data = 0, label = 0;
    
    // Getting training data
    
    ifstream input;
    vector<double> x;
    vector<double> y;
    input.open("train.csv");
    while(!input.eof()){
        input >> data;
        x.push_back(data);
        input >> label;
        y.push_back(label);
        // cout << "Data: " << data << "  -  Label: " << label << endl;
    }
    vector<double> pred;
    double m = 9, c = 0;
    int iter = 0, count = 1;

    // Getting number of iterations and intialization values

    cout << ">>> Please enter the number of iterations you desire: ";
    
    // Input validity check
    while(true){
        cin >> iter;
        if (cin.fail()){
            cout << "[WARNING] We received incorrect input, please try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            break;
    }
    cout << "[MESSAGE] Received: " << iter << endl;
    cout << ">>> Please enter the initial values of m and c respectively: ";
    
    // Input validity check
    while(true){
        cin >> m >> c;
        if (cin.fail()){
            cout << "[WARNING] We received incorrect input, please try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            break;
    }
    cout << "[MESSAGE] Received: " << m << " & " << c << endl;

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

    cout << "[MESSAGE] Training ended!" << endl;
    cout << "The line is: y = " << m << "x + " << c << endl;

    // Testing the model on unseen data
    
    int test;
    cout << ">>> Do you want to test your model on a testing dataset?: [1/0]: ";
    cin >> test;
    
    // Reading the test data from CSV files and calculating performance on the test data
    if(test == 1){
        vector<double> test_label;
        vector<double> pred_label;
        ifstream t_input;
        t_input.open("test.csv");
        cout << "Here\n";
        while(!t_input.eof()){
            t_input >> data >> label;
            test_label.push_back(label);
            pred_label.push_back(m*data + c);
            cout << "Data: " << data << " - " << "Label: " << label << endl;
        }
        cout << ">>> Test Error : " << cost_function(pred_label, test_label) << endl << endl;
    }
    else{
        cout << ">>> The model has been trained, have a nice day!" << endl;
    }
    return 0;
}
