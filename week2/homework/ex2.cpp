#include <iostream>
using namespace std;

int find(int a[], int n, int k);

int main()
{
	int n, k;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> k;
	cout << find(a, n, k);
}

int find(int a[], int n, int k)
{
	int last = a[n - 1];
	a[n - 1] = k;
	int i = 0;
	while (a[i] != k)
	{
		i++;
	}
	a[n - 1] = last;
	if (i < n - 1 || a[n - 1] == k)
	{
		return i;
	}
	return -1;
}