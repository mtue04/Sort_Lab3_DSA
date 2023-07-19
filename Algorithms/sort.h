/*  This file includes functions holding 11 sorting algorithms
    This following source code references the idea of
        + PhD. Thao Nguyen Ngoc
        +  
*/

#ifndef _SORT_H            // Header Guard: This ensures that the header file is included only once during compilation.
#define _SORT_H

#include <iostream>
#include <cmath>
using namespace std;

// -----   Selection Sort   -----//	

 
// -----   Insertion Sort   -----//	

 
// -----   Bubble Sort	    -----//
void bubble_sort(int arr[], int n);                           
unsigned long long bubble_sort_cmp(int arr[], int n);
// -----   Heap Sort	    -----//
void heapRebuild(int start, int arr[], int n);
void heapSort(int arr[], int n);

// -----   Merge Sort	    -----//

 
// -----   Quick Sort	    -----//

 
// -----   Radix Sort	    -----//
void radix_sort(int arr[], int n);
unsigned long long radix_sort_cmp(int arr[], int n);
// -----   Shaker Sort	    -----//
void shakerSort(int arr[], int n);

// -----   Shell Sort	    -----//

 
// -----   Counting Sort	-----//

 
// -----   Flash Sort	    -----//
void flash_sort(int a[], int n);
unsigned long long flash_sort_cmp(int a[], int n);
#endif