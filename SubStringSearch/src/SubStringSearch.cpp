#include "SubStringSearch.h"

SubStringSearch::SubStringSearch(){}

SubStringSearch::~SubStringSearch(){}

int SubStringSearch::search(string s, string pattern)
{
    int matchNumber = 0;
    for(int i = s.length()-1; i >= pattern.length()-1; i--)
    {
        string sub = s.substr(i-pattern.length()+1, pattern.length());
        // cout<<sub<<endl;
        if(sub.compare(pattern) == 0)
        {
            matchNumber++;
        }
    }
    return matchNumber;
}