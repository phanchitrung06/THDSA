#include<iostream>
using namespace std;
int  factorial(int n);

int main()
{
	int n;
	cin >> n;
	cout<< factorial(n);
}
// phuong phap su dung de quy
// Neu n = 0 tra ve 1
// Neu n >= 1, tinh factorial(n) = n * factorial(n - 1) bang cach goi de quy
// Va in ra gia tri tai giai thua thu n

int factorial(int n)
{
	if (n==0) return 0;
	if (n == 1) return 1;
	return n * factorial(n - 1);
}
