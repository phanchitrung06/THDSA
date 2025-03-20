#include<iostream>
#include<algorithm>
using namespace std;

int n, C;
int max1 = 0;

void compare(int sum) {
	if (sum > max1) max1 = sum;
}

void deQuy(int a[], int i, int sum) {
	for (int j = i; j < n; j++) {
		sum += a[j];
		if (sum < C) {
			compare(sum);
			deQuy(a, j + 1, sum);
		}
		
			sum -= a[j];
		
	}
}

int main() {
	cin >> n >> C;
	int* a = new int[n];
	int* dp = new int[C + 1];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int sum = 0;
	deQuy(a, 0, sum);
	cout << max1;
	return 0;
}