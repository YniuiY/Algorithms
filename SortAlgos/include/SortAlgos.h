#ifndef SORT_ALGOS_H
#define SORT_ALGOS_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;
class SortAlgos
{
public:
    SortAlgos(int N);
    SortAlgos(int N, int M);
    ~SortAlgos();

    void checkSort();    // 选择排序
    void insertSort(int left, int right); // 插入排序
    void quickSort(int startPos, int endPos);    //快速排序
    void quick3WaySort(int startPos, int endPos); //三向切分的快速排序
    void mergeSort(int left, int right);    // 归并排序
    void heapSort();

    bool isSorted();

private:
    void swap(int pos1, int pos2);
    void merge(int left, int mid, int right);
    void show();

private:
    std::vector<int> nums;
    std::vector<int> temp;
    int N_;
    int M_;
    static int cycelNum;
};

#endif