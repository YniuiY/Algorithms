#ifndef TST_H
#define TST_H
/**
 * 三向分割的字符串搜索树
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static const int R = 256;

class TST
{
private:
    struct Node
    {
        int     v;
        char    c;
        Node*   left = NULL;
        Node*   mid = NULL;
        Node*   right = NULL;
    };
    Node* root = NULL;

    Node* put(Node* root, string key, int value, int d);
    Node* get(Node* root, string key, int d);

public:
    TST();
    ~TST();
    void    put(string key, int value);
    int     get(string key);
};

#endif