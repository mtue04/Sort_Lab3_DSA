#pragma once
#include "Lib.h"
// -----   Quick Sort	    -----//
void quickSortV1Time(int a[], int first, int last)
{
    int pivot = a[(first + last) / 2];
    int i = first, j = last;

    do
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (first < j)
        quickSortV1Time(a, first, j);
    if (i < last)
        quickSortV1Time(a, i, last);
}
unsigned long long quickSortV1Compare(int a[], int first, int last)
{
    unsigned long long count_compare = 0;
    int pivot = a[(first + last) / 2];
    int i = first, j = last;

    do
    {
        while ((++count_compare && a[i] < pivot))
            i++;
        while ((++count_compare && a[j] > pivot))
            j--;
        if (++count_compare && i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (++count_compare && i <= j);

    if (++count_compare && first < j)
        quickSortV1Compare(a, first, j);
    if (++count_compare && i < last)
        quickSortV1Compare(a, i, last);

    return count_compare;
}
