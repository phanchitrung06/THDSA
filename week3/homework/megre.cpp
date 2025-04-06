#include<iostream>
#include<string>
#include"merge.h"
using namespace std;

void merge(int a[], int left, int mid, int right)
{

	int i = left, j = mid + 1, k = 0;
	int n = right - left + 1;
	int* temp = new int[n];


	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}


	while (i <= mid) {
		temp[k++] = a[i++];
	}


	while (j <= right) {
		temp[k++] = a[j++];
	}


	for (int x = 0; x < k; x++) {
		a[left + x] = temp[x];
	}
	delete[]temp;
}
void mergesort(int *a,int l,int r)
{
	if (l >= r) return;
	int m = l + (r - l) / 2;
	mergesort(a, l, m);
	mergesort(a, m + 1, r);
	merge(a, l,m, r);
}