#ifndef _SHAKER_SORT_H            // Header Guard: This ensures that the header file is included only once during compilation.
#define _SHAKER_SORT_H

#include "sort.h"

void shakerSortTime(int arr[], int n){
    int left = 1, right = n-1, k = n-1;
    do {
        for (int j = right; j >= left; --j)
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Smaller elements to the top
        left = k + 1;
        for (int j = left; j <= right; ++j)
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Larger elements to the end
        right = k - 1;
    } while (left <= right);
}

#endif