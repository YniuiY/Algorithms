#ifndef SUB_STRING_SEARCH_H
#define SUB_STRING_SEARCH_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SubStringSearch
{
private:

public:
    SubStringSearch();
    ~SubStringSearch();
    /**
     * 子字符串匹配暴力算法
     */
    int search(string s, string pattern);
};

#endif