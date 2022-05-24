#include "StringSearchTree.h"

StringSearchTree::StringSearchTree(){}

StringSearchTree::~StringSearchTree(){}

void StringSearchTree::put(string k, int v)
{
    root = put(root, k, v, 0);
}

StringSearchTree::Node* StringSearchTree::put(Node* x, string k, int v, int d)
{
    if(x == NULL)
    {
        x = new Node();
    }
    if(d == k.size())
    {
        x->value = v;
        return x;
    }
    char c = k.at(d);
    x->next[c] =  put(x->next[c], k, v, d+1);
    return x;
}

int StringSearchTree::get(string k)
{
    Node* n = NULL;
    n = get(root, k, 0);
    if(n != NULL)
        return n->value;
    else
        return 0;
}

StringSearchTree::Node* StringSearchTree::get(Node* x, string k, int d)
{
    if(x == NULL)
    {
        // cout<<"x is NULL\n";
        return NULL;
    }
    if(d == k.size())
    {
        // cout<<"\nLast Value:"<<x->value<<endl;
        return x;
    }
    char c = k.at(d);
    // cout<<"\nc: "<<c<<"\td:"<<d<<endl;
    return get(x->next[c], k, d+1);
}

int StringSearchTree::size()
{
    return size(root);
}

int StringSearchTree::size(Node* x)
{
    if(x == NULL)
    {
        return 0;
    }
    int cnt = 0;
    if(x->value != 0)
    {
        cnt++;
    }
    for(int r = 0; r < R; r++)
    {
        cnt += size(x->next[r]);
    }
    return cnt;
}

void StringSearchTree::del(string s)
{
    root = del(root, s, 0);
}

StringSearchTree::Node* StringSearchTree::del(Node* x, string s, int d)
{
    if(x == NULL) return NULL;
    if(d == s.length())
    {
        x->value = 0;
    }
    else
    {
        char c = s.at(d);
        x->next[c] = del(x->next[c], s, d+1);
    }

    if(x->value != NULL) return x;

    for(int r = 0; r < R; r++)
    {
        if(x->next[r] != NULL)
            return x;
    }
    return NULL;
}

vector<string> StringSearchTree::keyWithPrefix(string pre)
{
    vector<string> v;
    collect(get(root, pre, 0), pre, v);
    cout<<"collect over\n";
    return v;
}

void StringSearchTree::collect(Node* x, string pre, vector<string> &v)
{
    // static int nullNum = 1;
    if(x == NULL)
    {
        // cout<<"x is null\n";
        // cout<<" x is null pre: "<<pre<<"\tnull number:"<<nullNum++<<endl;
        return;
    }
    // cout<<"pre:"<<pre<<endl;
    if(x->value != 0)
    {
        // cout<<"pre:"<<pre<<endl;
        v.push_back(pre);
    }
    for(int r = 0; r < R; r++)
    {
        collect(x->next[r], pre+(char)r, v);
    }
}

vector<string> StringSearchTree::keyThatMatch(string pat)
{
    vector<string> v;
    collect(root, "", pat, v);
    return v;
}

void StringSearchTree::collect(Node* x, string pre, string pat, vector<string> &v)
{
    int d = pre.length();
    if(x == NULL) return;
    if(d == pat.length() && x->value != 0) v.push_back(pre);
    if(d == pat.length()) return;

    char c = pat.at(d);
    for(int r = 0; r < R; r++)
    {
        if(c == '.' || c == (char)r)
            collect(x->next[r], pre + (char)r, pat, v);
    }
}

string StringSearchTree::longestPrefix(string s)
{
    int lenght = search(root, s, 0, 0);
    // cout<<"lenght:"<<lenght<<endl;
    return s.substr(0, lenght);
}

int StringSearchTree::search(Node* x, string s, int d, int lenght)
{
    if(x == NULL) return lenght;
    if(x->value != 0) lenght = d;
    if(d == s.length()) return lenght;

    char c = s.at(d);
    return search(x->next[c], s, d+1, lenght);
}