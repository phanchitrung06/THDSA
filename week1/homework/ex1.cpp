#include<iostream>
using namespace std;
int fibonacci(int i);
void in(int n);
int main()
{
	int n;
	cin >> n;
	in(n);
}
//i :tinh so fibonacci
//	Neu  n=0  tra ve 0
//	Neu n = 1 tra ve 1
//	Neu n<=2, tính fibonacci(n) = fibonacci(n-1) + fibonacci(n-2) bang cach goi de quy
int fibonacci(int i)
{
	if (i == 0)
	{
	
		return 0;
	}
	if (i == 1)
	{
		
		return 1;
	}
	
	return  fibonacci(i - 1) + fibonacci(i - 2);
	

}
//ham in de in tung gia tri fibonacci tuong ung
void in(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << fibonacci(i)<<" ";
	}
}
