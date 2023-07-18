#ifndef _SELECTION_SORT_H            
#define _SELECTION_SORT_H

#include "sort.h"

void selectionSort(int arr[], int n){
	for (int i = 0; i < n - 1; ++i){
		int minIdx = i;
		
		for (int j = i + 1; j < n; ++j)
			if (arr[j] < arr[minIdx])
				minIdx = j;
		swap(arr[minIdx], arr[i]);
	}
}

unsigned long long selectionSort(int arr[], int n){
	unsigned long long cmp = 0;
	for (int i = 0; ++cmp && i < n - 1; ++i){
		int minIdx = i;
		
		for (int j = i + 1; ++cmp && j < n; ++j)
			if (++cmp && arr[j] < arr[minIdx])
				minIdx = j;
		swap(arr[minIdx], arr[i]);
	}
	
	return cmp;
}

#endif
