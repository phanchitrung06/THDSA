#include<iostream>
#include<vector>
using namespace std;

int find(vector <int> a, int target)
{
	bool t = false;
	int tong = 0;
	int l = 0;
	int r = 0;
	int min = 6;
	while (l < a.size() && r <=a.size())
	{

		if (tong >= target)
		{
			t = true;
			tong -= a[l];

			l++;
			if (r - l < min) min = r - l + 1;
		}
		else
		{
			if (r<a.size())
			tong += a[r];

			r++;
		}





	}
	if (t == false) return 0;
	if (min == 0) return 1;
		return min;
}

int main()
{
		vector<int> a = { 2,3,1,2,4,3 };
	int target;
	cin >> target;

	cout<<find(a, target);
}
