//
// Created by YD on 2022/7/29.
//

#ifndef DIGRAPHALGO_SYMBOLDIGRAPH_H
#define DIGRAPHALGO_SYMBOLDIGRAPH_H

#include "Digraph.h"
#include <map>
#include <string>

class SymbolDigraph
{
private:
    int V;
    Digraph G;
    std::map<std::string, int> Maps; //符号 -> 索引
    std::vector<std::string> Keys; // 索引 -> 符号

public:
    SymbolDigraph() = default;
    SymbolDigraph(int v);
    ~SymbolDigraph() = default;

    bool contains(std::string s);
    int index(std::string s);
    std::string name(int index);
    Digraph DG();
};


#endif //DIGRAPHALGO_SYMBOLDIGRAPH_H
