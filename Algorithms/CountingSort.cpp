#pragma once
#include "Lib.h"
// -----   Counting Sort	-----//
//  Algorithm
void countingSortTime(int a[], int n)
{
    long int maxVal = a[0];
    for (long int i = 1; i < n; i++)
    {
        if (a[i] > maxVal)
        {
            maxVal = a[i];
        }
    }

    vector<unsigned long long> count(maxVal + 1, 0);

    for (long int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    int index = 0;
    for (long int i = 0; i <= maxVal; i++)
    {
        while (count[i] > 0)
        {
            a[index] = i;
            index++;
            count[i]--;
        }
    }
}

// Comparison Mode
unsigned long long countingSortCompare(int a[], int n)
{
    unsigned long long count_compare = 0;

    long int maxVal = a[0];
    for (long int i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare && a[i] > maxVal)
        {
            maxVal = a[i];
        }
    }

    vector<unsigned long long> count(maxVal + 1, 0);

    for (long int i = 0; ++count_compare && i < n; i++)
    {
        count[a[i]]++;
    }

    int index = 0;
    for (long int i = 0; ++count_compare && i <= maxVal; i++)
    {
        while (++count_compare && count[i] > 0)
        {
            a[index] = i;
            index++;
            count[i]--;
        }
    }

    return count_compare;
}
