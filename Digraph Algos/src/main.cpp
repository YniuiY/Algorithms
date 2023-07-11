//
// Created by YD on 2022/7/28.
//

#include "Digraph.h"
#include "Graph.h"
#include "SymbolDigraph.h"
#include "BFS.h"
#include "DirectedCycle.h"
using namespace std;

int main()
{
#if 1
    int vertex, edge;
    cout << "diagraph has vertex: ";
    cin >> vertex;
    cout <<"has edge: ";
    cin >> edge;
    Digraph diaGraph(vertex);

    int v = 0, w = 0;
    cout<<"Input edge\n";
    for(int i = 0; i < edge; i++)
    {
        cout<<"From:";
        cin>>v;
        cout<<"To:";
        cin>>w;
        diaGraph.addEdge(v, w);
        cout<<"\n";
    }
    cout << "diagraph constract over\n";
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

#if 0
    Graph G(4, 4);
    int v = 0;
    int w = 0;

    for (int i = 0; i < 4; i++)
    {
        cout << "From: ";
        cin >> v;
        cout << "\nTo: ";
        cin >> w;
        cout << endl;
        G.addEdge(v, w);
    }
    BFS bfs(G);
    bfs.bfs(G,0);

#endif 
    return 0;
}