#include<iostream>

using namespace std;

int n; 
int cot[100];
int d1[100];
int d2[100];
int dem = 0;
 

//so cach cong 1
void inkq() {
	dem++;
}
// Ta se dat N quan hau tren N dong.
// Luc nay ta chi can xem coi N quan hau nay co quan nao cung nam chung tai mot cot, cung duong cheo chinh, hay duong cheo phu hay khong.
// Chay lap J tu 1 den N cot, neu tai vi tri cot do thoa cot[J] = 1, d1[i - J + N] = 1, d2[i + J - 1] = 1 thi ta se dat tai vi tri do.
// Sau do ta se danh dau vi tri cot[J] = 0, d1[i - J + N] = 0, d2[J + i - 1] = 0 de danh dau lai vi tri cot, duong cheo chinh, duong cheo phu da co quan hau.
// Neu i < N thi ta se goi lai ham de quy Try(i + 1) de tim vi tri thoa cho quan hau thu i + 1.
// Neu i = N thi ta se goi ham inkq() cong so cach sap quan hau thoa man va quay lui de tim vi tri khac thoa man, va vi tri cu se tra lai cot[j] = d1[i - j + n] = d2[i + j - 1] = 1.

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
	for (int i = 0; i <100; i++) {
		cot[i] = d1[i] = d2[i] = 1;
	}
	Try(1);
	cout << dem;
	return 0;
}
