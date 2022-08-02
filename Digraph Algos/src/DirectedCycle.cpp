//
// Created by YD on 2022/8/2.
//

#include "DirectedCycle.h"
#include <algorithm>

DirectedCycle::DirectedCycle(const Digraph &g):G(g)
{
    onStack = new bool [G.Vertex()];
    marked = new bool [G.Vertex()];
    edgeTo = new int [G.Vertex()];

    for(int v = 0; v < G.Vertex(); v++)
    {
        if(!marked[v])
            dfs(v);
    }
}

DirectedCycle::~DirectedCycle()
{
    delete[] onStack;
    delete[] marked;
    delete[] edgeTo;
}

void DirectedCycle::dfs(int v)
{
    marked[v] = true;
    onStack[v] = true;

    for(int w : G.adjs(v))
    {
        if(hasCycle())
            return;
        else if(!marked[w])
        {
            edgeTo[w] = v;
            dfs(w);
        }
        else if(marked[w])
        {
            // has cycle, cycle node push to stack like (1-2-3-1)
            for(int x = v; x != w; x = edgeTo[x])
                cycle.push_back(x);
            cycle.push_back(w);
            cycle.push_back(v);
        }
    }
}

bool DirectedCycle::hasCycle()
{
    return !cycle.empty();
}

vector<int> DirectedCycle::cycleNodes()
{
    reverse(cycle.begin(), cycle.end());
    return cycle;
}