#include<iostream>
#include<string>
#include"heapsort.h"
using namespace std;

void heapify(int *a,int n,int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int large = i;
	if (l < n && a[large] < a[l])
	{
		large = l;
	}
	if (r < n && a[large] < a[r])
	{
		large = r;
	}
	if (large != i)
	{
		int temp = a[large];
		a[large] = a[i];
		a[i] = temp;
		heapify(a, n, large);
	}
}

void heapsort(int *a,int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, i, 0);
	}
}