#include "Graph.h"
#include <iostream>
using namespace std;

int main()
{
    Graph *graph = new Graph();
    graph->traverse(0);

    // delete graph;
    return 0;
}