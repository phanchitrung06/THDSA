#include<iostream>
#include<string>
#include"flash.h"
#include<cmath>
using namespace std;

void flashsort(int *a,int n)
{
	
	int m=floor(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
	{
		l[i] = 0;
	}
	int max = a[0]; int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	if (max == min) {
		delete[] l;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int  k = floor((double)(m-1)*(a[i] - min) / (max - min) );
		l[k]++;
	}
	for (int i = 1; i < m; i++)
	{
		l[i] += l[i - 1];
	}
	int hold = a[0];
	int move = 0;
	int flash = 0;
	int t = 0;
	int j = 0;
	int k = 0;
	while (move < n - 1)
	{
		while (j> (l[k] - 1))
		{
			j++;
			k = floor((double)(m - 1)*(a[j] - min) / (max - min)  );
		}
		flash = a[j];
		while (j != l[k])
		{
			 k = floor((double)(m - 1) * (a[j] - min) / (max - min));
			  hold = a[t=--l[k]];
			  a[t] = flash; 
			  flash = hold; 
			  move++;
		}
		j++;
		if (j >= n) break;
	}
	for (int i = 1; i < n; i++)
	{
		int hold = a[i];
		int j = i - 1;;
		while (j >= 0 && a[j] > hold)
		{
			a[j + 1] = a[j--];
			
		}
		a[j + 1] = hold;
	}
	delete[] l; 
}