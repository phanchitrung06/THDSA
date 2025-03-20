#include<iostream>

using namespace std;
void process(int n, char nguon, char trunggian, char dich);
int main()
{
	int n;
	cin >> n;
	
		process(n, 'A', 'B', 'C');
}

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