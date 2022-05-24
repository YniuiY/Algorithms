/*
    LPS（最长回文字符串） 

给你一个字符串 s，找到 s 中最长的回文子串。
示例 1：
    输入：s = "babad"
    输出："bab"
    解释："aba" 同样是符合题意的答案。
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    cout<<"This Programe is LPS(Longest Palindrome String)"<<endl;
    // vector<char> s{'d','a','b','c','b','a','e'};
    // vector<char> s{'a','a','b','c','b','a','e'};
    vector<char> s{'b','b','b'};

    int sLength = s.size();
    vector<vector<int>>dp(sLength,vector<int>(sLength,1));

    /* 
    *   最后一步：判断s[i]是否等于s[j], i<j;
    *   子问题：判断s[i+1] 是否等于 s[j-1]
    *   所以dp[i][j],表示以s[i]，s[j]为起始点的回文字符长度。
    *   状态转移方程：
    *               dp[i][j] = max(1, dp[i+1][j-1]+2 (if(s[i] == s[j] && i < j && dp[i+1][j-1] > 1))  )
    *               需要单独判断相邻的两个字符是否相同。
    *               dp[i][i+1] = 2 ,if(s[i] == s[i+1])
     */


    /* 先找出相邻的回文串 */
    for(int i = 0; i < s.size(); i++)
    {
        if((i+1) < (s.size()))
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 2;
            }
        }
    }

    /* L从3开始扩大，保证计算方程左边dp[i][j]的时候，方程右边的dp[i+1][j-1]是计算过的 */
    for(int L = 3; L <= sLength; L++)
    {
        /* i表示比较起始点的下标 */
        for(int i = 0,j = 0; i < sLength - L + 1; i++)
        {
            j = i + L - 1;
            cout<<"s["<<i<<"]: "<< s[i];
            cout<<" - s["<<j<<"]: "<<s[j]<<endl;
            if(s[i] == s[j])
            {
                cout<<"i: "<<i<<" - j: "<<j<<endl;
                if(i+1 == j-1) //aba的情况
                {
                    dp[i][j] = 3;
                    // cout<<"***"<<dp[i][j]<<endl;
                    continue;
                }
                if(dp[i+1][j-1] > 1) // c a b a c 的情况
                {
                    // cout<<"dp[i+1][j-1]>1  i: "<<i<<" - j: "<<j<<endl;
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
            }
        }
    }

    cout<<"dp[]"<<endl;
    int res = 1;
    int beg = 0, size = 0;
    for(int i = 0; i < sLength; i++)
    {
        for(int j = 0; j < sLength; j++)
        {
            res = max(res, dp[i][j]);
            if(dp[i][j] == res)
            {
                beg = i;
                size = j-i + 1;
            }
            cout<<dp[i][j]<<" ";
        }
    }
    cout<<endl;

    for(auto ss : s)
    {
        cout<<ss<<" ";
    }

    cout<<endl<<"LPS is: "<<res<<endl<<"String is: "<<endl;
    for(int i = beg; i < beg + size; i++)
    {
        cout<<s[i];
    }
    return 0;
}