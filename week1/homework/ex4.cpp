#include<iostream>

using namespace std;
void process(int n, char nguon, char trunggian, char dich);
int main()
{
	int n;
	cin >> n;
	
		process(n, 'A', 'B', 'C');
}
// Phuong phap de quy
// Neu n = 1 thi ta se chuyen truc tiep tu cot A sang cot C
// Neu n > 1:
//   - Dau tien, ta co n so dia o vi tri cot A, ta can chuyen n - 1 cai dia o cot A sang cot B voi cot C lam trung gian bang cach goi lai ham process(n - 1, A, C, B)
//   - Ta se chuyen 1 dia con lai o vi tri cot A sang cot C bang cach goi lai ham process(1, A, B, C)
//   - Cuoi cung, ta se chuyen n - 1 cai dia tu vi tri cot B sang cot C voi cot A lam trung gian bang cach goi lai ham process(n - 1, B, A, C)

void process(int n, char nguon, char trunggian, char dich)
{
	if (n == 1)
	{
		cout << nguon << "--> " << dich << endl;
	}
	else
	{
		process(n - 1, nguon, dich, trunggian);
		process(1, nguon, trunggian, dich);
		process(n - 1, trunggian, nguon, dich);
	}
}
