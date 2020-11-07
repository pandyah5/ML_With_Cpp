#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

int main(void){
    ofstream output;
    output.open("train_custom.log");
    int count = 0;
    output << "x y val" << endl;
    while (count < 5000){
        srand(count);
        output << 1 + abs((rand() + 3*count/10)%68) << " " << 1 +abs(2*((rand() + count/10)%110)) << " " << 1 << endl;
        count++;
    }
    while (count < 10000){
        srand(count);
        output << -1 -abs((rand() + 3*count/10)%68) << " " << -1 -abs(2*((rand() + count/10)%110)) << " " << -1 << endl;
        count++;
    }
    output.close();

    output.open("test_custom.log");
    count = 0;
    output << "x y val" << endl;
    while (count < 2000){
        srand(count);
        output << 1 + abs((rand() + 2*count/10)%68) << " " << 1 + abs(2*((rand() - count/10)%110)) << " " << 1 << endl;
        count++;
    }
    while (count < 4000){
        srand(count);
        output << -1 - abs((rand() - 1*count/10)%68) << " " << -1 - abs(2*((rand() + count/10)%110)) << " " << -1 << endl;
        count++;
    }
    output.close();
    return 0;
}
