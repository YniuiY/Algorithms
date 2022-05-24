#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class Key, class Value>
class SymbolTable
{
private:
    int N;
    int Capebility;
    struct Node
    {
        Key     key_;
        Value   value_;
        Node(Key k, Value v):key_(k),value_(v){}
    };
    std::vector<Node>   datas;
    std::vector<Key>    Keys_;
    std::vector<Value>  Values_;

public:
    SymbolTable(int capebility):N(0),Capebility(capebility)
    {
        for(int i = 0; i < capebility; i++)
        {
            Keys_.push_back(" ");
            Values_.push_back(reinterpret_cast<Value>(0));
        }
        
    }
    ~SymbolTable(){}

    void    put(Key key, Value value);
    Value   get(Key key);
    void    deleta(Key key);
    bool    contains(Key key);
    bool    isEmpty();
    int     size();
    int     rank(Key key);
    void    show();
    std::vector<Key> keys();

};

template<class Key, class Value>
void SymbolTable<Key, Value>::put(Key key, Value value)
{
    cout<<"Put\n";
    if(value == NULL)
    {
        deleta(key);
        return;
    }
    int i = rank(key);
    if(Keys_[i] == key)
    {
        Values_[i] = value;
        return;
    }
    for(int j = N; j > i; j--)
    {
        Keys_[j] = Keys_[j-1];
        Values_[j] = Values_[j-1];
    }
    Keys_[i] = key;
    Values_[i] = value;
    N++;
}

template<class Key, class Value>
Value SymbolTable<Key, Value>::get(Key key)
{
    int i = rank(key);
    if(i < N && Keys_[i] == key)
    {
        return Values_[i];
    }
    else 
    {
        return NULL;
    }
}

template<class Key, class Value>
void SymbolTable<Key, Value>::deleta(Key key)
{
    int i = rank(key);
    if(i < N && Keys_[i] == key)
    {
        for(int j = i; j < N - 1; j++)
        {
            Keys_[j] = Keys_[j + 1];
            Values_[j] = Values_[j + 1];
        }
        N--;
    }
    return;
}

template<class Key, class Value>
bool SymbolTable<Key, Value>::contains(Key key)
{
    return get(key) != NULL;
}

template<class Key, class Value>
bool SymbolTable<Key, Value>::isEmpty()
{
    return size() == 0;
}

template<class Key, class Value>
int SymbolTable<Key, Value>::size()
{
    return N;
}

template<class Key, class Value>
vector<Key> SymbolTable<Key, Value>::keys()
{
    return Keys_;
}

/**
 *  使用二分查找的方法，找出Keys_中比key小的元素个数
 */
template<class Key, class Value>
int SymbolTable<Key, Value>::rank(Key key)
{
    cout<<"Rank\n";
    int low = 0, height = N - 1;
    while(low <= height)
    {
        int mid = low + (height - low) / 2;
        if(key < Keys_[mid]) { height = mid - 1; }
        else if(key > Keys_[mid]) { low = mid + 1; }
        else { return mid; }
    }
    cout<<"Low: "<<low<<endl;
    return low;
}

template<class Key, class Value>
void SymbolTable<Key, Value>::show()
{
    cout<<"Key: \t Value:"<<endl;
    for(int i = 0; i < N; i++)
    {
        cout<<Keys_[i]<<" \t "<<Values_[i]<<endl;
    }
}

#endif