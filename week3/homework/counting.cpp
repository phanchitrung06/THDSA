#include<iostream>
#include<string>
#include"counting.h"
#include"radix.h"
using namespace std;



void counting(int *a,int n)
{
	int max = getmax(a, n);

	int* b = new int[max+1];
	for (int i = 0; i < max+1; i++)
	{
		b[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		b[a[i]]++;
	}
	for (int i = 0; i < max+1; i++)
	{
		for (int j = 0; j < b[i]; j++)
			cout << i;
	}
	delete[]b;
}
