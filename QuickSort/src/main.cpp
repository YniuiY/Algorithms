#include "QuickSort.h"
#include <vector>

int main()
{
    QuickSort *QSort = new QuickSort();
    int array[7]{5,3,10,2,1,6,4};

    QSort->sort(array, 0, sizeof(array)/sizeof(int) - 1);

    for(auto a: array)
    {
        cout<<a<<" ";
    }
    return 0;
}