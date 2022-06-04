#ifndef QUEICK3WAYSORT_H
#define QUEICK3WAYSORT_H
#include <iostream>
#include <vector>
class Quick3WaySort
{
private:
    void quick3WaySort(std::vector<int>&, int lo, int hi);
    void swap(std::vector<int>&, int a, int b);
public:
    Quick3WaySort(){}
    ~Quick3WaySort(){}

    void sort(std::vector<int>&);
};

#endif