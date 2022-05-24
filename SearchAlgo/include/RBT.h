#ifndef RBT_H
#define RBT_H
/**
 * “红黑树” 是2-3平衡树的工程实现，红黑树中红链接拉平就是2-3平衡树。
 * 其中红色链接是3节点（2个键，3条链接）的实现，黑链接是普通2节点的实现。
 * 
 * 红黑树的性质：
 * 1、红链接全部是左链接。
 * 2、没有一个节点同时与两条红链接相连。（一个普通节点不可能同时属于两个3节点）
 * 3、红黑树中黑链接是完美平衡的，即任意空链接到根节点的路径上的黑链接数量相同（因为黑链接本就是2-3树中的链接，2-3树链接本就是平衡的）
 * 
 */

#include <iostream>
#include <string>
using namespace std;

enum Color
{
    Red,
    Black
};

template<class Key, class Value>
class RedBlackTree
{
private:
    struct Node
    {
        Key     key;
        Value   value;
        Node*   left;
        Node*   right;
        int     N;
        Color   color;

        Node(Key k, Value v, int n, Color c)
        :key(k), value(v), left(NULL), right(NULL), N(n), color(c)
        {}

        ~Node(){}
    };

    Node* root;
    Value ret;
    int     size(Node* root);
    Value   get(Node* root, Key k);
    void    DFS(Node* root);

    Node* rotateLeft(Node* h)
    {
        cout<<"rotateLeft\n";
        Node* x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = Red;
        x->N = h->N;
        h->N = size(h->left) + size(h->right) + 1;
        cout<<"rotateLeft return\n";
        return x;
    }

    Node* rotateRight(Node* h)
    {
        cout<<"rotateRight\n";
        Node* x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = Red;
        x->N = h->N;
        h->N = size(h->left) + size(h->right) + 1;
        cout<<"rotateRight return\n";
        return x;
    }
    
    void flipColors(Node* h)
    {
        cout<<"flipColor\n";
        h->color = Red;
        h->left->color = Black;
        h->right->color = Black;
        cout<<"flipColor over\n";
    }

    bool isRed(Node* h)
    {
        if(h == NULL) return false;
        // cout<<"is red: "<<(h->color == Red)<<endl;
        return h->color == Red;
    }

    Node* put(Node* h, Key k, Value v)
    {
        cout<<"put\n";
        if(h == NULL) return new Node(k, v, 1, Red);

        if(k < h->key) h->left = put(h->left, k, v);
        else if(k > h->key) h->right = put(h->right, k, v);
        else h->value = v;

        if(isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
        if(isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
        if(isRed(h->left) && isRed(h->right)) flipColors(h);

        h->N = 1 + size(h->left) + size(h->right);
        return h;
    }

public:
    RedBlackTree();
    ~RedBlackTree();

    void    put(Key k, Value v);
    Value   get(Key k);
    void    deleta(Key k);
    int     size();
    bool    isEmpty();
    bool    contains(Key k);
    void    show();
};

template<class Key, class Value>
RedBlackTree<Key, Value>::RedBlackTree():root(NULL){}

template<class Key, class Value>
RedBlackTree<Key, Value>::~RedBlackTree(){}

template<class Key, class Value>
void RedBlackTree<Key, Value>::put(Key k, Value v)
{
    root = put(root, k, v);
    root->color = Black;
}

template<class Key, class Value>
Value RedBlackTree<Key, Value>::get(Key k)
{
    return get(root, k);
}

template<class Key, class Value>
Value RedBlackTree<Key, Value>::get(Node* root, Key k)
{
    if(root == NULL) return NULL;
    if(k < root->key) get(root->left, k);
    else if(k > root->key) get(root->right, k);
    else
    {
        ret = root->value;
        return ret;
    }
}

template<class Key, class Value>
int RedBlackTree<Key, Value>::size()
{
    size(root);
}

template<class Key, class Value>
int RedBlackTree<Key, Value>::size(Node* root)
{
    if(root == NULL) return ret;

    return root->N;
}

template<class Key, class Value>
bool RedBlackTree<Key, Value>::isEmpty()
{
    return root == NULL;
}

template<class Key, class Value>
void RedBlackTree<Key, Value>::show()
{
    cout<<"\n=== Show ===\n";
    DFS(root);
    cout<<"===\t ===\n\n";
}

template<class Key, class Value>
void RedBlackTree<Key, Value>::DFS(Node* root)
{
    if(root == NULL) return;

    DFS(root->left);
    cout<<"\nKey:"<<root->key<<endl;
    cout<<"Value:"<<root->value<<endl;
    if(root->color == Red)
    {
        cout<<"Color:"<<"Red"<<endl<<endl;
    }
    else
    {
        cout<<"Color:"<<"Black"<<endl<<endl;
    }
    
    DFS(root->right);
}

#endif