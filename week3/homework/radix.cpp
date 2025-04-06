#include<iostream>
#include<string>
#include"radix.h"

int  getmax(int *a,int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}


void process(int *a,int  n, int div)
{
	int* output = new int[n];
	int count[10] = { 0 };
	for (int i = 0; i < n; i++)
	{
		count[(a[i] / div) % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = n-1; i >=0; i--)
	{
		output[count[(a[i] / div) % 10] - 1] = a[i];
		count[(a[i] / div) % 10]--;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = output[i];
	}
	delete[]output;
}


void radixsort(int* a, int n)
{
	int max = getmax(a, n);
	for (int i = 1; max / i > 0; i = i * 10)
	{
		process(a, n, i);
	}
}