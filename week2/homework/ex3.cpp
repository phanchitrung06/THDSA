#include <iostream>
using namespace std;

int BS(int a[], int n);

int main()
{
	int n, k;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << BS(a, n);

}

int BS(int a[], int n)
{
	int l = 0;
	int r = n - 1;
	while (l < r)
	{
		int m = (l + r) / 2;
		if (a[m] < a[r])
		{
			r = m;
		}
		else
			if (a[m] > a[r])
			{
				l = m + 1;
			}
	}
	return a[l];
}