#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

class Graph
{
private:
    /* data */
    /*
    *   Node和Edge共同构成了邻接表 
     */
    struct Edge;
    struct Node
    {
        /* data */
        std::string     name = NULL;    //节点名（可以是内容等）
        Edge*           next = NULL;    //这个节点的第一条边，可以时顺时针的第一条边
    };

    struct Edge
    {
        /* data */
        Node* node;         //这条边的另一个顶点
        int weight;         //边的权重
        Edge* nextEdge;     //另一条边的指针
    };

    
    /*
    *   用二维数组来表示邻接表（有向图），第一个Vector的下标表示弧的起点，第二个Vector的值表示终点。
    *   table[0] = {1，3} 表示 0->1，0->3 有边。 
    *   
    *   二维数组表示弧的权重，vector下标表示顶点，内部vector的元素值表示权重。
    *   weight[0][3].equal(12)表示 0 -> 3 这条边的权重是12。
     */
    struct AdjTableGraph
    {
        /* data */
        vector<vector<int>> table; 
        vector<vector<int>> weight; 
    };

    /*
    *   用二维数组表示临界矩阵（有向有权重的图），两个vector的下标都表示顶点，内容表示这条边的权重。  
    */
    struct AdjMatrixGraph
    {
        vector<vector<int>> matrix;
    };

    AdjTableGraph   adjTableGraph;
    AdjMatrixGraph  adjMatrixGraph;
    queue<int>      trace;
    int nodeNum = 0;
    vector<int> visited;
    
    void buildTable();
    void buildMatrix();
    void BFSTable(int start);
    void BFSMatrix(int start);
    void DFSMatrix(int start);


public:
    Graph(/* args */);
    ~Graph();

    void traverse(int startNode);
};


#endif