#pragma once
#include "Lib.h"
// -----   Bubble Sort   ----- //
void bubbleSortTime(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j)
        {
            // Swap adjacent elements if they are in the wrong order
            if ((arr[j] > arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
unsigned long long bubbleSortCompare(int arr[], int n)
{
    unsigned long long cmp = 0;
    for (int i = 0; ++cmp && i < n - 1; ++i)
    {
        // Last i elements are already in place
        for (int j = 0; ++cmp && j < n - i - 1; ++j)
        {
            // Swap adjacent elements if they are in the wrong order
            if (++cmp && (arr[j] > arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return cmp;
}