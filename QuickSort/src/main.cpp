#include "QuickSort.h"
#include "Quick3WaySort.h"
#include <vector>

int main()
{
    // QuickSort *QSort = new QuickSort();
    // int array[7]{5,3,10,2,1,6,4};

    // QSort->sort(array, 0, sizeof(array)/sizeof(int) - 1);

    vector<int> array{5,3,10,2,1,6,4};
    Quick3WaySort q3Sort;
    q3Sort.sort(array);

    for(auto a: array)
    {
        cout<<a<<" ";
    }
    cout<<"\n";
    return 0;
}