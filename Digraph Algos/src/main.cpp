//
// Created by YD on 2022/7/28.
//

#include "Digraph.h"
#include "SymbolDigraph.h"
#include "BFS.h"
#include "DirectedCycle.h"
using namespace std;

int main()
{
#if 1
    Digraph diaGraph(4);

    int v = 0, w = 0;
    cout<<"Input vertex\n";
    for(int i = 0; i < 4; i++)
    {
        cout<<"From:";
        cin>>v;
        cout<<"To:";
        cin>>w;
        diaGraph.addEdge(v, w);
        cout<<"\n";
    }
    DirectedCycle dc(diaGraph);
    cout<<"Graph has cycle: "<<dc.hasCycle()<<endl;
    if(dc.hasCycle())
    {
        for(auto v : dc.cycleNodes())
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }

//    Digraph dg = diaGraph.reverse();
#endif

#if 0
    SymbolDigraph SD(3);
    BFS bfs;
    bfs.bfs(SD,0);

#endif
    return 0;
}