//
// Created by YD on 2022/8/2.
//
/*
 * dfs递归调用的栈，表示的是“当前”正在遍历的有向图的路径。
 * 一旦存在 V->W 的 W 被访问过的情况，说明 W 这个节点在调用栈中（在 V 下面），也就找到了一个环。
 * 因为调用栈存在 W->V 的路径（ W 先被访问过，在调用栈中 V 的下面所以存在 W->V 的路径），而 V->W 可达就补齐了这个环。
 * */

#ifndef DIGRAPHALGO_DIRECTEDCYCLE_H
#define DIGRAPHALGO_DIRECTEDCYCLE_H
#include "Digraph.h"
#include <stack>
using namespace std;

class DirectedCycle
{
private:
    Digraph G;
    bool* onStack;
    int* edgeTo;
    bool* marked;
    vector<int> cycle;

    void dfs(int v);

public:
    DirectedCycle() = default;
    DirectedCycle(const Digraph& g);
    ~DirectedCycle();
    bool hasCycle();
    vector<int> cycleNodes();
};


#endif //DIGRAPHALGO_DIRECTEDCYCLE_H
