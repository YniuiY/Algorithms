//
// Created by YD on 2022/7/28.
//

#ifndef DIGRAPHALGO_DIGRAPH_H
#define DIGRAPHALGO_DIGRAPH_H

#include <iostream>
#include <vector>
#include <list>


class Digraph{
private:
    int V = 0;
    int E = 0;
    std::vector<std::list<int>> adj;

public:
    Digraph() = default;
    Digraph(int v);
    ~Digraph()=default;
    int Vertex();
    int Edge();
    void addEdge(int v, int w);
    std::list<int> adjs(int v);
    Digraph reverse();
};


#endif //DIGRAPHALGO_DIGRAPH_H
