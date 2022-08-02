//
// Created by YD on 2022/8/2.
//

#ifndef DIGRAPHALGO_TOPOLOGICAL_H
#define DIGRAPHALGO_TOPOLOGICAL_H
#include "DFS.h"
#include "DirectedCycle.h"

class Topological
{
private:
    Digraph G;
    stack<int> Order;
public:
    Topological() = default;
    Topological(Digraph g);
    ~Topological() = default;
    bool isDAG();
    stack<int> order();
};


#endif //DIGRAPHALGO_TOPOLOGICAL_H
