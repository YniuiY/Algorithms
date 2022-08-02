//
// Created by YD on 2022/7/29.
//

#ifndef DIGRAPHALGO_DFS_H
#define DIGRAPHALGO_DFS_H
#include "SymbolDigraph.h"
#include "Digraph.h"
#include <queue>
#include <stack>
using namespace std;

class DFS
{
private:
    Digraph DG;
    SymbolDigraph SDG;
    queue<int> pre;
    queue<int> post;
    stack<int> reversePost;
    bool* marked = nullptr;
    int* edgeTo = nullptr;
    int S = 0;
public:
    DFS() = default;
    DFS(Digraph dg, int s);
    DFS(SymbolDigraph sdg, int s);
    ~DFS();

    void dfs(Digraph, int);
    void dfs(int);
    bool isMarked(int v);
    std::vector<int> pathTo(int destVertex);
    std::queue<int> preNode();
    queue<int> postNode();
    stack<int> reversePostNode();
};


#endif //DIGRAPHALGO_DFS_H
