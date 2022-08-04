#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
public:
	Graph() = default;
	Graph(int v, int e);
	~Graph() = default;
	int Vertex();
	int Edges();
	void addEdge(int v, int w);
	list<int> adjs(int v);
	Graph reverse();

private:
	int V;
	int E;
	int edgesNum;
	vector<list<int>> adj; //аз╫с╠М

};

#endif // !GRAPH_H
