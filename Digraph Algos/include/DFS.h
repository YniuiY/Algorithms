//
// Created by YD on 2022/7/29.
//

#ifndef DIGRAPHALGO_DFS_H
#define DIGRAPHALGO_DFS_H
#include "SymbolDigraph.h"
#include "Digraph.h"


class DFS
{
private:
    Digraph DG;
    SymbolDigraph SDG;
    bool* marked = nullptr;
    int* edgeTo = nullptr;
    static bool* marked1;
    int S = 0;
public:
    DFS() = default;
    DFS(Digraph dg, int s);
    DFS(SymbolDigraph sdg, int s);
    ~DFS();

    static void dfs(Digraph, int);
    void dfs(int);
    bool isMarked(int v);
    std::vector<int> pathTo(int destVertex);
};


#endif //DIGRAPHALGO_DFS_H
