#include<iostream>
#include<string>
#include<fstream>
#include"selection.h"
#include"insertion.h"
#include"buble.h"
#include"counting.h"
#include"heapsort.h"
#include"merge.h"
#include"quick.h"
#include"shaker.h"
#include"radix.h"
#include"shell.h"
#include"flash.h"
using namespace std;

int main(int argc, char* argv[])
{
	int n;

	string path;
	string destination;
	string sort;
	ifstream f;

	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-i") == 0)
		{
			path = argv[i + 1];
	}
		else if (strcmp(argv[i], "-o") == 0)
		{
			destination = argv[i + 1];
		}
		else  if (strcmp(argv[i], "-a") == 0)
		{
			sort = argv[i + 1];
		}
	}
	f.open(path);
	f >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		f >> a[i];
	}
	f.close();

	if (sort == "selection-sort")
	{
		selection(a, n);
	}
	else if (sort == "insertion-sort")
	{
		insertion(a, n);
	}
	else if (sort == "counting-sort")
	{
		counting(a, n);
	}
	 else if (sort == "buble-sort")
	{
		buble(a, n);
	}
	 else if (sort == "heap-sort")
	{
		heapsort(a, n);
	}
	 else if (sort == "merge-sort")
	{
		mergesort(a, 0,n-1);
	}
	 else if (sort == "quick-sort")
	{
		quicksort(a, 0, n - 1);
	}
	 else if (sort == "shaker-sort")
	{
		shaker(a,n);
	}
	 else if (sort == "radix-sort")
	{
		radixsort(a, n);
	}
	 else if (sort == "shell-sort")
	{
		shellsort(a, n);
	}
	 else if (sort == "flash-sort")
	{
		flashsort(a, n);
	}
	ofstream f1;
	f1.open(destination, ios::out);
	if (!f1.is_open()) {
	cerr << "khong the mo file " << destination << endl;
		return 0;
	}
	f1 << n<<endl;
	if (sort!="counting-sort")
	for (int i = 0; i < n; i++)
		f1 << a[i]<<" ";
		
		f1.close();

}