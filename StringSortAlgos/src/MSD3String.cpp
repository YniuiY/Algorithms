#include "MSD3String.h"

MSD3String::MSD3String(){}

MSD3String::~MSD3String(){}

int MSD3String::charAt(string s, int d)
{
    if(s.length() > d)
    {
        return s.at(d);
    }
    else
    {
        return -1;
    }
}

void MSD3String::sort(vector<string> &a)
{
    int N = a.size();
    sort(a, 0, N-1, 0);
}

void MSD3String::sort(vector<string> &a, int lo, int hi, int d)
{
    if(lo >= hi) return;

    int le = lo, rt = hi;
    int i = lo+1;
    char v = charAt(a[lo], d);

    /**
     * 三向分割
     * 以随机一个字符串的第d个字母为基础，三向分割，将字符串数组分成三部分
     * 第一部分，第d个字符小于这个字母的字符串们
     * 第二部分，第d个字符等于这个字母的字符串们
     * 第三部分，第d个字符大于这个字母的字符串们。
     * 然后再分别递归的分割这三部分，直至完成排序。
     */
    while (rt >= i)
    {
        char t = charAt(a[i], d); //如果a[i]的长度小于d,t就是-1，这个时候短的字符串都会放在数组的前面
        if(t < v)
        {
            swap(a, le++, i++);
        }
        else if(t > v)
        {
            swap(a, i, rt--);
        }
        else
        {
            i++;
        }
    }

    /**
     * 递归的分割三部分数组, 如果v == -1则所有的字符串都会放在rt+1和hi之间。
     */
    sort(a, lo, le-1, d); //小于字母的部分,因为a数组的内容已经更改，所以此时继续按照d位置拆分。
    if(v >= 0) sort(a, le, rt, d+1); //等于字母的部分
    sort(a, rt+1, hi, d);   //大于字母的部分
}