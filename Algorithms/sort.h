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
void selectionSortTime(int arr[], int n);
unsigned long long selectionSortCompare(int arr[], int n);
 
// -----   Insertion Sort   -----//	
void insertionSortTime(int arr[], int n);
unsigned long long insertionSortCompare(int arr[], int n);
 
// -----   Bubble Sort	    -----//

 
// -----   Heap Sort	    -----//
void heapRebuildTime(int start, int arr[], int n);
void heapSortTime(int arr[], int n);
void heapRebuildCompare(int start, int arr[], int n, unsigned long long &compare);
unsigned long long heapSortCompare(int arr[], int n);

// -----   Merge Sort	    -----//
void mergeTime(int arr[], int first, int mid, int last);
void mergeSortTime(int arr[], int first, int last);
void mergeCompare(int arr[], int first, int mid, int last, unsigned long long &compare);
unsigned long long mergeSortCompare(int arr[], int first, int last);

// -----   Quick Sort	    -----//

 
// -----   Radix Sort	    -----//

 
// -----   Shaker Sort	    -----//
void shakerSortTime(int arr[], int n);
unsigned long long shakerSortCompare(int arr[], int n);

// -----   Shell Sort	    -----//
void shellSortTime(int a[], int n);
unsigned long long shellSortCompare(int a[], int n);

// -----   Counting Sort	-----//
void countingSortTime(int arr[], int n);
unsigned long long countingSortCompare(int arr[], int n);
 
// -----   Flash Sort	    -----//

#endif