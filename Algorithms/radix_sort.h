#ifndef _RADIX_SORT_H
#define _RADIX_SORT_H

#include "sort.h"
//  Algorithm
void radix_sort(int arr[], int n)
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

//  Calculate Comparison
unsigned long long radix_sort_cmp(int arr[], int n)
{
    unsigned long long cmp = 0;
    int max_val = arr[0]; // get maximum value in the array
    for (int i = 1;++cmp && i < n; ++i)
        if (++cmp && arr[i] > max_val) max_val = arr[i];

    int digits = 0, div; // find the maximum number of digits
    do
    {
        digits++;
        div = max_val / pow(10, digits);
    } while (++cmp && div > 0);

    int *tempArr[10]; // declare variables for temp store
    for (int i = 0;++cmp && i < 10; ++i)
        tempArr[i] = new int[n];
    
    int tempCount[10];

    for (int i = 0;++cmp && i < digits ; ++i) 
    {
        int exp = pow(10, i);
        for (int j = 0;++cmp && j < 10; ++j) // reset the counting
            tempCount[j] = 0;

        for (int j = 0;++cmp && j < n; ++j)  // form groups
        {
            int idx = (arr[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }

        int idx = 0; // combine groups
        for (int j = 0;++cmp && j < 10; ++j)
            for (int k = 0;++cmp && k < tempCount[j]; ++k)
                arr[idx++] = tempArr[j][k];
    }
    return cmp;
}

#endif