#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

struct  Company
{
	string name="";
	string profit_tax="";
	string address="";
};

struct HashTable
{
	Company a[2000];
	bool used[2000] = { false };
};


vector<Company> readCompanyList(string file_name)
{
	ifstream f;
	f.open(file_name);
	
	string s;
	vector<Company> group ;
	while (getline(f, s))
	{
		Company cp;
	
		
		int k = 0;
		while (k <= s.length() && s[k] != '|')
		{
			cp.name = cp.name + s[k++];
		}
		k++;
		while (k <= s.length() && s[k] != '|')
		{
			cp.profit_tax = cp.profit_tax + s[k++];
		}
		k++;
		while (k <= s.length() )
		{
			cp.address = cp.address + s[k++];
		}
		group.push_back(cp);
	}
	return group;

}

long long hashString(string company_name)
{

	string s;
	long long tam =1 ;

	if (company_name.length() <= 20)
	{
		s = company_name;
	}
	else
		s = company_name.substr(company_name.length() - 20);
	long long tong = 0;
	for (int i = 0; i < s.length(); i++)
	{
	
		tong =(tong+((s[i] * tam)%2000))%2000;
		tam = (tam * 31)%2000;
	}
	return tong;
}

HashTable* createHashTable(vector<Company> list_company)
{
	HashTable* arr = new HashTable ();
	
	
	for (int i = 0; i < list_company.size(); i++)
	{
		int step = 0;
		int temp=hashString(list_company[i].name);
		while (arr->used[temp] ==true && step<2000)
		{
			temp=(temp+1)%2000 ;
			step++;
		}
		if (step >= 2000)
		{
			return arr;
		}
		arr->used[temp] = true;
		arr->a[temp] = list_company[i];
		
	}
	return arr;
}

void insert(HashTable* hash_table, Company company)
{
	if (hash_table == nullptr) return;
		int step = 0;
		int temp = hashString(company.name);
		while (hash_table->used[temp] ==true && step < 2000)
		{
			temp = (temp + 1) % 2000;
			step++;
		}
		if (step >= 2000)
		{
			cout << "bang day";
			return;
		}
		hash_table->a[temp] = company;
		hash_table->used[temp] = true;
	
}

Company* search(HashTable* hash_table, string company_name)
{
	if(hash_table == nullptr) return nullptr;
	int temp = hashString(company_name);
	int step = 0;
	while (hash_table->used[temp] == true && step < 2000)
	{
		if (hash_table->a[temp].name == company_name)
			return &hash_table->a[temp];
		temp = (temp + 1) % 2000;
		step++;
	}
	return nullptr;
}


int main(int argc, char* argv[])
{
	vector<Company> group;
	HashTable* t;
	string path;
	string destination;
	string company;
	company = argv[1];
	path = argv[2];



	destination = argv[3];
	group=	readCompanyList(company);
	t = createHashTable(group);
	
	string s;
	
	
		

	
	ifstream f1;
	ofstream f;
	f1.open(path);
	f.open(destination);
	while (getline(f1, s))
	{
		
		
			Company* kq = search(t,s);
			if (kq)
				f << kq->name << "|" << kq->profit_tax << "|" << kq->address<<endl;
		
	}
	f.close();
	delete t;
}