#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

/**
 * 由于C++中所有类型，都需要自行设计实现对应的Hash计算函数，
 * 本类虽是泛型，但对应的Key类型转整形函数，只实现了string转换成数字的方法，所以Key只能是string类型。
 * 
 * 当Key需要是其他类型时，需要新增对应的转换函数，
 * 当Key对应的类型的数据，转换成数字后再通过hash函数将这个数字散列成（0-M-1）的数组下标
 */


template <typename T>
struct isString
{
	operator bool()
	{
		return false;
	}
};
 
template <>
struct isString<string>
{
	operator bool()
	{
		return true;
	}
};

template<class Key, class Value>
class HashTable
{
private:
    std::vector<std::list<std::pair<Key, Value>>* > st; //存放链表对象的数组
    int M; //必须是素数才能有效利用数组中 0~M-1 的所有空间
    int R; //Key类型转换成整数时的进制数
private:
    virtual int key2Num(Key k);
    int hash(int hashCode);

public:
    HashTable(int M_);
    ~HashTable();
    void put(Key k, Value v);
    Value get(Key k);
};

template<class Key, class Value>
HashTable<Key, Value>::HashTable(int M_): M(M_), R(10)
{
    if(!isString<Key>())
    {
        cout<<"This Class Key must be string\n";
        cout<<"Unless override string2Num()\n";
        return;
    }

    for(int i = 0; i < M; i++)
    {
        st.push_back(new std::list<std::pair<Key, Value>>);
    }
}

template<class Key, class Value>
HashTable<Key, Value>::~HashTable()
{

}

template<class Key, class Value>
int HashTable<Key, Value>::key2Num(Key s)
{
    int hashCode = 0;
    for(int i = 0; i < s.size(); i++)
    {
        hashCode = (hashCode * R + s.at(i)) % M;
    }
    return hashCode;
}

template<class Key, class Value>
int HashTable<Key, Value>::hash(int hashCode)
{
    return (hashCode & 0x7fffffff) % M;
}

template<class Key, class Value>
void HashTable<Key, Value>::put(Key k, Value v)
{
    int n = hash(key2Num(k));
    for(auto beg = st[n]->begin(), end = st[n]->end(); beg != end; beg++)
    {
        if(beg->first == k)
        {
            beg->second = v;
            return;
        }
    }
    st[n]->push_back(std::pair<Key, Value>{k,v});
}

template<class Key, class Value>
Value HashTable<Key, Value>::get(Key k)
{
    int n = hash(key2Num(k));
    for(auto beg = st[n]->begin(), end = st[n]->end(); beg != end; beg++)
    {
        if(beg->first == k)
        {
            return beg->second;
        }
    }

    // cout<<"\nhash table don't have "<<k<<endl;
    return INT32_MAX;
}

#endif