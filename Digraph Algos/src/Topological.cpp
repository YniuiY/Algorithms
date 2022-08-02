//
// Created by YD on 2022/8/2.
//

#include "Topological.h"

Topological::Topological(Digraph g):G(g)
{
    DirectedCycle dc(G);
    DFS DFS;
    if(!dc.hasCycle())
    {
        for(int v = 0; v < G.Vertex(); v++)
            DFS.dfs(G, v);
        Order = DFS.reversePostNode();
    }
}

stack<int> Topological::order()
{
    return Order;
}

bool Topological::isDAG()
{
    return Order.empty();
}
