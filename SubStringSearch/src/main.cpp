#include <stdio.h>
#include "SubStringSearch.h"

int main()
{
    SubStringSearch sss;
    cout<<"Input string s:";
    string s;
    cin>>s;
    cout<<"\nInput string pattern:";
    string pattern;
    cin>>pattern;
    cout<<"\nmatch number:"<<sss.search(s, pattern)<<endl;

    return 0;
}