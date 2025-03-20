#include<iostream>
#include <string>
using namespace std;
void in(string str);
void generateBinaryStrings(int n, string str);
int main()
{
	int n;
	cin >> n;
	string str="";
	 generateBinaryStrings( n,  str);
}

void generateBinaryStrings(int n, string str)
{
	string s = "";
	for (int i = 0; i <= 1; i++)
	{
		s = to_string(i);
		str = str + s;
		if (str.length() == n )
		{
			in(str);
		}
		else
		{
			generateBinaryStrings(n,str);
			
		}
		str.erase(str.length() - 1);
	}
}

void in( string str)
{
	for (int i = 0; i<str.length(); i++)
	{
		cout << str[i];
	}
	cout << endl;
}