#include <iostream>
using namespace std;


bool process(int a[], int n, int k, int sum, int ngay);
int main()
{
	int n, k;
	int kq = 0;
	int a[100];
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	cin >> k;
	int l = 0;
	int r = sum;
	kq = sum;
	int m = 0;
	while (l < r)
	{
		int m = (l + r) / 2;
		if (process(a, n, m, sum - m, k))
		{
			r = m;
			if (m < kq) kq = m;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << kq;

}

bool process(int a[], int n, int k, int sum, int ngay)
{
	int i = 0;
	int sum2 = 0;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		sum2 += a[i];
		if (sum2 > k)
		{
			sum2 = a[i];
			dem++;
		}
	}
	if (dem + 1 <= ngay) return true;
	else return false;

}

