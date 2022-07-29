//
// Created by YD on 2022/7/29.
//

#include "SymbolDigraph.h"
using namespace std;

SymbolDigraph::SymbolDigraph(int v):V(v)
{
    cout<<"Input vertex and edge\n";
    string vertex;
    for(int i = 0; i < V; i++)
    {
        cout<<"Vertex:";
        cin>>vertex;
        Maps.insert({vertex, Maps.size()});
        cout<<endl;
        Keys.emplace_back("");
    }
    cout<<endl;
    for(const auto& a : Maps)
    {
        Keys[a.second] = a.first;
    }

    G = Digraph(v);
    string from, to;
    for(int i = 0; i < V; i++)
    {
        cout<<"From:";
        cin>>from;
        cout<<"\nTo:";
        cin>>to;
        G.addEdge(Maps.find(from)->second, Maps.find(to)->second);
    }
}

Digraph SymbolDigraph::DG()
{
    return G;
}

int SymbolDigraph::index(std::string s)
{
    return Maps.find(s)->second;
}

std::string SymbolDigraph::name(int index)
{
    return Keys[index];
}

bool SymbolDigraph::contains(std::string s)
{
    return Maps.find(s) != Maps.end();
}