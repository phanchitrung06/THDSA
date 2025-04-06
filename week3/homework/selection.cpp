#include<iostream>
#include<string>
#include"selection.h"
using namespace std;

void selection(int *a,int n)
{
	int min ;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}


