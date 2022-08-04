//
// Created by YD on 2022/7/29.
//

#ifndef DIGRAPHALGO_BFS_H
#define DIGRAPHALGO_BFS_H

#include "SymbolDigraph.h"
#include "Digraph.h"
#include "Graph.h"

enum GraphType
{
    GRAPH,
    DIGRAPH,
    SYMBOLGRAPH,
    SYMBOLDIGRAPH
};

class BFS
{
private:
    SymbolDigraph SD;
    Digraph DG;
    Graph G;
    int s = 0;
    int VertexNum;
    bool *marked = nullptr;
    int *edgeTo = nullptr;
    void init();
public:
    BFS()=default;
    BFS(const SymbolDigraph&);
    BFS(const Digraph&);
    BFS(const Graph&);
    ~BFS();

    void bfs(Graph, int);
    void bfs(Digraph, int);
    void bfs(SymbolDigraph, int);
    void bfs(int);
    bool isMarked(int index);
    std::vector<int> pathTo(int root);

};

#endif //DIGRAPHALGO_BFS_H
