#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    std::cout<< log(16)/log(2)<<std::endl;
    vector<int> v{1,12,3,14,52,6,17};
    make_heap(v.begin(),v.end());
    // sort_heap(v.begin(), v.end());
    
    
    for(auto num : v)
    {
        cout<<num<<endl;
    }
    cout<<"pop heap"<<endl;
    pop_heap(v.begin(), v.end());
    
    v.pop_back();
    for(auto num : v)
    {
        cout<<num<<endl;
    }

    cout<<"push heap"<<endl;
    v.push_back(100);
    push_heap(v.begin(),v.end());
    for(auto num : v)
    {
        cout<<num<<endl;
    }

    cout<<"Sort heap"<<endl;
    sort_heap(v.begin(), v.end());
    for(auto num : v)
    {
        cout<<num<<endl;
    }
}