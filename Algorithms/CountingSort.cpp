#pragma once
#include "Lib.h"
// -----   Counting Sort	-----//
//  Algorithm
void countingSortTime(int arr[], int n) {
    //Find max value
    long int maxVal = arr[0];
    for (long int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // perform distribution counting
    int *f = new int[maxVal + 1]{0};
    for (int i = 0; i < n; i++)
        f[arr[i]]++;

    // accumulate sum of frequencies
    for (int i = 1; i <= maxVal; i++)
        f[i] = f[i - 1] + f[i];

    // distribute values to their final positions
    int *b = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = b[i];

    // Free dynamically allocated memory
    delete[] f;
    delete[] b;
}

// Comparison Mode
unsigned long long countingSortCompare(int arr[], int n)
{
    unsigned long long count_compare = 0;

    long int maxVal = arr[0];
    for (long int i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare && arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    // perform distribution counting
    int *f = new int[maxVal + 1]{0};
    for (int i = 0;++count_compare && i < n; i++)
        f[arr[i]]++;

    // accumulate sum of frequencies
    for (int i = 1;++count_compare && i <= maxVal; i++)
        f[i] = f[i - 1] + f[i];

    // distribute values to their final positions
    int *b = new int[n];
    for (int i = n - 1;++count_compare && i >= 0; i--) {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }

    for (int i = 0;++count_compare && i < n; i++)
        arr[i] = b[i];

    // Free dynamically allocated memory
    delete[] f;
    delete[] b;

    return count_compare;
}
