#include "../include/Graph.h"
#include <iostream>
using namespace std;


Graph::Graph(/* args */)
{
    buildTable();
    buildMatrix();
}

Graph::~Graph()
{
}

void Graph::buildTable()
{
    cout<<"Graph::buildTable()"<<endl;
    adjTableGraph.table.push_back(vector<int>{1,3});
    adjTableGraph.table.push_back(vector<int>{2,4});
    adjTableGraph.table.push_back(vector<int>{4});
    adjTableGraph.table.push_back(vector<int>{1,4});
    adjTableGraph.table.push_back(vector<int>{});
}

void Graph::buildMatrix()
{
    cout<<"Graph::buildMatrix()"<<endl;

    adjMatrixGraph.matrix.push_back(vector<int>{0,17,0,7,0});
    adjMatrixGraph.matrix.push_back(vector<int>{0,0,71,0,75});
    adjMatrixGraph.matrix.push_back(vector<int>{0,0,0,0,67});
    adjMatrixGraph.matrix.push_back(vector<int>{0,78,0,0,97});
    adjMatrixGraph.matrix.push_back(vector<int>{0,0,0,0,0});
}

void Graph::BFSTable(int startNode)
{
    cout<<"#################################   BFS Table  #######################################"<<endl;
    int nodeNum = adjTableGraph.table.size();
    vector<int> visited(nodeNum, 0);

    if(adjTableGraph.table[startNode].size() > 0)
    {
        trace.push(startNode);
        visited[startNode] = 1;
    }
    else
    {
        cout<<"The starting node has no edges leading to other nodes"<<endl;
        return;
    }

    while(!trace.empty())
    {
        int currentNode = trace.front();
        trace.pop();
        cout<<"Current Visited Node is: "<<currentNode<<endl;

        if(adjTableGraph.table[currentNode].size() > 0)
        {
            // cout<<"(adjTableGraph.table[currentNode].size() > 0)"<<endl;
            for(int i = 0; i < adjTableGraph.table[currentNode].size(); i++)
            {
                //判断这个节点是否被遍历过，如果没有就加入队列，并标记被遍历过了
                if(visited[adjTableGraph.table[currentNode][i]] != 1)
                {
                    trace.push(adjTableGraph.table[currentNode][i]);
                    visited[adjTableGraph.table[currentNode][i]] = 1;
                }  
            }
        }
    }
    cout<<"#################################   BFS Table  #######################################"<<endl;

}

void Graph::BFSMatrix(int start)
{
    cout<<"#################################   BFS Matrix  #######################################"<<endl;
    int nodeNum = adjMatrixGraph.matrix.size();
    vector<int> bfsVisited(nodeNum, 0);
    queue<int> queue;
    int currentNode = 0;

    if(nodeNum <= 0)
    {
        cout<<"Error: Matrix is empty"<<endl;
        return;
    }
    else
    {
        cout<<"Matrix Node is: "<<nodeNum<<endl;
    }

    queue.push(start);
    bfsVisited[start] = 1;

    while (!queue.empty())
    {
        currentNode = queue.front();
        queue.pop();
        cout<<"BFS Matrix visited node is: "<<currentNode<<endl;

        for(int i = 0; i < nodeNum; i++)
        {
            if(bfsVisited[i] == 0 && adjMatrixGraph.matrix[currentNode][i] != 0)
            {
                queue.push(i);
                bfsVisited[i] = 1;
            }
            else
            {
                // cout<<"bfsVisited["<<i<<"] is: "<<bfsVisited[i]<<endl;
                // cout<<"Matrix Node:"<<currentNode<<"->"<<i<<" is: " <<adjMatrixGraph.matrix[currentNode][i]<<endl;
            }
        }
    }
    cout<<"#################################   BFS Matrix  #######################################"<<endl;

}

void Graph::DFSMatrix(int start)
{
    visited[start] = 1;
    cout<<"DFS Visited Node is: "<<start<<endl;
    for(int i = 0; i < nodeNum; i++)
    {
        //判断节点 i 是否被访问过。如果没被访问过，且存在 start->i 的路径（权重不为0）则继续从i递归遍历。
        if(visited[i] == 0 && adjMatrixGraph.matrix[start][i] != 0)
        {
            DFSMatrix(i);
        }
    }
}

void Graph::traverse(int startNode)
{
    BFSTable(startNode);

    cout<<endl<<"****************************  DFS  ****************************"<<endl;
    this->nodeNum = adjMatrixGraph.matrix.size();
    for(int i = 0; i < this->nodeNum; i++)
    {
        this->visited.push_back(0);
    }
    DFSMatrix(startNode);
    cout<<"****************************  DFS  ****************************"<<endl<<endl;

    BFSMatrix(startNode);
}