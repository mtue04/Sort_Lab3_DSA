#include <iostream>
using namespace std;

// -----   Selection Sort   -----//	

 
// -----   Insertion Sort   -----//	

 
// -----   Bubble Sort	    -----//

 
// -----   Heap Sort	    -----//
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

// -----   Merge Sort	    -----//

 
// -----   Quick Sort	    -----//

 
// -----   Radix Sort	    -----//

 
// -----   Shaker Sort	    -----//
void shakerSort(int arr[], int n){
    int left = 1, right = n-1, k = n-1;
    do {
        for (int j = right; j >= left; --j)
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Smaller elements to the top
        left = k + 1;
        for (int j = left; j <= right; ++j)
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            } // Larger elements to the end
        right = k - 1;
    } while (left <= right);
}

// -----   Shell Sort	    -----//

 
// -----   Counting Sort	-----//

 
// -----   Flash Sort	    -----//

 