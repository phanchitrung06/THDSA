#include <iostream>
#include<fstream>
#include<string>

using namespace std;


struct NODE
{
	int key;
	NODE* p_next;


};

struct Stack
{
	NODE* top;


};


NODE* createnode(int key)
{
	NODE* p = new NODE;
	p->key = key;
	p->p_next = nullptr;
	return p;
}

Stack* initializeStack(Stack* s)
{

	s->top = nullptr;
	return s;
}

void push(Stack* s, int key)
{
	NODE* p = createnode(key);
	if (s->top == nullptr)
	{
		s->top = p;
	}
	else
	{
		p->p_next = s->top;
		s->top = p;
	}
}

bool isEmpty(Stack* s)
{
	if (s->top == nullptr)
		return true;
	return false;
}


int pop(Stack* s)
{



	int val = s->top->key;
	NODE* p = s->top;
	if (s->top->p_next)
		s->top = s->top->p_next;
	else
	{
		s->top = nullptr;
	}
	delete p;
	return val;

}


int size(Stack* s)
{

	int dem = 0;
	
	NODE* p = s->top;
	while (p)
	{
		dem++;
		p=p->p_next;
	}
	return dem;
}

void in(ofstream& f1, Stack* s)
{
	Stack* tam = new Stack;
	initializeStack(tam);
	if (s->top)
	{
		NODE* p = s->top;
		while (p)
		{

			push(tam, p->key);

			if (p->p_next)
				p = p->p_next;
			else break;
		}
		while (!isEmpty(tam))
		{
			f1 << pop(tam) << " ";
		}

	}
	else f1 << "EMPTY";
	f1 << endl;
	delete tam;
}

void process(ofstream& f1, Stack* s, string temp, string temp2)
{


	if (temp == "init")
	{

		s = initializeStack(s);
		f1 << "EMPTY" << endl;
	}
	else if (temp == "push")
	{
		int n = stoi(temp2);
		push(s, n);
		in(f1, s);
	}
	else if (temp == "pop")
	{
		if (!isEmpty(s))
			pop(s);
		in(f1, s);
	}
	else if (temp == "size")
	{
		f1 << size(s) << endl;
	}
	else if (temp == "isEmpty")
	{
		in(f1,s);
		
	}
}

int main()
{

	string s1;
	Stack* s = new Stack;
	ifstream f;
	ofstream f1;
	f1.open("output.txt");
	f.open("input.txt");
	while (getline(f, s1))
	{

		string temp = "";
		string temp2 = "";
		bool t = true;
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ' && t)
				temp = temp + s1[i];
			else if (s1[i] == ' ')
			{
				t = false;
			}
			else
			{
				temp2 = temp2 + s1[i];
			}

		}
		process(f1, s, temp, temp2);
	}
	f.close();
	f1.close();
	delete s;
}