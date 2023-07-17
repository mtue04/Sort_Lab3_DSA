#ifndef _MERGE_SORT_H            
#define _MERGE_SORT_H

#include "sort.h"

#define MAX_SIZE 500000

void mergeSort(int arr[], int first, int last)
{
	if (first < last){
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}

void merge(int arr[], int first, int mid, int last){
	int first1 = first, last1 = mid;
	int first2 = mid + 1, last2 = last;
	int tempArr[MAX_SIZE];
	int index = first1;
	while ((first1 <= last1) && (first2 <= last2)){
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

#endif
