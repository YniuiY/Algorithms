//
// Created by YD on 2022/7/29.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "BFS.h"
#include "Digraph.h"
#include "SymbolDigraph.h"
using namespace std;

BFS::BFS(const Digraph& dg):DG(dg),s(0)
{
    marked = new bool[DG.Vertex()];
    edgeTo = new int[DG.Vertex()];
}

BFS::BFS(const SymbolDigraph& sd):SD(sd),s(0)
{
    marked = new bool[SD.DG().Vertex()];
    edgeTo = new int[SD.DG().Vertex()];
}

BFS::~BFS()
{
    delete[] marked;
    delete[] edgeTo;
}

void BFS::bfs(int root)
{
    Digraph DG = SD.DG();
    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto a : DG.adjs(v))
        {
            if(!marked[v])
            {
                q.push(a);
                marked[v] = true;
                cout<<SD.name(a)<<endl;
            }
        }

    }
}

void BFS::bfs(Digraph DG, int root)
{
    queue<int> q;
    q.push(root);
    marked[root] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto a : DG.adjs(v))
        {
            if(!marked[a])
            {
                q.push(a);
                marked[a] = true;
                edgeTo[a] = v;
            }
        }

    }
}

void BFS::bfs(SymbolDigraph SG, int root)
{
    Digraph DG = SG.DG();;
    queue<int> q;
    q.push(root);
    marked[root] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto a : DG.adjs(v))
        {
            if(!marked[a])
            {
                q.push(a);
                marked[a] = true;
                cout<<SG.name(v)<<":"<<v<<endl;
            }
        }

    }
}

bool BFS::isMarked(int index)
{
    return marked[index];
}

std::vector<int> BFS::pathTo(int v)
{
    vector<int> path;
    if(!isMarked(v))
        return path;
    for(int x = v; x != s; x = edgeTo[x])
    {
        path.push_back(x);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}