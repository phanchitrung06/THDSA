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




void duyetNLR(NODE* pRoot,vector<int>&kq)
{
	if (!pRoot)
		return;
	kq.push_back(pRoot->key);
	duyetNLR(pRoot->p_left,kq);
	duyetNLR(pRoot->p_right,kq);

}
void duyetLNR(NODE* pRoot, vector<int>& kq)
{
	if (!pRoot)
		return;
	duyetLNR(pRoot->p_left, kq);
	kq.push_back(pRoot->key);
	duyetLNR(pRoot->p_right, kq);

}
void duyetLRN(NODE* pRoot, vector<int>& kq)
{
	if (!pRoot)
		return;
	duyetLRN(pRoot->p_left, kq);
	duyetLRN(pRoot->p_right, kq);
	kq.push_back(pRoot->key);
}

vector<int> NLR(NODE* pRoot)
{
	vector<int>kq;
	duyetNLR(pRoot,kq);
	return kq;
}

vector<int> LNR(NODE* pRoot)
{
	vector<int>kq;
	duyetLNR(pRoot, kq);
	return kq;
}
vector<int> LRN(NODE* pRoot)
{
	vector<int>kq;
	duyetLRN(pRoot, kq);
	return kq;
	
}




vector<vector<int>> LevelOrder(NODE* pRoot)
{
	vector<vector<int>> kq;
	if (!pRoot)
	{
		return kq;
	}
	queue<NODE*>q;
	q.push(pRoot);
	
	while (!q.empty())
	{
		
		int size = q.size();
		vector<int>v;
		for (int i = 0; i < size; i++)
		{
			NODE* temp = q.front();
			q.pop();
			if (temp->p_left) q.push(temp->p_left);
			if (temp->p_right) q.push(temp->p_right);
			v.push_back(temp->key);
		}
		kq.push_back(v);
		
	}
	return kq;
}

void demnode(NODE* pRoot,int& dem)
{
	if (!pRoot)
		return;
	dem++;
	demnode(pRoot->p_left, dem);
	demnode(pRoot->p_right, dem);
	
}

int countNode(NODE* pRoot)
{
	int dem = 0;
	 demnode(pRoot, dem);
	return dem;
		
}

void tongnode(NODE* pRoot, int& dem)
{
	if (!pRoot)
		return;
	dem+=pRoot->key;
	tongnode(pRoot->p_left, dem);
	tongnode(pRoot->p_right, dem);

}

int sumNode(NODE* pRoot)
{
	int tong = 0;
	tongnode(pRoot, tong);
	return tong;
}
NODE* search(NODE* pRoot, int value)
{
	if (!pRoot)
	{
		return nullptr;
	}
	if (pRoot->key == value)
	{
		return pRoot;
	}
	NODE*left =search(pRoot->p_left, value);
		 NODE*right=search(pRoot->p_right, value);
		 if (left)
			 return left;
		 if (right) return right;
		 return nullptr;
}

int  height(NODE* temp)
{
	if (!temp)
	{
		return -1;
	}
	int left = height(temp->p_left);
	int right = height(temp->p_right);
	if (left > right)
	{
		return left + 1;
	}
	else
	{
		return right + 1;
	}
}

int heightNode(NODE* pRoot, int value)
{
	NODE* temp = search(pRoot, value);
	if (!temp)
	{
		return -1;
	}
	return 	height(temp);
}


int  dosau(NODE* pRoot, NODE* p, int depth)
{
	if ( pRoot==nullptr)
	{
		return -1;
	}
	if (pRoot == p)
	{
		return depth;
	}
	
	int left=dosau(pRoot->p_left, p, depth+1);
	
	if (left != -1) return left;
	return dosau(pRoot->p_right, p, depth + 1);
}

int Level(NODE* pRoot, NODE* p)
{
	int depth = 0;
	return dosau(pRoot, p, depth);

}
void demnla(NODE* pRoot, int& dem)
{
	if (!pRoot) return;
	if (!pRoot->p_left && !pRoot->p_right)
	{
		dem++;
		return;
	}
	
	demnla(pRoot->p_left, dem);
	demnla(pRoot->p_right, dem);
	
}
int countLeaf(NODE* pRoot)
{
	int dem = 0;
	demnla(pRoot, dem);
	return dem;
}

int main()
{
	// Tao cay nhi phan mau nhu so do tren
	NODE* root = createNode(1);
	root->p_left = createNode(2);
	root->p_right = createNode(3);
	root->p_left->p_left = createNode(4);
	root->p_left->p_right = createNode(5);
	root->p_right->p_right = createNode(6);

	// 1. Duyet NLR
	vector<int> nlr = NLR(root);
	cout << "NLR: ";
	for (int x : nlr) cout << x << " ";
	cout << endl;

	// 2. Duyet LNR
	vector<int> lnr = LNR(root);
	cout << "LNR: ";
	for (int x : lnr) cout << x << " ";
	cout << endl;

	// 3. Duyet LRN
	vector<int> lrn = LRN(root);
	cout << "LRN: ";
	for (int x : lrn) cout << x << " ";
	cout << endl;

	// 4. Level-order
	vector<vector<int>> levels = LevelOrder(root);
	cout << "Level-order:" << endl;
	for (int i = 0; i < levels.size(); i++) {
		cout << "Level " << i << ": ";
		for (int x : levels[i]) cout << x << " ";
		cout << endl;
	}

	// 5. Dem so node
	cout << "Tong so node: " << countNode(root) << endl;

	// 6. Tong gia tri node
	cout << "Tong gia tri cac node: " << sumNode(root) << endl;

	// 7. Chieu cao node co gia tri 2
	cout << "Chieu cao node co gia tri 2: " << heightNode(root, 2) << endl;

	// 8. Muc (level) cua node co gia tri 5
	NODE* node5 = search(root, 5);
	if (node5)
		cout << "Level cua node co gia tri 5: " << Level(root, node5) << endl;
	else
		cout << "Khong tim thay node co gia tri 5" << endl;

	// 9. So luong la node
	cout << "So luong node la: " << countLeaf(root) << endl;

	return 0;

}