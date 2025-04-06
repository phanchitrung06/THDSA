#include<iostream>
#include<string>
#include"insertion.h"
using namespace std;

void insertion(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int pos = i - 1;
		int temp = a[i];
		while (pos >= 0 && a[pos]>temp)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = temp;
	}
}
