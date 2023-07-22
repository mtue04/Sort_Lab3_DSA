#pragma once
#include "Lib.h"
//   -------  HeapSort  --------  //
void heapRebuildTime(int start, int arr[], int n)
{
    int leftChild = 2 * start + 1;
    if (leftChild >= n)
        return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (rightChild < n && arr[rightChild] > arr[largerChild])
        largerChild = rightChild;
    if (arr[largerChild] > arr[start])
    {
        swap(arr[largerChild], arr[start]);
        heapRebuildTime(largerChild, arr, n);
    }
}
void heapSortTime(int arr[], int n)
{
    for (int index = (n - 1) / 2; index >= 0; index--)
        heapRebuildTime(index, arr, n);
    swap(arr[0], arr[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1)
    {
        heapRebuildTime(0, arr, heapSize);
        heapSize--;
        swap(arr[0], arr[heapSize]);
    }
}
void heapRebuildCompare(int start, int arr[], int n, unsigned long long &compare)
{
    int leftChild = 2 * start + 1;
    if (leftChild >= n)
    {
        compare++;
        return;
    }
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (rightChild < n && arr[rightChild] > arr[largerChild])
    {
        compare += 2;
        largerChild = rightChild;
    }
    if (arr[largerChild] > arr[start])
    {
        compare++;
        swap(arr[largerChild], arr[start]);
        heapRebuildCompare(largerChild, arr, n, compare);
    }
}
unsigned long long heapSortCompare(int arr[], int n)
{
    unsigned long long compare = 0;
    for (int index = (n - 1) / 2; index >= 0; index--)
    {
        compare++;
        heapRebuildCompare(index, arr, n, compare);
    }
    swap(arr[0], arr[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1)
    {
        compare++;
        heapRebuildCompare(0, arr, heapSize, compare);
        heapSize--;
        swap(arr[0], arr[heapSize]);
    }
    return compare;
}