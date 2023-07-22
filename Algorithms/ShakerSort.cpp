#pragma once
#include "Lib.h"
// -----   Shaker Sort	    -----//
void shakerSortTime(int arr[], int n)
{
    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int j = right; j >= left; --j)
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Smaller elements to the top
        left = k + 1;
        for (int j = left; j <= right; ++j)
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Larger elements to the end
        right = k - 1;
    } while (left <= right);
}
unsigned long long shakerSortCompare(int arr[], int n)
{
    unsigned long long compare = 0;
    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int j = right;++compare && j >= left ; --j)
            if (++compare && arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Smaller elements to the top
        left = k + 1;
        for (int j = left;++compare && j <= right; ++j)
            if (++compare && arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Larger elements to the end
        right = k - 1;
    } while (++compare && left <= right);
    return compare;
}

