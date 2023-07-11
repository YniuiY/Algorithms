//
// Created by YD on 2022/8/2
// Update by YD on 2023/07/07
//

/**
 * dfs递归的调用栈，表示的是“当前”正在遍历的有向图的路径。
 * 用bool类型的onStack数组表示节点在栈中，节点在dfs调用栈中时，节点在onStack标记为true，出栈则标记为false。
 * 从dfs的for循环出来，表明此节点的所有邻接节点都被访问过了，所以这个节点应该从dfs调用栈出栈。
 * 
 * 如果一个节点被访问过，且再次被访问时存在与调用栈中，意味着遍历沿着环走了一遍并再次访问到这个节点，这个节点是环的一部分。
 * 如果不存在以上情况则无环。
 */

#include "DirectedCycle.h"
#include <string.h>
#include <algorithm>

DirectedCycle::DirectedCycle(const Digraph &g):G(g)
{
    onStack = new bool [G.Vertex()];
    marked = new bool [G.Vertex()];
    edgeTo = new int [G.Vertex()];

    memset(onStack, 0, sizeof(bool) * G.Vertex());
    memset(marked, 0, sizeof(bool) * G.Vertex());
    memset(edgeTo, 0, sizeof(int) * G.Vertex());

    for(int v = 0; v < G.Vertex(); v++)
    {
        if(!marked[v])
            dfs(v);
    }
}

DirectedCycle::~DirectedCycle()
{
    delete[] onStack;
    delete[] marked;
    delete[] edgeTo;
}

void DirectedCycle::dfs(int v)
{
    // 标记节点V被访问过
    marked[v] = true;
    // V节点加入DFS递归调用栈，标记为在栈中的状态
    onStack[v] = true;

    for(int w : G.adjs(v))
    {
        if(hasCycle())
            return;
        else if(!marked[w])
        {
            edgeTo[w] = v;
            dfs(w);
        }
        else if(onStack[w]) // 如果一个节点被访问过，且再次被访问时依然在栈中，则表示有环
        {
            /**
             * has cycle, cycle node push to stack like (1-2-3-1)
             * 在 V->W 时判断成环，从V点向前推（包含V点，不包含W点）所有前驱节点加队列，最后再将W点加入队列
             * 队列中的就是环中节点，最后再将V点加入队列使环成型
             */
            for(int x = v; x != w; x = edgeTo[x])
                cycle.push_back(x);
            cycle.push_back(w);
            cycle.push_back(v);
        }
    }
    // V节点被遍历完毕，离开DFS递归调用栈，则标记为出栈状态
    onStack[v] = false;
}

bool DirectedCycle::hasCycle()
{
    return !cycle.empty();
}

vector<int> DirectedCycle::cycleNodes()
{
    reverse(cycle.begin(), cycle.end());
    return cycle;
}