#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
using namespace std;


vector<vector<int>> convertMatrixToList(const string& filename)
{
	int n;
	vector<vector<int>> v;

	ifstream f;
	f.open(filename);
	f >> n;

	for (int i = 0; i < n; i++)
	{
		vector<int >temp;
		for (int j = 0; j < n; j++)
		{

			int tam;
			f >> tam;
			if (tam > 0)
			{
				temp.push_back(j);

			}

		}
		v.push_back(temp);
	
	}
	f.close();
	

	return v;
}
vector<vector<int>> convertListToMatrix(const string& filename)
{
	int n;
	vector<vector<int>> v;
	int n1;

	ifstream f;
	f.open(filename);
	f >> n;

	for (int i = 0; i < n; i++)
	{
		vector<int >temp(n, 0);
		f >> n1;
		for (int j = 0; j < n1; j++)
		{

			int tam;
			f >> tam;

			temp[tam] = 1;




		}

		v.push_back(temp);
		temp.clear();
	}
	f.close();

	return v;
}
bool isDirected(const vector<vector<int>>& adjMatrix)
{
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix[0].size(); j++)
		{
			if (adjMatrix[i][j] != adjMatrix[j][i]) return true;

		}
	}
	return false;
}
int countVertices(const vector<vector<int>>& adjMatrix)
{
	return adjMatrix.size();
}

int countEdges(const vector<vector<int>>& adjMatrix)
{
	int dem = 0;
	bool directed = isDirected(adjMatrix);
	vector<vector<int>>kq = adjMatrix;
	if (directed)
	{
		for (int i = 0; i < kq.size(); i++)
		{
			for (int j = 0; j < kq[0].size(); j++)
			{
				if (kq[i][j] > 0)
				{
					
					dem++;
				}

			}
		}
	}
	else
	{
		for (int i = 0; i < kq.size(); i++)
		{
			for (int j = i+1; j < kq[0].size(); j++)
			{
				if (kq[i][j] > 0)
				{

					dem++;
				}

			}
		}
	}
	return dem;
}

vector<int> getIsolatedVertices(const vector<vector<int>>& adjMatrix)
{
	vector<bool>v(adjMatrix.size(), false);
	vector<int>kq;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix[0].size(); j++)
		{
			if (adjMatrix[i][j] > 0)
			{
				if (v[i] == false)
				{

					v[i] = true;
				}
				if (v[j] == false)
				{

					v[j] = true;
				}
			}

		}
	}
	for (int i = 0; i < adjMatrix.size(); i++)
		if (v[i] == false) kq.push_back(i);
			return kq;
}
bool isCompleteGraph(const vector<vector<int>>& adjMatrix)
{
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix[0].size(); j++)
		{
			if (adjMatrix[i][j] ==0 && i != j) return false;
		}
	}
	return true;
}
bool isBipartite(const vector<vector<int>>& adjMatrix)
{

	vector<int>color(adjMatrix.size(), -1);
	for (int start = 0; start < adjMatrix.size(); start++) {
		if (color[start] == -1)
		{
			queue<int> q;
			q.push(start);
			color[start] = 0;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int i = 0; i < adjMatrix.size(); i++)
				{
					if (adjMatrix[u][i] > 0)
					{
						if (color[i] == -1)
						{
							color[i] = 1 - color[u];
							q.push(i);
						}
						else if (color[u] == color[i]) return false;

					}
				}
			}
		}
	}
	return true;
}
bool isCompleteBipartite(const vector<vector<int>>& adjMatrix)
{
	vector<int>color(adjMatrix.size(), -1);
	for (int start = 0; start < adjMatrix.size(); start++) {
		if (color[start] == -1)
		{
			queue<int> q;
			q.push(start);
			color[start] = 0;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int i = 0; i < adjMatrix.size(); i++)
				{
					if (adjMatrix[u][i] >0)
					{
						if (color[i] == -1)
						{
							color[i] = 1 - color[u];
							q.push(i);
						}
						else if (color[u] == color[i]) return false;

					}
				}
			}
		}
	}
	int count0 = 0;
	int count1 = 0;
	for (int x : color)
	{
		if (x==0)
		count0++;
		else 
		count1++;
	}
	int canh = 0;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix[0].size(); j++)
		{
			if (adjMatrix[i][j] > 0)
			{
				if (color[i] != color[j])
					canh++;
				else return false;
			}
		}
	}
	canh = canh / 2;
	return canh == count1 * count0;
}
vector<vector<int>> convertToUndirectedGraph(const vector<vector<int>>& adjMatrix)
{
	vector<vector<int>> kq=adjMatrix;
	
	for (int i = 0; i < adjMatrix.size(); i++) {
		for (int j = i + 1; j < adjMatrix[0].size(); j++) {
			int a = adjMatrix[i][j];
			int b = adjMatrix[j][i];

			if (a > 0 && b > 0) {
				if (a>b)
				kq[i][j] = kq[j][i] = b;
				else
					kq[i][j] = kq[j][i] = a;

			}
			else if (a > 0) {
				
				kq[i][j] = kq[j][i] = a;
			}
			else if (b > 0) {
			
				kq[i][j] = kq[j][i] = b;
			}
		}
	}
	return kq;

}
vector<vector<int>> getComplementGraph(const vector<vector<int>>& adjMatrix)
{
	vector<vector<int>> kq = adjMatrix;

	for (int i = 0; i < adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix[0].size(); j++)
		{
			if (adjMatrix[i][j] == 0&&i!=j)
			{
				kq[i][j] = 1;
			}
			else if (adjMatrix[i][j] >0 && i != j)
			{
				kq[i][j] = 0;
			}
		}
	}
	return kq;
} 


bool hasEulerCycle(const vector<vector<int>>& adj, bool directed) {
	int n = adj.size();
	if (directed) {
		vector<int> inDeg(n, 0), outDeg(n, 0);
		for (int u = 0; u < n; ++u)
			for (int v = 0; v < n; ++v) {
				outDeg[u] += adj[u][v];
				inDeg[v] += adj[u][v];
			}
		for (int i = 0; i < n; ++i)
			if (inDeg[i] != outDeg[i])
				return false;
		return true;
	}
	else {
		for (int i = 0; i < n; ++i) {
			int deg = 0;
			for (int j = 0; j < n; ++j)
				deg += adj[i][j];
			if (deg % 2 != 0) return false;
		}
		return true;
	}
}

vector<int> findEulerCycle(const vector<vector<int>>& adjMatrix) {
	vector<vector<int>>adj = adjMatrix;
	int n = adj.size();
	bool directed = isDirected(adj);
	if (!hasEulerCycle(adj, directed))
		return {};

	stack<int> st;
	vector<int> cycle;

	
	int start = 0;
	for (; start < n; ++start) {
		int deg = 0;
		for (int v = 0; v < n; ++v)
			deg += adj[start][v];
		if (deg > 0) break;
	}
	if (start == n) return {};

	st.push(start);

	while (!st.empty()) {
		int u = st.top();
		bool hasEdge = false;
		for (int v = 0; v < n; ++v) {
			if (adj[u][v] > 0) {
				
				if (!directed) {
					adj[u][v]--;
					adj[v][u]--;
				}
				else {
					adj[u][v]--;
				}
				st.push(v);
				hasEdge = true;
				break;
			}
		}
		if (!hasEdge) {
			cycle.push_back(u);
			st.pop();
		}
	}

	reverse(cycle.begin(), cycle.end());
	return cycle;
}
void dfs(const vector<vector<int>>& v,int start, vector<vector<int>>& kq,vector<bool>&check)
{
	check[start] = false;
		for (int j = 0; j < v[0].size(); j++)
		{
			if (v[start][j] >0 &&check[j])
			{
				check[j] = false;
				kq.push_back({start,j});
				dfs(v, j, kq,check);
			}
		}
	
}
vector<vector<int>> dfsSpanningTree(const vector<vector<int>>& adjMatrix, int start)
{
	vector<vector<int>> temp;
	vector<bool> check(adjMatrix.size(),true);
	dfs(adjMatrix, start, temp,check);
	for (int i = 0; i < adjMatrix[0].size(); i++)
	{
		if (check[i] == true) return {};
	}
	return temp;
}
vector<vector<int>> bfs(const vector<vector<int>>& v, int start)
{
	vector<vector<int>> kq;
	queue<int>q ;
	q.push(start);
	vector<bool> visited(v.size(), false);
	visited[start] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int j = 0; j < v[0].size(); j++)
		{
			if (v[u][j]>0 && visited[j] == false)
			{
				kq.push_back({ u,j });
				q.push(j);
				visited[j] = true;
				

			}
		}
	}
	for (int i = 0; i < v[0].size(); i++)
	{
		if (visited[i] == false) return {};
	}
	return kq;
}
vector<vector<int>> bfsSpanningTree(const vector<vector<int>>& adjMatrix, int start)
{

	
	return bfs(adjMatrix, start);
}
void dfsconnect(const vector<vector<int>>&v,int start,vector<bool>& check)
{
	check[start] = false;
	for (int i = 0; i < v.size(); i++)
	{
		if (check[i] && v[start][i] > 0)
		{
			check[i] = false;
			dfsconnect(v, i, check);
		}
	}
}
bool isConnected(int u, int v, const vector<vector<int>>& adjMatrix)
{
	vector<bool>check(adjMatrix.size(), true);
	dfsconnect(adjMatrix,u,check);
	if (!check[v])
	{
		return true;
	}
	else return false;
}
vector<int> dijkstra(int start, int end, const vector<vector<int>>& adjMatrix)
{
	int n = adjMatrix.size();
	vector<int> dist(n, 1e9);
	vector<int> prev(n, -1);
	vector<bool> check(n, false);
	dist[start] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1;
		int min = 1e9;
		for (int j = 0; j < n; j++)
		{
			if (check[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		if (u == -1) break;

		check[u] = true;
			for (int j = 0; j < n; j++)
			{
				if (adjMatrix[u][j] > 0 && check[j] == false)
				{
					int newdist = dist[u] + adjMatrix[u][j];
					if (newdist < dist[j])
					{
						dist[j] = newdist;
						prev[j] = u;
					}
				}
			}
		
	}
	if (dist[end] ==1e9) return {};
	vector<int> path;
	path.push_back(end);
	while (start != end)
	{
		end = prev[end];
		path.push_back(end);
	}
	int l = 0;
	int r = path.size() - 1;

	while (l < r)
	{
		int temp = path[l];
		path[l] = path[r];
		path[r] = temp;
		l++;
		r--;
	}
	
	return path;
}

vector<int> bellmanFord(int start, int end, const vector<vector<int>>& adjMatrix) {
	int V = adjMatrix.size();
	vector<int> dist(V, 1e9);
	vector<int> parent(V, -1);
	dist[start] = 0;

	for (int i = 0; i < V - 1; i++) {
		for (int u = 0; u < V; u++) {
			for (int v = 0; v < V; v++) {
				if (adjMatrix[u][v] != 0 && dist[u] + adjMatrix[u][v] < dist[v]) {
					dist[v] = dist[u] + adjMatrix[u][v];
					parent[v] = u;
				}
			}
		}
	}


	for (int u = 0; u < V; u++) {
		for (int v = 0; v < V; v++) {
			if (adjMatrix[u][v] != 0 && dist[u] + adjMatrix[u][v] < dist[v]) {
			
				return {};
			}
		}
	}

	if (dist[end] >= 1e9) return {};

	vector<int> path;
	for (int at = end; at != -1; at = parent[at])
		path.push_back(at);
	reverse(path.begin(), path.end());
	return path;
}


int main()
{
	vector<vector<int>> adjMatrix = convertListToMatrix("input.txt");

	// In ma tr?n k? ra màn h?nh
	cout << "Adjacency matrix:\n";
	for (const auto& row : adjMatrix) {
		for (int x : row) cout << x << " ";
		cout << "\n";
	}

	cout << "\nIs directed? " << (isDirected(adjMatrix) ? "Yes" : "No") << "\n";
	cout << "Number of vertices: " << countVertices(adjMatrix) << "\n";
	cout << "Number of edges: " << countEdges(adjMatrix) << "\n";

	vector<int> isolated = getIsolatedVertices(adjMatrix);
	cout << "Isolated vertices: ";
	if (isolated.empty()) cout << "None";
	else for (int v : isolated) cout << v << " ";
	cout << "\n";

	cout << "Is complete graph? " << (isCompleteGraph(adjMatrix) ? "Yes" : "No") << "\n";
	cout << "Is bipartite? " << (isBipartite(adjMatrix) ? "Yes" : "No") << "\n";
	cout << "Is complete bipartite? " << (isCompleteBipartite(adjMatrix) ? "Yes" : "No") << "\n";

	vector<vector<int>> complement = getComplementGraph(adjMatrix);
	cout << "\nComplement graph adjacency matrix:\n";
	for (const auto& row : complement) {
		for (int x : row) cout << x << " ";
		cout << "\n";
	}

	// Test spanning tree b?ng DFS t? ð?nh 0
	auto dfsTree = dfsSpanningTree(adjMatrix, 0);
	if (dfsTree.empty()) cout << "\nGraph not connected by DFS\n";
	else {
		cout << "\nDFS spanning tree edges:\n";
		for (auto& e : dfsTree) cout << e[0] << " - " << e[1] << "\n";
	}

	// Test spanning tree b?ng BFS t? ð?nh 0
	auto bfsTree = bfsSpanningTree(adjMatrix, 0);
	if (bfsTree.empty()) cout << "\nGraph not connected by BFS\n";
	else {
		cout << "\nBFS spanning tree edges:\n";
		for (auto& e : bfsTree) cout << e[0] << " - " << e[1] << "\n";
	}

	// Ki?m tra tính liên thông gi?a ð?nh 0 và 3
	cout << "\nIs connected (0,3)? " << (isConnected(0, 3, adjMatrix) ? "Yes" : "No") << "\n";

	// Test t?m chu tr?nh Euler (n?u có)
	bool directed = isDirected(adjMatrix);
	if (hasEulerCycle(adjMatrix, directed)) {
		auto eulerCycle = findEulerCycle(adjMatrix);
		cout << "\nEuler cycle:\n";
		for (int v : eulerCycle) cout << v << " ";
		cout << "\n";
	}
	else cout << "\nNo Euler cycle\n";

	// Test thu?t toán Dijkstra t? 0 ð?n 3
	auto pathDijkstra = dijkstra(0, 3, adjMatrix);
	if (pathDijkstra.empty()) cout << "\nNo path found by Dijkstra from 0 to 3\n";
	else {
		cout << "\nShortest path by Dijkstra from 0 to 3:\n";
		for (int v : pathDijkstra) cout << v << " ";
		cout << "\n";
	}

	// Test thu?t toán Bellman-Ford t? 0 ð?n 3
	auto pathBF = bellmanFord(0, 3, adjMatrix);
	if (pathBF.empty()) cout << "\nNo path found by Bellman-Ford from 0 to 3 or negative cycle detected\n";
	else {
		cout << "\nShortest path by Bellman-Ford from 0 to 3:\n";
		for (int v : pathBF) cout << v << " ";
		cout << "\n";
	}

	return 0;
	
}