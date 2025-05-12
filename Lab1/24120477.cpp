#include<iostream>
#include <string>
#include <cstring>
#include<fstream>

using namespace std;



struct bigint
{
	string s;
};


struct node
{
	bigint  data;
	node* next=nullptr;
};

struct list
{
	node* p_tail;
	node* p_head;
};

struct stack
{
	node* top;
};



void newlist(list * l)
{
	l->p_head = nullptr;
	l->p_tail = nullptr;
}

node* createnode(string data)
{
	node* p = new node;
	p->data.s = data;
	p->next = nullptr;
	return p;
}


void addtail(list*l,string data)
{
	node* p = createnode(data);
	if (l->p_head == nullptr)
	{
		l->p_head = p;
		l->p_tail = p;
	}
	else
	{
		l->p_tail->next = p;
		l->p_tail = p;
	}
}
void init(stack &st)
{
	st.top = nullptr;
}

bool isempty(stack st)
{
	if (st.top == nullptr)
		return true;
	return false;
}

void push(stack& st, string data)
{
	
	node* p = createnode(data);
	if (isempty(st))
	{
		st.top = p;
	}
	else
	{
		p->next = st.top;
		st.top = p;
	}
}

string pop(ofstream& f1,stack& st)
{

	
	if (isempty(st))
	{
		f1 << "stack rong" << endl;
		return "";
	}
	else
	{
		node* temp = st.top;
		string data="";
		data = st.top->data.s;
		if (temp->next)
		st.top = temp->next;
		else
		{
			st.top = nullptr;
		}
		delete temp;
			return data;
	}

}


void peek(ofstream& f1,stack st)
{
	if (isempty(st))
	{
		f1 << "stack rong" << endl;

	}
	else
	{
		f1 << st.top->data.s<<endl;
	}
}

bool uutien(string  s1, char s2)
{
	if (s1=="*" || s1=="/")
	{
		
			return true;
	}
	else
	{
		if (s2 == '+' || s2 == '-')
		{
			return true;
		}
	}
	return false;
}

// xu ly hau to 
void xuly(ofstream& f1,stack&ope, list* post,string s)
{
	string temp="";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			temp+= s[i];

		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (s[i] == '-')
			{
				int k = i - 1;
				while (k >= 0 && s[k] == ' ')k--;
				if (s[k] == '(')
				{
					temp += s[i];
					continue;
				}
			

			}
			if (temp != "")
				addtail(post, temp);
			temp = "";
			while (!isempty(ope) && ope.top->data.s != "(" && uutien(ope.top->data.s, s[i]))
			{
				

					if (ope.top->data.s != "(")
					{
						addtail(post, ope.top->data.s);
						pop(f1, ope);
					}
					

					
			}
			string  tempchar = "";

				tempchar += s[i];

				push(ope, tempchar);
			
			
		}
		else if (s[i]!=' ')
		{
			if (s[i] == '(')
			{
				string tempchar = "";
				tempchar += s[i];
				push(ope, tempchar);
				
			}
			else
			{
				
				
				if (temp!="")
				addtail(post, temp);
				temp = "";
				while (!isempty(ope) && ope.top->data.s !="(")
				{
				
					addtail(post, ope.top->data.s);
					pop(f1, ope);
					
				}
				pop(f1, ope);
			}

		}

	}

	if (temp.length() > 0) {
		
		addtail(post, temp);
	}
	while (!isempty(ope))
	{
		
		addtail(post, ope.top->data.s);
		pop(f1, ope);
	}
	
}
void removeall(list* l)
{
	node* p = l->p_head;
	while (p)
	{
		node* temp = p;
		p = p->next;
		delete temp;
	}
	l->p_head = nullptr;
	l->p_tail = nullptr;
}

string cong(string  s1, string  s2, bool t);
bool check(ofstream& f1, const string  s);
int compare(const string  a, const string  b);
string chia(string  s1, string  s2, bool t);
string  subtract(const string  a, const string  b);
string  nhan(string  s1, string  s2, bool t);
string tru(string  s1, string  s2);
int main(int argc, char* argv[])
{
	string path;
	string  destination;
	ifstream f;
	ofstream f1;
	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "tests.txt") == 0)
		{
			path = argv[i];
		}
		else if (strcmp(argv[i], "output_24120477.txt") == 0)
		{
			destination = argv[i ];
		}
		
	}
	f.open(path);
	f1.open(destination);
	if (!f.is_open()) {
		f1 << "Khong mo duoc file!" << endl;
		return 0;
	}
	if (!f1.is_open()) {
		f1 << "Khong mo duoc file!" << endl;
		return 0;
	}
	
	string s;
	/*list* l = new list;
	newlist(l);*/
	
	while (getline(f, s))
	{
		stack ope;
		init(ope);
	
		stack kq;
		init(kq);
		list* post = new list;
		newlist(post);
	 if (check(f1,s) == false) continue;
		xuly(f1,ope, post, s);
		for (node* p = post->p_head; p != nullptr; p = p->next)
		{
			/*cout << p->data.s<<" ";*/
			if (p->data.s == "+" || p->data.s == "-"  || p->data.s == "*" || p->data.s == "/")
			{
				if (p->data.s == "+")
				{

					string temp1 = "";
					temp1 = pop(f1,kq);

					string temp2="";
					temp2 = pop(f1, kq);
					if (temp1[0] != '-' && temp2[0] == '-')
					{
						push(kq, tru(temp2.substr(1), temp1));
					}
					else if (temp1[0] == '-' && temp2[0] != '-')
					{
						push(kq, tru(temp1.substr(1), temp2));
					}
					else if (temp1[0] == '-' && temp2[0] == '-')
					{
						push(kq, cong(temp1.substr(1), temp2.substr(1), false));
					}
					else 
					push(kq, cong(temp1, temp2,true));
					
				}

				else 	if (p->data.s == "-")
					{
						string temp1 = "";
						temp1 = pop(f1, kq);
							string temp2 = "";
							temp2 = pop(f1, kq);
							if (temp1[0] != '-' && temp2[0] == '-')
							{
								push(kq, cong(temp1 , temp2.substr(1),false));
							}
							else if (temp1[0] == '-' && temp2[0] != '-')
							{
								push(kq, cong(temp1.substr(1), temp2 , true));
							}
							else if(temp1[0] == '-' && temp2[0] == '-')
							{
								push(kq, tru(temp2.substr(1), temp1.substr(1)));

							}
							else
							{
								push(kq, tru(temp1, temp2));
							}
							
					}
				else 	if (p->data.s == "*")
				{
					string temp1= "";
					temp1 = pop(f1, kq);
					string temp2 = "";
					temp2 = pop(f1, kq);
					if (temp1[0] != '-' && temp2[0] == '-')
					{
						push(kq, nhan(temp1, temp2.substr(1), false));
					}
					else if (temp1[0] == '-' && temp2[0] != '-')
					{
						push(kq, nhan(temp1.substr(1), temp2, false));
					}
					else if (temp1[0] == '-' && temp2[0] == '-')
					{
						push(kq, nhan(temp1.substr(1), temp2.substr(1),true));

					}
					else
					{
						push(kq, nhan(temp1, temp2,true));
					}
					
				} 
				else
				{
					string temp1 = "";
					temp1 = pop(f1, kq);
					string temp2 = "";
					temp2 = pop(f1, kq);
					if (temp1 == "0")
					{
						f1 << "Error" << endl;
						cerr << "Error" << endl;
						break;
					}
					if (temp1[0] != '-' && temp2[0] == '-')
					{
						push(kq, chia(temp1, temp2.substr(1), false));
					}
					else if (temp1[0] == '-' && temp2[0] != '-')
					{
						push(kq, chia(temp1.substr(1), temp2, false));
					}
					else if (temp1[0] == '-' && temp2[0] == '-')
					{
						push(kq, chia(temp1.substr(1), temp2.substr(1), true));

					}
					else
					{
						push(kq, chia(temp1, temp2, true));
					}
					
				}

			}
			else
			{
				push(kq, p->data.s);

			}
		}
	
		removeall(post);
		delete post;
		if (!isempty(kq))
		{
			peek(f1, kq);
			pop(f1, kq);
		}
		while (!isempty(ope))
		{
			pop(f1, ope);
		 }
		s = "";
	}

	f.close();
	f1.close();
	
	
}

// phep cong

string   cong(string s1, string  s2, bool t)
{

	int i = s1.length() - 1;
	int j = s2.length() - 1;
	int carry = 0;


	string kq = "";

	while (i >= 0 && j >= 0)
	{
		int temp1 = s1[i] - 48;
		int temp2 = s2[j] - 48;
		if (temp1 + temp2 + carry >= 10)
		{
			int temp = (temp1 + temp2 + carry) % 10;
			carry = 1;
			kq += temp + 48;
		}
		else
		{
			int temp = (temp1 + temp2 + carry) % 10;
			carry = 0;
			kq += temp + 48;
		}
		i--;
		j--;

	}
	while (i >= 0)
	{
		int temp1 = s1[i] - 48;
		if (temp1 + carry >= 10)
		{
			int temp = (temp1 + carry) % 10;
			carry = 1;
			kq += temp + 48;
		}
		else
		{
			int temp = (temp1 + carry) % 10;
			carry = 0;
			kq += temp + 48;
		}
		i--;
	}
	while (j >= 0)
	{
		int temp2 = s2[j] - 48;
		if (temp2 + carry >= 10)
		{
			int temp = (temp2 + carry) % 10;
			carry = 1;
			kq += temp + 48;
		}
		else
		{
			int temp = (temp2 + carry) % 10;
			carry = 0;
			kq += temp + 48;
		}
		j--;
	}
	while (carry > 0)
	{
		kq += carry + 48;
		carry = 0;
	}

	string kq2 = "";
	if (t == false)
	{
		kq2 += "-";

	}
	else  j = 0;
	for (int i = kq.length() - 1; i >= 0; i--)
	{
		if (kq[i] != '-')
		{
			kq2 += kq[i];
		}
	}



	return kq2;
}

// ham kiem tra bieu thuc

bool check(ofstream& f1, const string s)
{
	int k = 0;
	int len = s.length() - 1;
	// hai toan tu canh nhau
	while (len > 0 && s[len] == ' ')
		len--;

	for (int i = 0; i < len; i++)
	{
		k = i + 1;
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			while (k <= len && s[k] == ' ') k++;
			if (s[k] == '+' || s[k] == '-' || s[k] == '*' || s[k] == '/')
			{
				f1 << "Error" << endl;
				cerr << "Error" << endl;
				return false;
			}
			if (s[k] == ')')
			{
				f1 << "Error" << endl;
				cerr << "Error" << endl;
				return false;
			}
		}
	}
	


	// toan tu dung dau
	if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
	{
		f1 << "Error" << endl;
		cerr << "Error" << endl;
		return false;
	}
	// toan tu dung cuoi
	if (s[len] == '+' || s[len] == '-' || s[len] == '*' || s[len] == '/')
	{
		f1 << "Error" << endl;
		cerr << "Error" << endl;
		return false;
	}

	

	int dem = 0;
	// dau ngoac hop le
	for (int i = 0; i <= len; i++)
	{
		if (s[i] == '(') dem++;
		else if (s[i] == ')')
		{
			if (dem == 0)
			{
				f1 << "Error" << endl;
				cerr << "Error" << endl;
				return false;
			}
			dem--;
		}
	}
	if (dem != 0)
	{
		f1 << "Error" << endl;
		cerr << "Error" << endl;
		return false;
	}
	// ky tu la
	for (int i = 0; i <= len; i++)
	{
		if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != ' ' && s[i] != '(' && s[i] != ')')
		{

			if (s[i] < '0' || s[i] > '9')
			{
				f1 << "Error" << endl;
				cerr << "Error" << endl;
				return false;
			}

		}
	}
	// chia 0
	for (int i = 0; i < len; i++)
	{
		k = i + 1;
		if (s[i] == '/')
		{
			while (k <= len && s[k] == ' ') k++;
			if (s[k] == '0')
			{
				f1 << "Error" << endl;
				cerr << "Error" << endl;
				return false;
			}

		}
	}
	// thieu toan tu sau dau ngoac dong
	for (int i = 0; i < len; i++) {
		if (s[i] == ')') {
			int k = i + 1;
			while (k <= len && s[k] == ' ') k++;
			if (k <= len && s[k] >= '0' && s[k] <= '9') {
				f1 << "Error" << endl;
				cerr << "Error" << endl;
				return false;
			}
		}
	}
	// thieu toan tu hai so
	bool t = false;
	for (int i = 0; i < len; i++) {
		t = false;
		if (s[i] >= '0' && s[i] <= '9') {
			int k = i ;
			while (k <= len && s[k] >= '0' && s[k] <= '9')
			{
				t = true;
				k++;
			}
			while (k <= len && s[k] == ' ')
			{
				t = true;
				k++;
			}
			if (k <= len && s[k] != '-' && s[k] != '+' && s[k] != '*' && s[k] != '/' && t && s[k] != ')') {
				f1 << "Error" << endl;
				cerr << "Error" << endl;
				return false;
			}
		}
	}
	// thieu toan hang
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			int k = i + 1;
			while (k <= len && s[k] == ' ') k++;
			if (s[k] != '(')
				if (k <= len && s[k] < '0' || s[k] > '9') {
					if (s[k] != '-')
					{
						
						f1 << "Error" << endl;
						cerr << "Error" << endl;
						return false;
					}
				}
		}
	}

	return true;
}

// phep chia 

// tru hai so trong phep chia
string  subtract(string  a, string  b) {
	int lenA = a.length(), lenB = b.length();
	int maxLen = lenA;
	string A = "";
	string B = "";
	string result = "";
	A = a;
	B = b;




	while (B.length() < A.length()) {
		B = '0' + B;
	}

	int carry = 0, sub;
	string res = "";


	for (int i = maxLen - 1; i >= 0; --i) {
		sub = (A[i] - '0') - (B[i] - '0') - carry;
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else carry = 0;
		res += sub + '0';
	}

	int pos = res.length() - 1;
	while (pos > 0 && res[pos] == '0') {
		pos--;
	}
	for (int i = pos; i >= 0; --i) {
		result += res[i];
	}

	if (result == "") result = "0";




	return result;
}

//so sanh do dai  hai so trong phep chia
int compare(string  a, string  b) {
	int lenA = a.length(); int  lenB = b.length();
	if (lenA != lenB) return lenA - lenB;
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}
//ham chia chinh
string  chia(string s1, string s2, bool t)
{

	string result = "";
	string temp = "";

	if (t == false)
	{

		result += '-';
	}
	else
	{

	}

	for (int i = 0; i < s2.length(); ++i) {
		int lenT = temp.length();
		temp += s2[i];

		while (temp.length() >= 1 && temp[0] == '0')
			temp.erase(0, 1);

		int thuong = 0;
		while (compare(temp, s1) >= 0) {
			string sub = subtract(temp, s1);
			temp = sub;

			thuong++;
		}
		result += thuong + '0';
	}
	if (result.length() == 0) {
		result = "0";

	}


	int k = 0;
	int dem = 0;
	string result2 = "";
	if (t == false)
	{
		result2 += '-';
		dem = 1;

	}

	while (result[dem] == '0')dem++;

	for (int i = dem; i < result.length(); i++)
	{
		result2 += result[i];
	}
	if (s2 == "0")
	{
		result2 = "0";
	}
	if (result2 == "") return "0";

	return result2;

}

// phep nhan
string nhan(string s1, string s2, bool t)
{
	int len1 = s1.length(), len2 = s2.length();
	int* kq = new int[10000]();
	string  kq2 = "";

	if (s1 == "0" || s2 == "0")
	{
		kq2 = "0";

		return kq2;
	}
	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			int mul = (s1[i] - '0') * (s2[j] - '0');
			int sum = mul + kq[i + j + 1];
			kq[i + j + 1] = sum % 10;
			kq[i + j] += sum / 10;

		}
	}
	int start = 0;
	while (kq[start] == 0)
	{
		start++;
	}
	int k;
	if (t == false)
	{

		kq2 += '-';
	}


	for (int i = start; i < len1 + len2; i++)
	{
		kq2 += kq[i] + '0';
	}

	delete[]kq;
	return kq2;
}

// phep tru
// so sanh do dai hai chuoi trong phep tru
bool isSmaller(const string s1, const string  s2)
{
	int len1 = s1.length();
	int len2 = s2.length();

	if (len1 < len2) return true;
	if (len1 > len2) return false;
	for (int i = 0; i < len1; i++)
	{
		if (s1[i] < s2[i]) return true;
		if (s1[i] > s2[i]) return false;
	}
	return true;
}
// xoa 0 dau du trong phep tru
void xoaodau(string& s)
{
	int len = s.length();
	int start = 0;
	if (s[0] == '-')

		start = 1;



	int i = start;
	while (i < s.length() && s[i] == '0')
		i++;
	s.erase(start, i - start);
	if (s == "-" || s == "")
	{
		s = "0";
	}
}
//ham tru chinh
string  tru(string s1, string s2)
{



	int carry = 0;
	int k = 0;
	if (!isSmaller(s1, s2))
	{
		string tam = s1;
		s1 = s2;
		s2 = tam;
		k = 1;

	}

	int i = s1.length() - 1;
	int j = s2.length() - 1;
	string kq = "";
	if (k == 1) kq += '-';
	while (i >= 0 && j >= 0)
	{
		int temp1 = s1[i] - 48;
		int temp2 = s2[j] - 48;
		if (temp2 - temp1 - carry < 0)
		{
			int temp = temp2 - temp1 - carry + 10;
			carry = 1;
			kq += temp + 48;
		}
		else
		{
			int temp = (temp2 - temp1 - carry);
			carry = 0;
			kq += temp + 48;
		}
		i--;
		j--;

	}

	while (j >= 0)
	{
		int temp2 = s2[j] - 48;
		if (temp2 - carry < 0)
		{
			int temp = (temp2 - carry) + 10;
			carry = 1;
			kq += temp + 48;
		}
		else
		{
			int temp = (temp2 - carry);
			carry = 0;
			kq += temp + 48;
		}
		j--;
	}

	string kq2 = "";
	if (kq[0] == '-')
	{
		kq2 += '-';

	}

	for (int i = kq.length() - 1; i >= 0; i--)
	{
		if (kq[i] != '-')
		{
			kq2 += kq[i];
		}
	}


	if (kq2[0] == '-')
		xoaodau(kq2);
	else xoaodau(kq2);


	return kq2;
}