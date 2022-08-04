#include "Graph.h"

Graph::Graph(int v, int e) :V(v), E(e), edgesNum(0)
{
    for (int i = 0; i < E; i++)
    {
        adj.push_back(list<int>());
    }
}

void Graph::addEdge(int v, int w)
{
    // 无向图需要加两条边
    adj[v].push_back(w);
    adj[w].push_back(v);
    edgesNum++;
    cout << "Graph total need " << E << " edges. Now have: " << edgesNum << endl;
}

list<int> Graph::adjs(int v)
{
    return adj[v];
}

Graph Graph::reverse()
{
    Graph R(V, E);
    for (int v = 0; v < V; v++)
    {
        for (auto w : adj[v])
        {
            R.addEdge(w, v);
        }
    }

    return R;
}

int Graph::Vertex()
{
    return V;
}

int Graph::Edges()
{
    return E;
}