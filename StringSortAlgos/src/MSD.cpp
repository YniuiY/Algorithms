#include "MSD.h"

MSD::MSD(){}

MSD::~MSD(){}

int MSD::charAt(string s, int d)
{
    if(d < s.length())
    {
        return s.at(d);
    }
    else
    {
        return -1;
    }
}

void MSD::sort(vector<string> &a)
{
    int N = a.size();
    for(int i = 0; i < N; i++)
    {
        aux.push_back("0");
    }
    sort(a, 0, N-1, 0);
}

void MSD::sort(vector<string> &a, int lo, int hi, int d)
{

    vector<int> count(R+2, 0);
    if(hi < lo + M)
    {
        insertSort(a, lo, hi, d);    
        return;
    }

    /**
     * 统计频率
     */
    for(int i = lo; i <= hi; i++)
    {
        count[charAt(a[i], d) + 2]++;
    }

    /**
     * 频率转索引
     */
    for(int i = 0; i < R+1; i++)
    {
        count[i + 1] += count[i];
    }

    /**
     * 根据第d个字符的不同对字符串分类
     */
    for(int i = lo; i <= hi; i++)
    {
        aux[count[charAt(a[i], d) + 1]++] = a[i];
    }

    /**
     * 回写
     */
    for(int i = lo; i <= hi; i++)
        a[i] = aux[i-lo];

    /**
     * 递归的去切分字符串数组a
     */
    for(int i = 0; i < R; i++)
    {
        sort(a, lo+count[i], lo+count[i+1]-1, d+1);
    }

}

void MSD::insertSort(vector<string> &a, int lo, int hi, int d)
{
    for(int i = lo; i <= hi; i++)
    {
        for(int j = i; j > lo; j--)
        {
            if(a[i].at(d) < a[j].at(d))
            {
                swap(a, i, j);
            }
        }
    }
}

void MSD::swap(vector<string> &a, int i, int j)
{
    string tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}