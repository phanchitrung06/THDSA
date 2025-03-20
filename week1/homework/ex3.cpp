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
// Phuong phap de quy, quay lui
// Ta se lap tung gia tri 0 den 1 de gan vao chuoi str va so sanh do dai chuoi str voi n
// Neu do dai chuoi str < n se goi de quy generateBinaryStrings(n, str) de gan them 0 hoac 1 de tang them do dai chuoi str
// Neu do dai chuoi str = n se in cau hinh va quay lui

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
// in cau hinh nhi phan ra
void in( string str)
{
	for (int i = 0; i<str.length(); i++)
	{
		cout << str[i];
	}
	cout << endl;
}
