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

//bool* DFS::marked1 = nullptr;

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

void DFS::dfs(Digraph DG, int v)
{
    pre.push(v);
    marked[v] = true;

    for(auto w: DG.adjs(v))
    {
        if(!marked[w])
        {
            dfs(DG, w);
        }
    }
    post.push(v);
    reversePost.push(v);
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

std::queue<int> DFS::preNode()
{
    return pre;
}

queue<int> DFS::postNode()
{
    return post;
}

stack<int> DFS::reversePostNode()
{
    return reversePost;
}