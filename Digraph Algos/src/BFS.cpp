//
// Created by YD on 2022/7/29.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include "BFS.h"
#include "Digraph.h"
#include "SymbolDigraph.h"
using namespace std;

void BFS::init()
{
    marked = new bool[VertexNum];
    edgeTo = new int[VertexNum];
    memset(marked, 0, sizeof(bool) * VertexNum);
    memset(edgeTo, 0, sizeof(int) * VertexNum);
}

BFS::BFS(const Digraph& dg):DG(dg),s(0)
{
    VertexNum = DG.Vertex();
    init();
}

BFS::BFS(const Graph& g) :G(g), s(0)
{
    VertexNum = G.Vertex();
    init();
}

BFS::BFS(const SymbolDigraph& sd):SD(sd),s(0)
{
    VertexNum = SD.DG().Vertex();
    init();
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

void BFS::bfs(Graph G, int root)
{
    queue<int> q;
    q.push(root);
    marked[root] = true;
    cout << root << " ";

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto w : G.adjs(v))
        {
            if (!marked[w])
            {
                q.push(w);
                marked[w] = true;
                edgeTo[w] = v;
                cout << w << " ";
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