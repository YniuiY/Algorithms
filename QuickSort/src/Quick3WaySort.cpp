#include "Quick3WaySort.h"
using namespace std;

void Quick3WaySort::sort(std::vector<int>& n)
{
    cout<<"sort"<<endl;
    quick3WaySort(n, 0, n.size()-1);
}

void Quick3WaySort::quick3WaySort(std::vector<int>& n, int lo, int hi)
{
    if(lo >= hi) return;
    int le = lo;
    int ri = hi;
    int i = lo+1;
    int v = n[lo];

    while(i <= ri)
    {
        if(n[i] < v) 
        {
            swap(n, i++, le++);
        }
        else if(n[i] > v)
        {
            swap(n, i, ri--);
        }
        else
        {
            i++;
        }
    }

    quick3WaySort(n, lo, le-1);
    quick3WaySort(n, ri+1, hi);
}

void Quick3WaySort::swap(std::vector<int>& n, int a, int b)
{
    // cout<<"beg: n[a]:"<<n[a]<<" n[b]:"<<n[b]<<endl;
    int tmp = n[a];
    n[a] = n[b];
    n[b] = tmp;
    // cout<<"end: n[a]:"<<n[a]<<" n[b]:"<<n[b]<<endl;
}