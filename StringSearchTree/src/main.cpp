#include "StringSearchTree.h"
#include <stdio.h>

int main()
{
    StringSearchTree sst;
    // sst.nodeNext();
#if 1
    string key;
    int value;
    int size;
    cout<<"Input Tree size:";
    cin>>size;
    for(int i = 0; i < size; i++)
    {
        cout<<"\nInput Key:";
        cin>>key;
        cout<<"\nInput Value:";
        cin>>value;
        sst.put(key, value);
    }
    cout<<"sst build over!\n";

    cout<<"\n*******************************\n";
#if 0
    cout<<"sst size:"<<sst.size()<<endl;
    cout<<"Input get Key:";
    cin>>key;
    cout<<"\n Key:"<<key<<"\tValue: "<<sst.get(key)<<endl;
#endif

#if 0
    cout<<"\n prefix key:";
    cin>>key;
    vector<string> tmp = sst.keyWithPrefix(key);
    cout<<"\n key with prefix, Key:"<<key<<"\n Values: ";
    for(string a : tmp)
    {
        cout<<a<<"\t"<<endl;
    }
#endif

#if 0
    cout<<"\n prefix key:";
    cin>>key;
    vector<string> tmp = sst.keyThatMatch(key);
    cout<<"\n key with prefix, Key:"<<key<<"\n Values: ";
    for(string a : tmp)
    {
        cout<<a<<"\t"<<endl;
    }
#endif 

#if 1
    cout<<"\n prefix key:";
    cin>>key;
    string tmp = sst.longestPrefix(key);
    cout<<"\n longest prefix string is:"<<tmp<<endl;
#endif 

    cout<<"\n*******************************\n";
#endif
}