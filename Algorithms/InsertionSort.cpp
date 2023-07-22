#pragma once
#include "Lib.h"
// -----   Insertion Sort   -----//
void insertionSortTime(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
unsigned long long insertionSortCompare(int arr[], int n)
{
    unsigned long long count_compare = 0;
    for (int i = 1; ++count_compare && i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while ((++count_compare, j >= 0) && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    return count_compare;
}