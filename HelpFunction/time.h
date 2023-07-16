/*  This file includes function calculating running time of Algorithm
    This following source code references the idea of Duongdinh24.com (https://duongdinh24.com/tinh-thoi-gian-chay-chuong-trinh-trong-c-c/)
                                                                                                                                            */

#ifndef _CALCULATING_RUNNING_TIME_H            // Header Guard: This ensures that the header file is included only once during compilation.
#define _CALCULATING_RUNNING_TIME_H

#include <iostream>
#include <ctime>
using namespace std;

void calculatingRunningTime() {
    clock_t start, end;
    double time_use;

    start = clock();            // Take starting time of algorithm
    // TODO

    end = clock();              // Take ending time of algorithm
    time_use = (double)(end - start) / CLOCKS_PER_SEC;      // Calculating running time
    
    // TODO
}

#endif