#ifndef LSD_H
#define LSD_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 字符串低位优先排序算法，从右向左依次按照每个字符排序，右边是低位。
 * 这个排序算法要求字符串长度相同。
 */
class LSD
{
private:
    int R = 256;
public:
    LSD();
    ~LSD();

    void sort(vector<string> &a, int w);
};

#endif