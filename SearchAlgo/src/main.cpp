#include "SymbolTable.h"
#include "BST.h"
#include "RBT.h"
#include "HashTable.h"
using namespace std;

int main()
{
    // SymbolTable<string, int> st(10);
    // BinarySearchTree<string, int> bst;
    // RedBlackTree<string, int> rbt;
    HashTable<string, int> ht(97);
    int N = 0;
    string k;
    int v;
    cout<<"Input Table Size: ";
    cin>>N;
    cout<<"\n";
    for(int i = 0; i < N; i++)
    {
        cout<<"\nKey: ";
        cin>>k;
        cout<<"Value: ";
        cin>>v;
        // bst.put(k, v);
        // rbt.put(k, v);
        ht.put(k, v);
    }

    string s = "yangdi";
    string s1 = "xingmeiling1";
    ht.put(s, 000);
    cout<<s<<"- value is:"<<ht.get(s)<<endl;
    cout<<s1<<"- value is:"<<ht.get(s1)<<endl;

    // cout<<"BST Size: "<<bst.size()<<endl<<endl;

    // cout<<"Key: ";
    // cin>>k;
    // cout<<"Is contains?: "<<bst.contains(k)<<endl<<endl;

    // cout<<"Get Table elements -Key:";
    // cin>>k;
    // cout<<"Value: "<<bst.get(k)<<endl<<endl;
    // if(bst.get(k) == NULL)
    // {
    //     cout<<"Key: "<<k<<" not exist in this Tree\n";
    // }

    // bst.show();
    // rbt.show();
    // cout<<"Min: "<< bst.min()<<endl;
    // bst.deletaMin();
    // cout<<"deleta Key:";
    // cin>>k;
    // bst.deleta(k);
    // bst.show();

    return 0;
}