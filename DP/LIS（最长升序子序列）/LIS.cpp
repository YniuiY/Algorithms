/*
*   LIS (最长升序子序列，严格升序)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // vector<int> s{12,2,69,55,7,33,81,100,6,78,109};//{12,2,69,55,33,81,100,8,78,109};//{12,2,69,55,7,33,81,100,6,78,109};//{2,6,7}
    // vector<int> s{10,9,2,5,3,7,101,18};
    vector<int> s{4,10,4,3,8,9};//{4,10,4,3,8,9};

    vector<int>dp(s.size(),1);//dp[i]表示：s[0]-s[i]间最大升序子序列的长度，dp[i]至少为1（在纯降序序列中）
    cout<<s.size()<<endl;
    /* 
    *   最后一步：确定最终的LIS长度。
    *   子问题：找到0-j(0 < j < s.size()-1)的序列中最大升序子序列的长度。
    *   所以dp[i]，表示以s[i]结尾的序列最大升序子序列的长度。（注意：是以s[i]结尾的LIS，不是0-i之间的LIS）
    *   状态转移方程：
    *               dp[i] = max{1， dp[j] + 1 (if(s[i] > s[j] && dp[i] <= dp[j])) }
    *               0 < j < i
    *               dp[i]至少为 1。
     */
    for(int i = 1; i < s.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(s[i] > s[j] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int res = 1;
    for(auto a : dp)
    {
        res = max(res, a);
    }

    cout<<"In this string: "<<endl;
    for(auto sub : s)
    {
        cout<<sub<<" ";
    }
    cout<<"LIS is: "<<res;

    cout<<endl<<"dp[]"<<endl;
    for(auto d: dp)
    {
        cout<<d<<" ";
    }

    return 0;
}