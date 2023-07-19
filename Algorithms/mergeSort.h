#ifndef _MERGE_SORT_H            
#define _MERGE_SORT_H

#include "sort.h"

#define MAX_SIZE 500000

void mergeTime(int arr[], int first, int mid, int last) {
	int first1 = first, last1 = mid;
	int first2 = mid + 1, last2 = last;
	int tempArr[MAX_SIZE];
	int index = first1;
	while ((first1 <= last1) && (first2 <= last2)) {
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

void mergeSortTime(int arr[], int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		mergeSortTime(arr, first, mid);
		mergeSortTime(arr, mid + 1, last);
		mergeTime(arr, first, mid, last);
	}
}

void mergeCompare(int arr[], int first, int mid, int last, unsigned long long &compare) {
	int first1 = first, last1 = mid;
	int first2 = mid + 1, last2 = last;
	int tempArr[MAX_SIZE];
	int index = first1;
	while ((++compare && first1 <= last1) && (++compare && first2 <= last2)){
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

unsigned long long mergeSortCompare(int arr[], int first, int last) {
	unsigned long long compare = 0;
	if (++compare && first < last) {
		int mid = (first + last) / 2;
		mergeSortCompare(arr, first, mid);
		mergeSortCompare(arr, mid + 1, last);
		mergeCompare(arr, first, mid, last, compare);
	}
	return compare;
}


#endif
