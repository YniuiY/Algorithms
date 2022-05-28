#ifndef SUB_STRING_SEARCH_H
#define SUB_STRING_SEARCH_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SubStringSearch
{
private:

public:
    SubStringSearch();
    ~SubStringSearch();
    /**
     * 子字符串匹配暴力算法
     */
    int search(string s, string pattern);
};

/**
 * Rabin-Karp指纹字符串查找算法
 * 1、将长度为M的pattern字符串计算散列函数生成随机值；
 * 2、将文本字符串中，每M个字符计算一次散列函数生成随机值，对比与pattern字符串的随机值是否相同。
 *    如果相同就比较这段字符与pattern字符串是否真正相同，但是真正的直接对比两个字符串会降低算法效率，
 *    甚至会降低到与暴力搜索算法相同的水平。
 * 3、将散列表范围扩到到足够大，就能降低不同的字符串算出相同随机数的可能。
 *    当散列规模Q取大于10^20的long long型值，使得不同字符串散列出相同随机值的概率小于10^-20。
 *    如果还不够小就除两次Q从而降低到10^-40。
 * 4、使用足够大的散列规模降低冲突概率，从而在两个随机值相等的情况下省略逐个字符比较。
 *    这是蒙特卡洛算法的一种应用，使用扩大散列规模确保正确性的算法叫拉斯维加斯算法。
 */
class RabinKarp
{
private:
    string pattern;
    int R = 256;            //字母表大小
    int M = 0;              //pattern字符串长度
    unsigned long long Q = 0;        //很大的一个随机素数
    unsigned long long patHash = 0;  //pattern字符串的散列结果
    // long long txtHash = 0;  //文本中每个长度为pattern.lenght()的子字符串散列结果
    unsigned long long RM = 1;             //R^(M-1)，计算i+1到i+M下标的子字符串散列值需要

    unsigned long long longRandomPrime();
    unsigned long long hash(string s, int m);
    bool check(string substring);
    bool judgePrime(int p);
public:
    RabinKarp(string pat);
    ~RabinKarp();
    int search(string s);
};

#endif