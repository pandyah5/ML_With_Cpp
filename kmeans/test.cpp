#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<double> x = {1, 2, 3};
    vector<double> y = {4, 5, 6};
    vector<double> z = x + y;
    cout << z << endl;
    return 0;
}
