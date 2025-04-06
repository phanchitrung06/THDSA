#include<iostream>
#include<string>
#include"quick.h"
using namespace std;

int  phanhoach(int *a,int l,int r)
{
	int i = l - 1;
	int j = r + 1;
	int pivot = a[l];
	while (1)
	{
		do
		{
			i++;
		} while (a[i] < pivot);
		do
		{
			j--;
		} while (a[j] > pivot);
		if (i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else return j;
	}
}

void quicksort(int *a,int l,int r)
{
	if (l >= r) return;
	int m = phanhoach(a, l, r);
	quicksort(a, l, m);
	quicksort(a, m + 1, r);
}