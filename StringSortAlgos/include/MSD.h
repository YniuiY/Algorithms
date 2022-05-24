#ifndef MSD_H
#define MSD_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 高位优先字符串排序算法
 * 这个算法可以对不定长的字符串，按照从左向右的顺序排序。
 * 算法按照分治的思想，根据当前位置的字符，将所有字符串数组分成数份，再在这些子数组中递归的拆分排序。
 */

class MSD
{
private:
    /* data */
    int R = 256;
    int M = 10; //小数组使用高位优先字符串排序会明显降低排序速度，所以在数组长度小于10时调用插入排序。
    vector<string> aux;

    void    swap(vector<string> &a , int i, int j);
    int     charAt(string s, int d);
    void    insertSort(vector<string> &a, int lo, int hi, int d);

    /**
     * a：      待排序的字符串数组，
     * low:     参加本次排序的字符串数组的起始下标。
     * height： 参加本次排序的字符串数字的结束下标。
     * d:       本次排序的字符串中的第d个字符。从0开始（最左边是0）
     */
    void sort(vector<string> &a, int lo, int hi, int d);
public:
    MSD(/* args */);
    ~MSD();
    void sort(vector<string> &a);
};


#endif