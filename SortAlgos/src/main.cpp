#include "SortAlgos.h"
#include "MyHeap.h"
#include <chrono>
using namespace std;

static const int N = 5;
static const int M = 5;
static int heapSize = 0;
int SortAlgos::cycelNum = 1;

int main()
{
    MyHeap heap;
    default_random_engine engine;
    cout<<"Input Heap Size: ";
    cin>>heapSize;
    while (heapSize-- > 0)
    {
        /* code */
        // int value;
        // cin>>value;
        heap.insert(engine());
        // heapSize--;
    }
    cout<<"heap construct over\n\n"<<"Heap Sortting\n";
    // heap.show();
  
    // SortAlgos sortAlgos(N, M);
    auto start = chrono::steady_clock::now();
    // sortAlgos.checkSort();
    // sortAlgos.insertSort(0, N-1);
    // sortAlgos.quickSort(0, N-1);
    // sortAlgos.mergeSort(0, N-1);
    heap.sort();
    auto end = chrono::steady_clock::now();
    // if(!sortAlgos.isSorted())
    // {
    //     cout<<"\n\nSort Filed\n";
    // }
    // else
    // {
    //     cout<<"Sort Success\n";
    // }

    chrono::duration<double> castTime = end - start;
    cout<<"Sort Cost time: "<< castTime.count()<<"s\n";
    return 0;
}