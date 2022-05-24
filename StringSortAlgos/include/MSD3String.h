#ifndef MSD3STRING_H
#define MSD3STRING_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MSD3String
{
private:
    void sort(vector<string> &a, int lo, int hi, int d);
    void swap(vector<string> &a, int i, int j);
    int  charAt(string s, int d);
public:
    MSD3String();
    ~MSD3String();
    void sort(vector<string> &a);
};


#endif