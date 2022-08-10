#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
int n;
int no_edges;
char label[50];
bool isCycle;
int cnt;
// Adding edges of a graph
void addEdge(vector<int> adjList[], int u, int v)
{
	adjList[u].push_back(v);
}
// Printing Graph
void PrintGraph(vector<int> adjList[], int n)
{
	cout << "\nTHE ADJACENCY LIST OF THE GRAPH\n";
	for (int i = 0; i < n; i++)
	{
		cout << "For Vertex " << label[i] << " -> ";
		for (int j = 0; j < adjList[i].size(); j++)
		{
			cout << label[adjList[i][j]] << " ->";
		}
		cout << "null" << endl;
	}
	return;
}
// dfs Topological sort
bool dfsTopologicalSort(vector<int> adjList[], int v, int n, bool visited[], bool done[], int nodeOrder[])
{
	visited[v] = true;
	for (auto a : adjList[v])
	{
	//	cout << " a is" << label[a] << " visited is " << visited[a] <<" "<< done[a] << endl;
		if (!visited[a])
			dfsTopologicalSort(adjList, a, n, visited, done, nodeOrder);
		else
		if (visited[a] && !done[a])
		{
			isCycle = true;
			return true; 
		}
	}
	done[v] = true;
	nodeOrder[cnt - 1] = v;
	cnt--;
	return false;
}
// bfs Topological sort
bool bfsTopologicalSort(vector<int> adjList[], int n)
{
	int inVertices[25];
	for (int i = 0; i < n; i++)
		inVertices[i] = 0;
	list<int> que;
	for (int i = 0; i < n; i++)
	{
		for (auto a : adjList[i])
		{
			inVertices[a]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (inVertices[i] == 0)
		{
			que.push_back(i);
			inVertices[i] = -1;
		}
	}
	cout << "\nTOPOLOGICAL SORT IN BFS MANNER\n";
	while (!que.empty()) {
		int v = que.front();
		cout << label[v] << " ";
		que.pop_front();
		for (auto a : adjList[v])
		{
			inVertices[a]--;
		}
		for (int i = 0; i < n; i++)
		{
			if (inVertices[i] == 0)
			{
				que.push_back(i);
				inVertices[i] = -1;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (inVertices[i] != -1)
			return true;
	}
	return false;	
}
void createGraph1(vector<int> adjList[])
{
	n = 8;
	no_edges = 13;
	cnt = 8;
	strcpy_s(label, "12345678");
	addEdge(adjList, 1 - 1, 2 - 1);
	addEdge(adjList, 1 - 1, 5 - 1);
	addEdge(adjList, 1 - 1, 6 - 1);
	addEdge(adjList, 2 - 1, 3 - 1);
	addEdge(adjList, 2 - 1, 5 - 1);
	addEdge(adjList, 2 - 1, 7 - 1);
	addEdge(adjList, 3 - 1, 4 - 1);
	addEdge(adjList, 4 - 1, 5 - 1);
	addEdge(adjList, 5 - 1, 7 - 1);
	addEdge(adjList, 5 - 1, 8 - 1);
	addEdge(adjList, 6 - 1, 8 - 1);
	addEdge(adjList, 7 - 1, 4 - 1);
	addEdge(adjList, 7 - 1, 8 - 1);
	return;
}
void createGraph2(vector<int> adjList[])
{
	n = 14;
	no_edges = 21;
	cnt = 14;
	strcpy_s(label, "mnopqrstuvwxyz");
	addEdge(adjList, 'm' - 'm', 'q'-'m');
	addEdge(adjList, 'm'-'m', 'r'-'m');
	addEdge(adjList, 'm'-'m', 'x'-'m');
	addEdge(adjList, 'n'-'m', 'o'-'m');
	addEdge(adjList, 'n'-'m', 'q'-'m');
	addEdge(adjList, 'n'-'m', 'u'-'m');
	addEdge(adjList, 'o'-'m', 'r'-'m');
	addEdge(adjList, 'o'-'m', 's'-'m');
	addEdge(adjList, 'o'-'m', 'v'-'m');
	addEdge(adjList, 'p'-'m', 'o'-'m');
	addEdge(adjList, 'p'-'m', 's'-'m');
	addEdge(adjList, 'p'-'m', 'z'-'m');
	addEdge(adjList, 'q'-'m', 't'-'m');
	addEdge(adjList, 'r'-'m', 'u'-'m');
	addEdge(adjList, 'r'-'m', 'y'-'m');
	addEdge(adjList, 's'-'m', 'r'-'m');
	addEdge(adjList, 'u'-'m', 't'-'m');
	addEdge(adjList, 'v'-'m', 'x'-'m');
	addEdge(adjList, 'v'-'m', 'w'-'m');
	addEdge(adjList, 'w'-'m', 'z'-'m');
	addEdge(adjList, 'y'-'m', 'v'-'m');
	return;
}
void createGraph(vector<int> adjList[])
{
	cout << "\nEnter the number of nodes \n";
	cin >> n;
	cout << "\nEnter the number of edges\n";
	cin >> no_edges;
	int a, b;
	for (int i = 0; i < no_edges; i++)
	{
		cout << "Enter the directed edge a->b \n";
		cin >> a >> b;
		addEdge(adjList, a, b);
	}
	cnt = n;
	return;
}
int main()
{
	// Adjacency list representation
	vector<int> adjList[50];
	for (int i = 0; i < 50; i++)
	{
		label[i] = '0' + i;
	}
	int choice = 0;
	// User needs to enter the choice to run the graph1 or graph2 or any user defined graph
	cout << "\nEnter the user Choice ( 1-> to test Graph 1, 2-> to test graph, 3-> For user defined graph 2)\n";
	cin >> choice;
	if (choice == 1)
		createGraph1(adjList);
	else
	if(choice == 2)
		createGraph2(adjList);
	else
	if (choice == 3)
	{
		createGraph(adjList);
	}
	PrintGraph(adjList, n);
	isCycle = false;
	//Part 1
	// BFS Topological Sort of the graph
	isCycle = bfsTopologicalSort(adjList, n);
	if (isCycle == true)
		cout << "\nCycle present in the graph\n";
	// Part 2
	// DFS Topological Sort of the Graph 
	cout << "\nDFS TOPOLOGICAL SORT OF THE GRAPH IS\n";
	bool visited[50];
	bool done[50];
	int nodeOrder[50];
	for (int i = 0; i <= n; i++)
	{
		visited[i] = false;
		done[i] = false;
		nodeOrder[i] = -1;
	}
	isCycle = false;
	for (int i = 0; i < n; i++)
	{
		if (isCycle ==  false && visited[i] == false)
		{
			dfsTopologicalSort(adjList, i, n, visited, done, nodeOrder);
		}
	}
	for (int i = 0; i <= n; i++)
	{
		if (nodeOrder[i] != -1)
		{
			cout << label[nodeOrder[i]] << " ";
		}
	}
	cout << endl;
	if (isCycle)
	{
		cout << "\nCycle is present in the graph\n";
	}
	return 0;
}