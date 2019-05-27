#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
public:
	Graph(int v);
	~Graph();
	void addEdge(int v, int w);
	bool topological_sort();
private:
	int v;
	list<int> *adj;
	priority_queue<int, vector<int>, greater<int>> q;
	int* indegree;
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
	indegree = new int[v];
	for (int i = 0; i < v; i++)
	{
		indegree[i] = 0;
	}
}

Graph::~Graph()
{
	delete[] adj;
	delete[] indegree;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	++indegree[w];
}

bool Graph::topological_sort()
{
	for (int i = 0; i < v; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
	int count = 0;
	while (!q.empty())
	{
		int v = q.top();
		q.pop();
		cout << v << " ";
		++count;
		for (auto iter = adj[v].begin(); iter != adj[v].end(); ++iter)
		{
			if (!(--indegree[*iter]))
				q.push(*iter);
		}
	}
	return count < v ? false : true;
}

int main()
{
	Graph g(10);
	// g.addEdge(2, 4);
	// g.addEdge(0, 3);
	// g.addEdge(1, 4);
	// g.addEdge(0, 1);
	// g.addEdge(2, 3);
	// g.addEdge(0, 3);
	// g.addEdge(1, 2);
	// g.addEdge(0, 4);
	// g.addEdge(2, 4);
	// g.addEdge(0, 1);
	// g.topological_sort();
	g.addEdge(6, 4);
	g.addEdge(3, 9);
	g.addEdge(5, 7);
	g.addEdge(4, 1);
	g.addEdge(9, 2);
	g.addEdge(7, 8);
	g.addEdge(1, 0);
	g.addEdge(2, 0);
	g.addEdge(8, 0);
	g.topological_sort();
	getchar();
	return 0;
}

