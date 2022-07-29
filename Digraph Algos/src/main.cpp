//
// Created by YD on 2022/7/28.
//

#include "Digraph.h"
#include "SymbolDigraph.h"
#include "BFS.h"
using namespace std;

int main()
{
#if 0
    Digraph diaGraph(3);

    int v = 0, w = 0;
    cout<<"Input vertex\n";
    for(int i = 0; i < 3; i++)
    {
        cout<<"From:";
        cin>>v;
        cout<<"To:";
        cin>>w;
        diaGraph.addEdge(v, w);
        cout<<"\n";
    }

    Digraph dg = diaGraph.reverse();
#endif

#if 1
    SymbolDigraph SD(3);
    BFS bfs;
    bfs.bfs(SD,0);

#endif
    return 0;
}