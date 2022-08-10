#include<iostream>
#include<vector>
#include<list>
using namespace std;
// Adding edges of a graph
void addEdge(vector<int> adjList[], int u, int v)
{
	adjList[u].push_back(v);
}
// Printing Graph
void PrintGraph(vector<int> adjList[], int n)
{
	cout << "\nTHE ADJACENCY LIST OF THE GRAPH\n";
	for (int i = 1; i <= n; i++)
	{
		cout << "For Vertex " << i << " -> ";
		for (int j = 0; j < adjList[i].size(); j++)
		{
			cout << adjList[i][j] << " ->";
		}
		cout << "null" << endl;
	}
	return;
}
// DFS Traversal of Graph
void dfs(vector<int> adjList[],int v, bool visited[]) {
	
	visited[v] = true;
	cout << v << " ";
	
	for (int i = 0; i < adjList[v].size(); i++)
	{
		int t = adjList[v][i];
		if (!visited[t])
			dfs(adjList, t, visited);
	}
	return;
}
// BFS Traversal of Graph
void bfs(vector<int> adjList[], int v, int n)
{
	bool visited[25];
	for (int i = 1; i <= n; i++)
		visited[i] = false;

	list<int> queue;

	visited[v] = true;
	queue.push_back(v);

	while (!queue.empty())
	{
		v = queue.front();
		cout << v << " ";
		queue.pop_front();

		for (auto k : adjList[v])
		{
		//	int k = adjList[v][i];
			if (!visited[k])
			{
				visited[k] = true;
				queue.push_back(k);
			}
		}
	}
	return;
}
int main()
{
	int n;
	cout << "\nENTER THE NUMBER OF NODES \n";
	cin >> n;
	// Adjacency list representation
	vector<int> adjList[25];
	int no_edges;
	cout << "\nENTER THE NUMBER OF EDGES\n";
	cin >> no_edges;
	int a, b;
	for (int i = 0; i < no_edges; i++)
	{
		cout << "\nENTER THE DIRECTED EDGE a->b \n";
		cin >> a >> b;
		addEdge(adjList, a, b);
	}
	PrintGraph(adjList, n);
	bool visited[25];
	for (int i = 0; i <= n; i++)
	{
		visited[i] = false;
	}
	cout << "\nDFS TRAVERSAL OF THE GRAPH STARTING FROM VERTEX 1\n";
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			dfs(adjList, i, visited);
		}
	}
	cout << endl;
	cout << "\nBFS TRAVERSAL OF THE GRAPH STARTING FROM VERTEX 1\n";
	bfs(adjList, 1, n);
	return 0;
}