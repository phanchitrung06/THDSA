#include<iostream>

using namespace std;


bool kiemtra(int arr[], int n)
{
	if (n == 0) return true;
	if (arr[n] < arr[n - 1]) return false;
	return kiemtra(arr, n-1);
}

int main()
{
	
	int arr[] = { 1, 3, 5, 6, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]);
	
	if (kiemtra(arr, n-1))
	{
		cout << "mang da sap xep";
	}
	else
	{
		cout << "mang chua sap xep";
	}
}
