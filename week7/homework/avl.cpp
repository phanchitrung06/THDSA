#include<iostream>
#include<vector>
#include <queue>
using namespace std;
struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};

NODE* createNode(int data)
{
	NODE* p = new NODE;
	p->key = data;
	p->p_left = nullptr;
	p->p_right = nullptr;
	p->height = 0;
	return p; 
}
int height(NODE* p) {
	if (p == nullptr)
		return -1;
	else
		return p->height;
}
void xoaytrai(NODE*& pRoot)
{
	NODE* temp = pRoot;
	pRoot = temp->p_right;
	temp->p_right = pRoot->p_left;
	pRoot->p_left = temp;
	if (height(temp->p_left) > height(temp->p_right))
		temp->height = height(temp->p_left) + 1;
	else
		temp->height = height(temp->p_right) + 1;

	if (height(pRoot->p_left) > height(pRoot->p_right))
		pRoot->height = height(pRoot->p_left) + 1;
	else
		pRoot->height = height(pRoot->p_right) + 1;
}
void xoayphai(NODE*& pRoot)
{
	NODE* temp = pRoot;
	pRoot = temp->p_left;
	temp->p_left = pRoot->p_right;
	pRoot->p_right = temp;
	if (height(temp->p_left) > height(temp->p_right))
		temp->height = height(temp->p_left) + 1;
	else
		temp->height = height(temp->p_right) + 1;
	if (height(pRoot->p_left) > height(pRoot->p_right))
		pRoot->height = height(pRoot->p_left) + 1;
	else
		pRoot->height = height(pRoot->p_right) + 1;
}
int getBalance(NODE* p) {
	if (!p) return 0;
	return height(p->p_left) - height(p->p_right);
}
void Insert(NODE*& pRoot, int x)
{
	if (!pRoot)
	{
		NODE* p = createNode(x);
		pRoot = p;
	}
	else
	{
		if (x < pRoot->key)
		{
			Insert(pRoot->p_left, x);
		}
		else if (x > pRoot->key)
		{
			Insert(pRoot->p_right, x);
		}
		else return;
	}

	if (height(pRoot->p_left) > height(pRoot->p_right))
		pRoot->height = height(pRoot->p_left) + 1;
	else
		pRoot->height = height(pRoot->p_right) + 1;
	int balance = getBalance(pRoot);
	if (balance > 1&&pRoot->p_left&&x<pRoot->p_left->key)
	{
		xoayphai(pRoot);
		return;
	}
	else if (balance < -1&&pRoot->p_right && x > pRoot->p_right->key)
	{
		xoaytrai(pRoot);
		return;
	}
	else if (balance > 1 &&pRoot->p_left&& x > pRoot->p_left->key)
	{
		xoaytrai(pRoot->p_left);
		xoayphai(pRoot);
		return;
	}
	else if(balance <-1 && pRoot->p_right && x < pRoot->p_right->key)
	{
		xoayphai(pRoot->p_right);
		xoaytrai(pRoot);
		return;
	}
}

void Remove(NODE*& pRoot, int x)
{
	if (!pRoot)
	{
		return;
	}
	if (x > pRoot->key)	
	{
		Remove(pRoot->p_right, x);
	}
	else if (x < pRoot->key)
	{
		Remove(pRoot->p_left, x);
	}
	else
	{
		if (!pRoot->p_left && !pRoot->p_right)
		{
			delete pRoot;
			pRoot = nullptr;
		}
		else if (pRoot->p_left && pRoot->p_right)
		{
			NODE* temp = pRoot->p_right;
			while (temp->p_left)
				temp = temp->p_left;

			pRoot->key = temp->key;
			Remove(pRoot->p_right, temp->key);
			
		}
		else
		{
			if (pRoot->p_left)
			{
				NODE* temp = pRoot;
				pRoot = temp->p_left;
				delete temp;

			}
			else  
			{
				NODE* temp = pRoot;
				pRoot = temp->p_right;
				delete temp;

			}
		}
	}
	if (!pRoot) return;
	if (height(pRoot->p_left) > height(pRoot->p_right))
		pRoot->height = height(pRoot->p_left) + 1;
	else
		pRoot->height = height(pRoot->p_right) + 1;
	int balance = getBalance(pRoot);
	if (balance > 1 && getBalance(pRoot->p_left) >= 0)
	{
		xoayphai(pRoot);
		return;
	}
	else if (balance < -1 && getBalance(pRoot->p_right)<=0)
	{
		xoaytrai(pRoot);
		return;
	}
	else if (balance > 1 && getBalance(pRoot->p_left) <= 0)
	{
		xoaytrai(pRoot->p_left);
		xoayphai(pRoot);
		return;
	}
	else if (balance < -1 && getBalance(pRoot->p_right) >= 0)
	{
		xoayphai(pRoot->p_right);
		xoaytrai(pRoot);
		return;
	}

}
bool kiemtrabst(NODE* pRoot, NODE* left, NODE* right)
{
	if (!pRoot)
	{
		return true;
	}
	if ((left && pRoot->key <= left->key) || (right && pRoot->key >= right->key))
	{
		return false;
	}
	return	kiemtrabst(pRoot->p_left, left, pRoot) && kiemtrabst(pRoot->p_right, pRoot, right);

}
bool kiemtraavl(NODE*pRoot)
{
	if (!pRoot)
	{
		return true;
	}
	 int left=height(pRoot->p_left);
	 int right= height(pRoot->p_right);
	 if (abs(left - right) > 1)
	 {
		 return false;
	 }
	 return kiemtraavl(pRoot->p_left) && kiemtraavl(pRoot->p_right);
}
bool isAVL(NODE* pRoot)
{
	return kiemtrabst(pRoot, nullptr,nullptr)&&kiemtraavl(pRoot);
}

void inorderPrint(NODE* pRoot)
{
	if (!pRoot)
		return;
	inorderPrint(pRoot->p_left);
	cout << pRoot->key << " ";
	inorderPrint(pRoot->p_right);
}

int main()
{
	
	NODE* root = nullptr;


	Insert(root, 30);
	Insert(root, 20);
	Insert(root, 40);
	Insert(root, 10);
	Insert(root, 25);
	Insert(root, 100);
	Insert(root, 70);
	Insert(root, 80);
	Insert(root, 90);

	cout << "Cay AVL truoc khi xoa:" << endl;
	inorderPrint(root);
	cout << (isAVL(root) ? "La cay AVL" : "Khong phai cay AVL") << endl;

	
	Remove(root, 50);

	cout << "Cay AVL sau khi xoa nut 50 (khong ton tai):" << endl;
	inorderPrint(root);
	cout << (isAVL(root) ? "La cay AVL" : "Khong phai cay AVL") << endl;

	

 
	



	return 0;
}