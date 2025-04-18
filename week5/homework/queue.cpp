#include <iostream>
#include<fstream>
#include<string>
using namespace std;

struct NODE {
	int key;
	NODE* p_next;
};

struct Queue
{
	NODE* head;
	NODE* tail;
};
NODE* createnode(int key)
{
	NODE* p = new NODE;
	p->key = key;
	p->p_next = nullptr;
	return p;
}

Queue * initializeQueue(Queue* q)
{

	q->head = nullptr;
	q->tail = nullptr;
	return q;
}

void enqueue(Queue * q, int key)
{
	NODE* p = createnode(key);
	if (q->head == nullptr)
	{
		q->head = p;
		q->tail = p;
	}
	else
	{
		q->tail->p_next = p;
		q->tail = p;
	}
}

int dequeue(Queue* q)
{
	int val = q->head->key;
	NODE* temp = q->head;
	if (temp->p_next)
	q->head = temp->p_next;
	else
	{
		q->head = nullptr;
		q->tail = nullptr;
	}
	delete temp;
	return val;
}

int size(Queue* q)
{
	int dem = 0;
	NODE* p = q->head;
	while (p)
	{
		dem++;
		p = p->p_next;
	}
	return dem;
}
bool isEmpty(Queue* q)
{
	if (q->head == nullptr)
	{
		return true;
	}
	return false;
}

void in(ofstream& f1, Queue* q)
{
	
	
	if (q->head)
	{
		NODE* p = q->head;
		while (p)
		{
			f1 << p->key<<" ";
			p = p->p_next;
		}
	}
	else f1 << "EMPTY";
	f1 << endl;
	
}


void process(ofstream& f1, Queue* q, string temp, string temp2)
{


	if (temp == "init")
	{

		q = initializeQueue(q);
		f1 << "EMPTY" << endl;
	}
	else if (temp == "enqueue")
	{
		int n = stoi(temp2);
		enqueue(q, n);
		in(f1, q);
	}
	else if (temp == "dequeue")
	{
		if (!isEmpty(q))
			dequeue(q);
		in(f1, q);
	}
	else if (temp == "size")
	{
		f1 << size(q) << endl;
	}
	else if (temp == "isEmpty")
	{
		if (isEmpty(q))
			f1 << "EMPTY" << endl;
		else
		{
			in(f1, q);
		}
	}
}


int main()
{
	string s1="";
	Queue* q = new Queue;
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
		process(f1, q, temp, temp2);
	}
	f.close();
	f1.close();
	delete q;
}