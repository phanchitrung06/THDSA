#include<iostream>
#include<vector>
#include <queue>
using namespace std;
struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
};

NODE* createNode(int data)
{
	NODE* p = new NODE;
	p->key = data;
	p->p_left = nullptr;
	p->p_right = nullptr;
	return p;
}

NODE* Search(NODE* pRoot, int x)
{
	if (!pRoot||pRoot->key==x)
	{
		return pRoot;
	}

	
	 if (pRoot->key < x)
	{
		
		 return Search(pRoot->p_right, x);
	}
	else
	{
		return Search(pRoot->p_left, x);
	}
	
	
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
		else
		{
			Insert(pRoot->p_right, x);
		}
	}
}
void Remove(NODE*& pRoot, int x)
{
	if (!pRoot)
	{
		return;
	}
	if (x < pRoot->key)
	{
		Remove(pRoot->p_left, x);
	}
	else if (x>pRoot->key)
	{
		Remove(pRoot->p_right, x);

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
			NODE* parent = pRoot;
			while (temp->p_left)
			{
				parent = temp;
				temp = temp->p_left;
			}
			pRoot->key = temp->key;
			if (parent == pRoot)
			{
				parent->p_right = temp->p_right;
			}
			else
			{
				parent->p_left = temp->p_right;
			}
			delete temp;
		}
		else
		{
			if (pRoot->p_left&&!pRoot->p_right)
			{
				NODE* temp = pRoot;
				pRoot = pRoot->p_left;
				delete temp;
			}
			else if (pRoot->p_right&& !pRoot->p_left)
			{
				NODE* temp = pRoot;
				pRoot = pRoot->p_right;
				delete temp;
			}
			
		}
	}
	
}



NODE* createTree(int a[], int n)
{
	NODE* tree = createNode(a[0]);
	for (int i = 1; i < n; i++)
	{
		Insert(tree, a[i]);
	}
	return tree;
}

void removeTree(NODE*& pRoot)
{
	if (!pRoot)
		return;
	removeTree(pRoot->p_left);
	removeTree(pRoot->p_right);
	delete pRoot;
	pRoot = nullptr;
}

int Height(NODE* pRoot)
{
	if (!pRoot)
	{
		return -1;
	}
	int left=	Height(pRoot->p_left);
	int right = Height(pRoot->p_right);
	if (left > right)
	{
		return left + 1;
	}

	
		return right + 1;
	
}
void Less(NODE* pRoot,int& dem,int x)
{
	if (!pRoot)
	{
		return;
	}
	if (pRoot->key < x)
	{
		dem++;
		Less(pRoot->p_left, dem, x);
		Less(pRoot->p_right, dem, x);
	}
	else
	{
		Less(pRoot->p_left, dem, x);
	}
}
int countLess(NODE* pRoot, int x)
{
	
		int dem = 0;
		Less(pRoot,dem,x);
		return dem;
}
void greate(NODE* pRoot, int& dem, int x)
{
	if (!pRoot)
	{
		return;
	}
	if (pRoot->key > x)
	{
		dem++;
		
		greate(pRoot->p_right, dem, x);
		greate(pRoot->p_left, dem, x);
	}
	else
	{
		greate(pRoot->p_right, dem, x);
	}
}
int countGreater(NODE* pRoot, int x)
{
	int dem = 0;
	greate(pRoot, dem, x);
	return dem;
}

bool kiemtrabst(NODE* pRoot,NODE* left,NODE* right)
{
	if (!pRoot)
	{
		return true;
	}
	if ((left && pRoot->key <= left->key) || (right && pRoot->key >= right->key))
	{
		return false;
	}
	return	kiemtrabst(pRoot->p_left, left,pRoot) && kiemtrabst(pRoot->p_right, pRoot, right);
	
}

bool isBST(NODE* pRoot)
{
	
	return kiemtrabst(pRoot,nullptr, nullptr);
}
bool kiemtrafullbst(NODE* pRoot)
{
	if (!pRoot)
	{
		return true;
	}
	if (pRoot->p_left && !pRoot->p_right)
	{
		return false;
	}
	else if (!pRoot->p_left && pRoot->p_right)
	{
		return false;
	}
	return kiemtrafullbst(pRoot->p_left) && kiemtrafullbst(pRoot->p_right);
}

bool isFullBST(NODE* pRoot)
{
	
	return kiemtrafullbst(pRoot) && isBST(pRoot);
	
}

int main()
{
	int a[] = { 20, 10, 30, 5, 15, 25, 35 };
	NODE* root = createTree(a, 7);

	cout << "Is Full BST before removal: " << (isFullBST(root) ? "true" : "false") << "\n";

	Remove(root, 25);

	cout << "Is Full BST after removing 25: " << (isFullBST(root) ? "true" : "false") << "\n";

	removeTree(root);
}