#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template<class Key, class Value>
class BinarySearchTree
{
private:
    struct Node
    {
        Key     k;
        Value   v;
        Node*   left;
        Node*   right;
        int     N;

        Node(Key key, Value value, int N_):k(key),v(value),N(N_),left(NULL),right(NULL) {}
        ~Node(){}
    };
    Node* root = NULL;
    Value ret;

    int   size(Node* root);
    void  DFS(Node* root);
    Node* put(Node* x, Key k, Value v)
    {
        if(x == NULL)
        {
            return new Node(k, v, 1);
        }

        /**
         *  小于当前节点的Key则继续深入左子树
         *  大于则转向右子树
         *  */
        if(k < x->k)
        {
            x->left = put(x->left, k, v);
        }
        else if(k > x->k)
        {
            x->right = put(x->right, k, v);
        }
        else
        {
            x->v = v;
        }
        x->N = size(x->left) + size(x->right) + 1;//更新这个节点下的节点数，+1是因为包含本节点
        return x;
    }

    void get(Node* x, Key k)
    {
        if(x == NULL)
        {
            // return NULL;
            ret = NULL;
            return;
        }

        if(k < x->k) { get( x->left, k ); }
        else if(k > x->k) { get( x->right, k ); }
        else 
        {
            // cout<<"Key:"<<x->k<<"\tValue:"<<x->v<<endl;
            // cout<<"ret: "<<ret<<endl;
            ret = x->v;
            // return ret;
        }
    }

    Node* min(Node* root)
    {
        if(root->left == NULL)
        {
            return root;
        }
        min(root->left);
    }

    Node* deletaMin(Node* root)
    {
        if(root->left != NULL)
        {
            root->left = deletaMin(root->left);
            root->N = size(root->left) + size(root->right) + 1;
            return root;
        }
        return root->right;
    }

    Node* deleta(Node* root, Key key)
    {
        if(root == NULL)
        {
            return NULL;
        }

        if(key < root->k) 
        {
            root->left = deleta(root->left, key); 
        }
        else if(key > root->k)
        {
            root->right = deleta(root->right, key);
        }
        else
        {
            /**
             * 如果找到的目标节点没有左子树，直接将右子树返回即可
             * 同理返回左子树
             */
            if(root->left == NULL)
            {
                return root->right;
            }
            if(root->right == NULL)
            {
                return root->left;
            }

            /**
             * 找到目标节点,如果目标节点有左右子树
             * 删除时需要找到右子树上最小的节点接替被删除节点的位置，
             * 这样才能保证树内节点的有序。 
             */
            Node* tmp = root;
            root = min(root->right);    //找出右子树上最小的节点，作为接替的节点
            root->right = deletaMin(tmp->right);    //删除目标节点右子树上最小的节点，并返回给接替节点的右子树
            root->left = tmp->left; //将被删除节点的左子树，接到接替节点的左子树
            root->N = size(root->left) + size(root->right) + 1;
            return root;
        }
    }
    

public:
    BinarySearchTree(){};
    ~BinarySearchTree(){};
    

    void    put(Key key, Value value);
    Value   get(Key key);
    void    deleta(Key key);
    bool    contains(Key key);
    bool    isEmpty();
    int     size();
    // int     rank(Key key);
    void    show();
    Key     min();
    Key     max();
    void    deletaMin();
    void    deletaMax();
};


template<class Key, class Value>
void BinarySearchTree<Key, Value>::put(Key k, Value v)
{
    root = put(root, k, v);
}

template<class Key, class Value>
Value BinarySearchTree<Key, Value>::get(Key k)
{ 
    get(root, k);
    // cout<<"Value: "<<ret<<"\tKey: "<<k<<endl;
    return ret;
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::deleta(Key k)
{
    deleta(root, k);
}

template<class Key, class Value>
Key BinarySearchTree<Key, Value>::min()
{
    BinarySearchTree::Node* tmp = min(root);
    return tmp->k;
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::deletaMin()
{
    deletaMin(root);
}

template<class Key, class Value>
bool BinarySearchTree<Key, Value>::contains(Key k)
{
    bool r = false;
    get(k);
    if(ret != NULL)
    {
        r = true;
    }
    return r;
}

template<class Key, class Value>
bool BinarySearchTree<Key, Value>::isEmpty()
{
    return size(root) == 0;
}

template<class Key, class Value>
int BinarySearchTree<Key, Value>::size()
{
    return size(root);
}

template<class Key, class Value>
int BinarySearchTree<Key, Value>::size(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else 
    {
        return root->N;
    }
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::show()
{
    cout<<"====== Show ======"<<endl;
    DFS(root);
    cout<<"=================="<<endl;
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::DFS(Node* root)
{
    // cout<<"DFS\n";
    if(root == NULL)
    {
        return;
    }
    DFS(root->left);
    cout<<"Key: "<<root->k<<"\t Value: "<<root->v<<endl;
    DFS(root->right);
}

#endif