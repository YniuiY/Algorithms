#ifndef MYHEAP_H
#define MYHEAP_H
#include <vector>
#include <iostream>
#include <random>
#include <stack>

class MyHeap
{
private:
    /* data */
    int N_, M;
    std::vector<int> nums;
    std::stack<int> stk;
    void swim(int k);
    void sink(int k);
    void swap(int i, int j);
    
public:
    MyHeap(int N);
    MyHeap();
    ~MyHeap();
    void insert(int value);
    int delMax();
    int delMin();
    void sort();
    void show();
    bool isSorted();
};


#endif