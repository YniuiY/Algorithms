/* 
最长公共子序列（longest common sequence）和最长公共子串（longest common substring）不是一回事儿。
什么是子序列呢？即一个给定的序列的子序列，就是将给定序列中零个或多个元素去掉之后得到的结果。
什么是子串呢？给定串中任意个连续的字符组成的子序列称为该串的子串。
给一个图再解释一下：如本目录下图片所示：


问题描述：
字符序列的子序列是指从给定字符序列中随意地（不一定连续）去掉若干个字符（可能一个也不去掉）后所形成的字符序列。
令给定的字符序列X=“x0，x1，…，xm-1”，序列Y=“y0，y1，…，yk-1”是X的子序列，
存在X的一个严格递增下标序列<i0，i1，…，ik-1>，使得对所有的j=0，1，…，k-1，有xij=yj。
例如，X=“ABCBDAB”，Y=“BCDB”是X的一个子序列。
找出最长的公共子序列的长度。
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 
    dp[i][j]：表示以字符串s1以下标i结尾，和字符串s2以下标j结尾的最长公共子序列的长度
    状态转移方程：
                dp[i][j] = dp[i-1][j-1] + 1                 if(s1[i] == s2[j])
                         = max(dp[i-1][j], dp[i][j-1])      if(s1[i] != s[j])
                         还要考虑i,j为0的情况，因为这个时候，i-1,j-1就无效了。
 */

int main()
{
    string s1("bcaddeaf");
    // string s2("cdefbg");
    string s2("adcbf");
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));

    for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
        {
            if(s1[i] == s2[j])
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else if(i == 0)
                {
                    dp[i][j] = dp[i][j-1] + 1;
                }
                else if(j == 0)
                {
                    dp[i][j] = dp[i-1][j] + 1;
                }
                else
                {
                    cout<<s1[i]<<" - "<<s2[j]<<endl;
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                
            }
            else
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 0;
                }
                else if(i == 0)
                {
                    dp[i][j] = max(dp[i][j],dp[i][j-1]);
                }
                else if(j == 0)
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j]);
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
                if(i == 2 && j == 0)
                {
                    cout<<"i-1,j: "<<dp[i-1][j]<<endl;
                    cout<<"i,j-1: "<<dp[i][j-1]<<endl;
                }
            }
        }
    }

    cout<<"s1: "<<s1<<endl;
    cout<<"s2: "<<s2<<endl;
    for(auto dd: dp)
    {
        for(auto d: dd)
        {
            cout<<d<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"s1-s2 LCS is: "<<dp[s1.size()-1][s2.size()-1];
    return 0;
}