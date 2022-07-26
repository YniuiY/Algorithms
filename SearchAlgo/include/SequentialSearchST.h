#ifndef SEQUENTIAL_SEARCH_ST_H
#define SEQUENTIAL_SEARCH_ST_H

#include <iostream>

template<class Key, class Value>
class SequentialSearchST
{
private:
    struct Node
    {
        Key   k;
        Value v;
        Node* next;

        Node(Key k_, Value v_, Node* n):k(k_), v(v_), next(n) {}
    };
    Node* first = nullptr;

public:
    SequentialSearchST();
    ~SequentialSearchST();

    void put(Key, Value);
    Value get(Key);
};

template<class Key, class Value>
SequentialSearchST<Key, Value>::SequentialSearchST(/* args */)
{
}

template<class Key, class Value>
SequentialSearchST<Key, Value>::~SequentialSearchST()
{
}

template<class Key, class Value>
void SequentialSearchST<Key, Value>::put(Key k, Value v)
{
    for(Node* x = first; x != nullptr; x = x->next)
    {
        if(x->k == k)
        {
            x->v = v;
            return;
        }
    }

    first = new Node(k, v, first);
}

template<class Key, class Value>
Value SequentialSearchST<Key, Value>::get(Key k)
{
    for(Node* x = first; x != nullptr; x = x->next)
    {
        if(x->k == k)
        {
            return x->v;
        }
    }
    return nullptr;
}

#endif