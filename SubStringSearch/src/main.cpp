#include <stdio.h>
#include "SubStringSearch.h"

int main()
{
    // SubStringSearch sss;
    cout<<"Input string s:";
    string s;
    cin>>s;
    cout<<"\nInput string pattern:";
    string pattern;
    cin>>pattern;
    RabinKarp rk(pattern);
    // cout<<"\nmatch number:"<<sss.search(s, pattern)<<endl;
    cout<<"\nmatch number:"<<rk.search(s)<<endl;

    return 0;
}