#include "sign.h"

int sign(double* weight, double* input, int size){
    int result = 0;
    for (int i = 0; i < size; i++)
        result += (weight[i] * input[i]);
    if (result >= 0)
        return 1;
    else
        return -1;
}
