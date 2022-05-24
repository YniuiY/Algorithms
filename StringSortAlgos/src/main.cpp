#include "LSD.h"
#include "MSD.h"

int main()
{
    // LSD lsd;
    MSD msd;
    vector<string> a;
    string tmp;
    int n;
    cout<<"input string number: ";
    cin>>n;cout<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>tmp;
        a.push_back(tmp);
    }

    // lsd.sort(a, 4);
    msd.sort(a);

    cout<<"********************\n";
    for(auto c : a)
    {
        cout<<c<<endl;
    }
    cout<<"********************\n";
}