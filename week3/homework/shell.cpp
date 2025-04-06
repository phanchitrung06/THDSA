#include<iostream>
#include<string>
#include"shell.h"

void shellsort(int *a,int n)
{
	int gap = n / 2;
	while (gap >= 1)
	{
		for (int i = gap; i < n; i++)
		{
			int key = a[i];
			int j = i;
			while (j - gap >= 0 && a[j - gap] > key)
			{
				a[j] = a[j-gap];
				j = j - gap;
			}
			a[j] = key;
		}
		gap = gap / 2;
	}
}