#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H

#include "sort.h"

unsigned long long bubbleSort(int arr[], int n)
{
    unsigned long long cmp = 0;
    int tenBil = 0;
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
            // if (cmp >= 10000000000)     //num of cmp more than 10bil
            // {                           //Reduce cmp 
            //     tenBil++;               //store
            //     cmp %= 10000000000;
            // }
    }
    // if (tenBil != 0)
    // {
    //     string numCmp = "";
    //     numCmp += to_string(tenBil);
    //     char a[] = cmp.c_str();

    // }
    return cmp;
}

#endif