#ifndef STRING_SEARCH_TREE
#define STRING_SEARCH_TREE
/**
 * 字符串搜索树
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

static const int R = 256; //共计R种字符

class StringSearchTree
{
private: 
    struct Node
    {
        int value = 0;
        Node* next[R];
    };
    Node* root = NULL;

    Node*   put(Node* root, string k, int v, int d);
    Node*   get(Node* root, string k, int d);
    int     size(Node* root);
    Node*   del(Node* root, string s, int d);
    void    collect(Node* root, string key, vector<string> &v);
    void    collect(Node* root, string pre, string pat, vector<string> &v);
    int     search(Node* root, string s,int d, int lenght);

public:
    StringSearchTree();
    ~StringSearchTree();

    void    put(string key, int value);
    int     get(string key);
    int     size();
    void    del(string s);

    vector<string>  keyWithPrefix(string key); //返回树中所有以key为前缀的字符串
    vector<string>  keyThatMatch(string pat); //使用通配符的前缀匹配函数
    
    /**
     * s的前缀在树中匹配的最长的键
     * 比如树中有键：yang, s为yang-di,则yang是树中与s的前缀匹配的最长的键
     */
    string          longestPrefix(string s); 

};

#endif