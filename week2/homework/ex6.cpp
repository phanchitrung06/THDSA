#include <iostream>
using namespace std;

bool check(int a[], int n,int k)
{
	int l = 0;
	int r = n - 1;
	while (l < r)
	{
		if (a[l] + a[r] > k)
		{
			r--;
		}
		else if (a[l]+a[r]<k)
		{
			l++;
		}
		else
		{
			return true;
		}
	}
	return false;
}


int main()
{
	int a[100];
	int target;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	cin >> target;
	if (check(a, n, target))
		cout << "YES";
	else cout << "NO";
}