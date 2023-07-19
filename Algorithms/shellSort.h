#ifndef _SHELL_SORT_H            
#define _SHELL_SORT_H

#include "sort.h"

void shellSortTime(int a[], int n) {
	int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2){
		for(i = interval; i < n; i++){
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
}

unsigned long long shellSortCompare(int a[], int n) {
	unsigned long long cmp = 0;
	int interval, i, j, temp;
	for(interval = n/2; ++cmp && interval > 0; interval /= 2){
		for(i = interval; ++cmp && i < n; i++){
			temp = a[i];
			for(j = i; cmp += 2 && j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
    return cmp;
}

#endif
