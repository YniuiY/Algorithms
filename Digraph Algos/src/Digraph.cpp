//
// Created by YD on 2022/7/28.
//

#include "Digraph.h"
using namespace std;

Digraph::Digraph(int v):V(v),E(0)
{
    for(int v = 0; v < V; v++)
    {
        adj.push_back(list<int>());
    }
}

void Digraph::addEdge(int v, int w)
{
    cout << "add edge from: " << v << "-> to: " << w << std::endl;
    adj[v].push_back(w);
    E++;
}

Digraph Digraph::reverse()
{
    Digraph R(V);
    for(int v = 0; v < V; v++)
    {
        for(auto w: adj[v])
        {
            R.addEdge(w, v);
        }
    }
    return R;
}

int Digraph::Edge()
{
    return E;
}

int Digraph::Vertex()
{
    return V;
}

std::list<int> Digraph::adjs(int v)
{
    return adj[v];
}

