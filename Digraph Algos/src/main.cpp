//
// Created by YD on 2022/7/28.
//

#include "Digraph.h"
using namespace std;

int main()
{
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

    return 0;
}