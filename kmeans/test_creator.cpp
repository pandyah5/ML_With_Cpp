#include <iostream>
#include <cstdlib>

using namespace std;

int main(void){
    cerr << "Enter number of data points: ";
    int count = 0, i = 5;
    cin >> count;
    while(count--){
        cout << (rand() % i) + 2 << ' ' << (rand() % i) + 2 << endl;
        cout << -(rand() % i) - 2 << ' ' << -(rand() % i) - 2 << endl;
        cout << (rand() % i) + 2 << ' ' << -(rand() % i) - 2 << endl;
        cout << -(rand() % i) - 2 << ' ' << (rand() % i) + 2 << endl;
    }
    return 0;
}
