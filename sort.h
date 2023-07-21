/*  This file includes functions holding 11 sorting algorithms
    This following source code references the idea of
        + PhD. Thao Nguyen Ngoc
        +
*/

#ifndef _SORT_H
#define _SORT_H

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// -----   Selection Sort   -----//
void selectionSortTime(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;

        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
}
unsigned long long selectionSortCompare(int arr[], int n)
{
    unsigned long long cmp = 0;
    for (int i = 0; ++cmp && i < n - 1; ++i)
    {
        int minIdx = i;

        for (int j = i + 1; ++cmp && j < n; ++j)
            if (++cmp && arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
    }

    return cmp;
}

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

// -----   Bubble Sort	    -----//
void bubbleSortTime(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j)
        {
            // Swap adjacent elements if they are in the wrong order
            if ((arr[j] > arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
unsigned long long bubbleSortCompare(int arr[], int n)
{
    unsigned long long cmp = 0;
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
    }
    return cmp;
}

// -----   Heap Sort	    -----//
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
}

// -----   Merge Sort	    -----//
#define MAX_SIZE 500000
void mergeTime(int arr[], int first, int mid, int last)
{
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int tempArr[MAX_SIZE];
    int index = first1;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (arr[first1] <= arr[first2])
            tempArr[index++] = arr[first1++];
        else
            tempArr[index++] = arr[first2++];
    }
    while (first1 <= last1)
        tempArr[index++] = arr[first1++];
    while (first2 <= last2)
        tempArr[index++] = arr[first2++];

    for (index = first; index <= last; ++index)
        arr[index] = tempArr[index];
}
void mergeSortTime(int arr[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSortTime(arr, first, mid);
        mergeSortTime(arr, mid + 1, last);
        mergeTime(arr, first, mid, last);
    }
}
void mergeCompare(int arr[], int first, int mid, int last, unsigned long long &compare)
{
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int tempArr[MAX_SIZE];
    int index = first1;
    while ((++compare && first1 <= last1) && (++compare && first2 <= last2))
    {
        if (++compare && arr[first1] <= arr[first2])
            tempArr[index++] = arr[first1++];
        else
            tempArr[index++] = arr[first2++];
    }
    while (++compare && first1 <= last1)
        tempArr[index++] = arr[first1++];
    while (++compare && first2 <= last2)
        tempArr[index++] = arr[first2++];

    for (index = first; ++compare && index <= last; ++index)
        arr[index] = tempArr[index];
}
unsigned long long mergeSortCompare(int arr[], int first, int last)
{
    unsigned long long compare = 0;
    if (++compare && first < last)
    {
        int mid = (first + last) / 2;
        mergeSortCompare(arr, first, mid);
        mergeSortCompare(arr, mid + 1, last);
        mergeCompare(arr, first, mid, last, compare);
    }
    return compare;
}

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
        while ((++count_compare, a[i] < pivot))
            i++;
        while ((++count_compare, a[j] > pivot))
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

// -----   Radix Sort	    -----//
void radixSortTime(int arr[], int n)
{
    int max_val = arr[0]; // get maximum value in the array
    for (int i = 1; i < n; ++i)
        if (arr[i] > max_val)
            max_val = arr[i];

    int digits = 0, div; // find the maximum number of digits
    do
    {
        digits++;
        div = max_val / pow(10, digits);
    } while (div > 0);

    int *tempArr[10]; // declare variables for temp store
    for (int i = 0; i < 10; ++i)
        tempArr[i] = new int[n];

    int tempCount[10];

    for (int i = 0; i < digits; ++i)
    {
        int exp = pow(10, i);
        for (int j = 0; j < 10; ++j) // reset the counting
            tempCount[j] = 0;

        for (int j = 0; j < n; ++j) // form groups
        {
            int idx = (arr[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }

        int idx = 0; // combine groups
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < tempCount[j]; ++k)
                arr[idx++] = tempArr[j][k];
    }
}
unsigned long long radixSortCompare(int arr[], int n)
{
    unsigned long long cmp = 0;
    int max_val = arr[0]; // get maximum value in the array
    for (int i = 1; ++cmp && i < n; ++i)
        if (++cmp && arr[i] > max_val)
            max_val = arr[i];

    int digits = 0, div; // find the maximum number of digits
    do
    {
        digits++;
        div = max_val / pow(10, digits);
    } while (++cmp && div > 0);

    int *tempArr[10]; // declare variables for temp store
    for (int i = 0; ++cmp && i < 10; ++i)
        tempArr[i] = new int[n];

    int tempCount[10];

    for (int i = 0; ++cmp && i < digits; ++i)
    {
        int exp = pow(10, i);
        for (int j = 0; ++cmp && j < 10; ++j) // reset the counting
            tempCount[j] = 0;

        for (int j = 0; ++cmp && j < n; ++j) // form groups
        {
            int idx = (arr[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }

        int idx = 0; // combine groups
        for (int j = 0; ++cmp && j < 10; ++j)
            for (int k = 0; ++cmp && k < tempCount[j]; ++k)
                arr[idx++] = tempArr[j][k];
    }
    return cmp;
}

// -----   Shaker Sort	    -----//
void shakerSortTime(int arr[], int n)
{
    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int j = right; j >= left; --j)
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Smaller elements to the top
        left = k + 1;
        for (int j = left; j <= right; ++j)
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Larger elements to the end
        right = k - 1;
    } while (left <= right);
}
unsigned long long shakerSortCompare(int arr[], int n)
{
    unsigned long long compare = 1;
    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int j = right; j >= left && ++compare; --j)
            if (arr[j - 1] > arr[j] && ++compare)
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Smaller elements to the top
        left = k + 1;
        for (int j = left; j <= right && ++compare; ++j)
            if (arr[j - 1] > arr[j] && ++compare)
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Larger elements to the end
        right = k - 1;
    } while (left <= right && ++compare);
}

// -----   Shell Sort	    -----//
void shellSortTime(int a[], int n)
{
    int interval, i, j, temp;
    for (interval = n / 2; interval > 0; interval /= 2)
    {
        for (i = interval; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}

unsigned long long shellSortCompare(int a[], int n)
{
    unsigned long long cmp = 0;
    int j;
    for (int interval = n / 2; ++cmp && interval > 0; interval /= 2)
    {
        for (int i = interval; ++cmp && i < n; i++)
        {
            int temp = a[i];
            for (j = i; (++cmp && j >= interval) && (++cmp && a[j - interval] > temp); j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
    return cmp;
}

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

// -----   Flash Sort	    -----//
int __L[500000];

// Algorithm
void flashSortTime(int a[], int n)
{
    if (n <= 1)
        return;
    int m = n * 0.43;
    if (m <= 2)
        m = 2;
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (Mx < a[i])
            Mx = a[i];
        if (Mn > a[i])
            Mn = a[i];
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];
    // step 2
    int count = 0;
    int i = 0;
    while (count < n)
    {
        int k = getK(a[i]);

        while (i >= __L[k])
            k = getK(a[++i]);

        int z = a[i];
        while (i != __L[k])
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    // step 3
    for (int k = 1; k < m; ++k)
    {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
            if (a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (t > a[j + 1])
                {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
    }
}

// Calculate Comparisons
unsigned long long flashSortCompare(int a[], int n)
{
    unsigned long long cmp = 0;
    if (++cmp && n <= 1)
        return cmp;
    int m = n * 0.43;

    if (++cmp && m <= 2)
        m = 2;
    // int m = n;
    for (int i = 0; ++cmp && i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; ++cmp && i < n; ++i)
    {
        if (++cmp && Mx < a[i])
            Mx = a[i];
        if (++cmp && Mn > a[i])
            Mn = a[i];
    }
    if (Mx == Mn)
        return cmp;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; ++cmp && i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; ++cmp && i < m; ++i)
        __L[i] += __L[i - 1];
    // step 2
    int count = 0;
    int i = 0;
    while (++cmp && count < n)
    {
        int k = getK(a[i]);
        while (++cmp && i >= __L[k])
            k = getK(a[++i]);

        int z = a[i];
        while (++cmp && i != __L[k])
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    // step 3
    for (int k = 1; ++cmp && k < m; ++k)
    {
        for (int i = __L[k] - 2; ++cmp && i >= __L[k - 1]; --i)
            if (++cmp && a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (++cmp && t > a[j + 1])
                {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
    }
    return cmp;
}

#endif
