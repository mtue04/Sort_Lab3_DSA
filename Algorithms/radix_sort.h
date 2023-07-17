#ifndef _RADIX_SORT_H
#define _RADIX_SORT_H

#include "sort.h"

void radixSort(int arr[], int n)
{
    int max_val = arr[0]; // get maximum value in the array
    for (int i = 1; i < n; ++i)
        if (arr[i] > max_val) max_val = arr[i];

    int digits = 0, div; // find the maximum number of digits
    do
    {
        digits++;
        div = max_val / pow(10, digits);
    } while (div > 0);

    int *tempArr[10]; // declare variables for temp store
    for (int i = 0; i < 10; ++i)
        tempArr[i] = new int[n];
    
    int tempCount[10];

    for (int i = 0; i < digits ; ++i) 
    {
        int exp = pow(10, i);
        for (int j = 0; j < 10; ++j) // reset the counting
            tempCount[j] = 0;

        for (int j = 0; j < n; ++j)  // form groups
        {
            int idx = (arr[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }

        int idx = 0; // combine groups
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < tempCount[j]; ++k)
                arr[idx++] = tempArr[j][k];
    }
}

#endif