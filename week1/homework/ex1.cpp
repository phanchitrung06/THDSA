#include<iostream>
using namespace std;
int fibonacci(int n);
void in(int n);
int main()
{
	int n;
	cin >> n;
	in(n);
}

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

void in(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << fibonacci(i)<<" ";
	}
}