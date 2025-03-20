#include<iostream>

using namespace std;

int n; 
int cot[100];
int d1[100];
int d2[100];
int dem = 0;
 


void inkq() {
	dem++;
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (cot[j] == 1 && d1[i - j + n] == 1 && d2[i + j - 1] == 1) 
		{
			cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
			if (i == n)
			{
				inkq();
			}
			else
			{
				Try(i + 1);
			}
			cot[j] = d1[i - j + n] = d2[i + j - 1] = 1;
		} 
	


	}

}
int main()
{
	cin >> n;
	for (int i = 1; i <= 100; i++) {
		cot[i] = d1[i] = d2[i] = 1;
	}
	Try(1);
	cout << dem;
	return 0;
}