#ifndef _HEAP_SORT_H            // Header Guard: This ensures that the header file is included only once during compilation.
#define _HEAP_SORT_H

#include "sort.h"

void heapRebuild(int start, int arr[], int n) {
    int leftChild = 2 * start + 1;
    if (leftChild >= n) return;     
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (rightChild < n && arr[rightChild] > arr[largerChild])
        largerChild = rightChild;
    if (arr[largerChild] > arr[start]) {
        swap(arr[largerChild], arr[start]);
        heapRebuild(largerChild, arr, n);
    }
}

void heapSort(int arr[], int n) {
    for (int index = (n - 1) / 2; index >= 0; index--)
        heapRebuild(index, arr, n);
    swap(arr[0], arr[n-1]);
    int heapSize = n - 1;
    while(heapSize > 1) {
        heapRebuild(0, arr, heapSize);
        heapSize--;
        swap(arr[0], arr[heapSize]);
    }
}

#endif