//
// Created by YD on 2022/7/29.
//

#ifndef DIGRAPHALGO_BFS_H
#define DIGRAPHALGO_BFS_H

#include "SymbolDigraph.h"
#include "Digraph.h"

class BFS
{
private:
    SymbolDigraph SD;
    Digraph DG;
    int s = 0;
    bool *marked = nullptr;
    int *edgeTo = nullptr;
public:
    BFS()=default;
    BFS(const SymbolDigraph&);
    BFS(const Digraph&);
    ~BFS();

    void bfs(Digraph, int);
    void bfs(SymbolDigraph, int);
    void bfs(int);
    bool isMarked(int index);
    std::vector<int> pathTo(int root);

};

#endif //DIGRAPHALGO_BFS_H
