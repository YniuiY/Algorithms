#include "TST.h"

TST::TST(){}

TST::~TST(){}

void TST::put(string s, int v)
{
    root = put(root, s, v, 0);
}

TST::Node* TST::put(Node* x, string s, int v, int d)
{
    char c = s.at(d);
    if(x == NULL)
    {
        x = new Node();
        x->c = c;
    }
    if(c < x->c)
    {
        x->left = put(x->left, s, v, d+1);
    }
    else if(c > x->c)
    {
        x->right = put(x->right, s, v, d+1);
    }
    else if(d < s.length())
    {
        x->mid = put(x->mid, s, v, d+1);
    }
    else
    {
        x->v = v;
    }
    return x;
}

int TST::get(string key)
{
    Node* node = get(root, key, 0);
    return node->c;
}

TST::Node* TST::get(Node* x, string s, int d)
{
    if(x == NULL) return NULL;
    char c = s.at(d);
    
    if(c < x->c)
    {
        return get(x->left, s, d+1);
    }
    else if(c > x->c)
    {
        return get(x->right, s, d+1);
    }
    else if(d < s.length())
    {
        return get(x->mid, s, d+1);
    }
    else
    {
        return x;
    }
}