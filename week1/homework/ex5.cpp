#include<iostream>

using namespace std;

// Neu n = 0 thi mang chi co 1 phan tu nen no da sap xep, tra ve true
// Neu n > 0:
//   - Ta se kiem tra phan tu arr[n] < arr[n - 1] hay khong.
//   - Neu co thi tra ve false,
//   - Neu khong, ta se goi lai ham de quy kiemtra(arr, n - 1) de kiem tra 2 phan tu tiep theo co thoa hay khong.
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
