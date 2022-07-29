//
// Created by YD on 2022/7/29.
//

#include "DFS.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Digraph.h"
#include "SymbolDigraph.h"
using namespace std;

bool* DFS::marked1 = nullptr;

DFS::DFS(Digraph dg, int s):DG(dg) ,S(s)
{
    marked = new bool [DG.Vertex()];
    edgeTo = new int [DG.Vertex()];
}

DFS::DFS(SymbolDigraph sdg, int s):SDG(sdg) ,S(s)
{
    marked = new bool [SDG.DG().Vertex()];
    edgeTo = new int [SDG.DG().Vertex()];
}

DFS::~DFS()
{
    delete[] marked;
    delete[] edgeTo;
}

void DFS::dfs(Digraph DG, int s)
{
    marked1 = new bool [DG.Vertex()];
    marked1[s] = true;

    for(auto v: DG.adjs(s))
    {
        if(!marked1[v])
        {
            dfs(DG, v);
        }
    }
}

void DFS::dfs(int s)
{
    marked[s] = true;
    cout<<s<<endl;

    for(auto v : DG.adjs(s))
    {
        if(!isMarked(v))
        {
            edgeTo[v] = s;
            dfs(v);
        }
    }
}

bool DFS::isMarked(int vertex)
{
    return marked[vertex];
}

std::vector<int> DFS::pathTo(int destVertex)
{
    vector<int> path;
    if(!isMarked(destVertex))
        return path;
    for(int x = destVertex; x != S; x = edgeTo[x])
    {
        path.push_back(x);
    }
    path.push_back(S);
    reverse(path.begin(), path.end());
    return path;
}