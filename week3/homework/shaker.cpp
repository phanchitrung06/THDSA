#include<iostream>
#include<string>
#include"shaker.h"

void shaker(int* a, int n)
{
	int l = 0; int r = n - 1; int k = n - 1;
	while (l < r)
	{
		for (int i = r; i > l; i--)
		{
			if (a[i - 1] > a[i])
			{
				int temp = a[i - 1];
				 a[i - 1] = a[i];
				a[i] = temp;
				k = i;
			}
		}
		l = k;
		for (int i = l; i <r ; i++)
		{
			if (a[i ] > a[i+1])
			{
				int temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				k = i;
			}
		}
		r = k;
	}
}