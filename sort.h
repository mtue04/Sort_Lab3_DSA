/*  This file includes functions holding 11 sorting algorithms
    This following source code references the idea of
        + PhD. Thao Nguyen Ngoc
        + https://github.com/leduythuccs/Sorting-Algorithms
*/
#pragma once
#ifndef _SORT_H
#define _SORT_H

// -------    Functions Files    ------- //
#include "Algorithms/Lib.h"
#include "Algorithms/SelectionSort.cpp"
#include "Algorithms/InsertionSort.cpp"
#include "Algorithms/BubbleSort.cpp"
#include "Algorithms/ShakerSort.cpp"
#include "Algorithms/HeapSort.cpp"
#include "Algorithms/ShellSort.cpp"
#include "Algorithms/MergeSort.cpp"
#include "Algorithms/QuickSort.cpp"
#include "Algorithms/CountingSort.cpp"
#include "Algorithms/RadixSort.cpp"
#include "Algorithms/FlashSort.cpp" 

//   -----------Prototype---------   //
//      -----SelectionSort-----      //
void selectionSortTime(int arr[], int n);
unsigned long long selectionSortCompare(int arr[], int n);

// // -----   Insertion Sort   -----//
void insertionSortTime(int arr[], int n);
unsigned long long insertionSortCompare(int arr[], int n);

// // -----   Bubble Sort	    -----//
void bubbleSortTime(int arr[], int n);
unsigned long long bubbleSortCompare(int arr[], int n);

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
void quickSortV1Time(int a[], int first, int last);
unsigned long long quickSortV1Compare(int a[], int first, int last);

// -----   Radix Sort	    -----//
void radixSortTime(int arr[], int n);
unsigned long long radixSortCompare(int arr[], int n);

// -----   Shaker Sort	    -----//
void shakerSortTime(int arr[], int n);
unsigned long long shakerSortCompare(int arr[], int n);

// -----   Shell Sort	    -----//
void shellSortTime(int a[], int n);
unsigned long long shellSortCompare(int a[], int n);

// -----   Counting Sort	-----//
void countingSortTime(int a[], int n);
unsigned long long countingSortCompare(int a[], int n);

// -----   Flash Sort	    -----//
void flashSortTime(int a[], int n);
unsigned long long flashSortCompare(int a[], int n);

#endif