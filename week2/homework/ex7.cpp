#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> check(vector<int> a, int n)
{
	vector<vector<int>> kq;
	int n = a.size();
	for (int i = 0; i < n - 2; i++) {
		if (i > 0 && a[i] == a[i - 1]) continue;
		int j = i + 1;
		int k = n - 1;

		while (j < k)
		{
			int tong = a[i] + a[j] + a[k];
			if (tong == 0)
			{
				kq.push_back({ a[i],a[j],a[k] });
				while (j < k && a[j] == a[j + 1]) j++;
				while (j < k && a[k] == a[k - 1]) k--;
				j++;
				k--;
			}
			else if (tong < 0)
			{
				j++;
			}
			else
			{
				k--;
			}


		}
	}
	return kq;
}
void heapify(vector<int> &a,int n,int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int large = i;
	if (l<n && a[l]>a[large])
	{
		large = l;
	}
	if (r<n && a[r]>a[large])
	{
		large = r;
	}
	if (large != i)
	{
		int temp = a[i];
		a[i] = a[large];
		a[large] = temp;
		heapify(a, n,large);
	}
}

void heapsort(vector<int>& a,int  n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n,i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		heapify(a, i, 0);
	}
}


int main()
{
	vector<int> v = {1,1,1};
	
	heapsort(v, v.size());
	check(v, v.size());
	
}