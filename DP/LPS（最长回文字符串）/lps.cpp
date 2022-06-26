#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(),1));

    for(int i = 0, j; i < s.size(); i++)
    {
        j = i+1;
        if(j < s.size() && s.at(i) == s.at(j))
        {
            dp[i][j] = 2;
        }
    }
    cout<<"1"<<endl;

    for(int L = 3; L <= s.size(); L++)
    {
        for(int i = 0, j = i + L - 1; j < s.size(); i++, j++)
        {
            if(s.at(i) == s.at(j))
            {
                if(L == 3 || dp[i+1][j-1] == j - i -1)
                    dp[i][j] = dp[i+1][j-1] + 2;
            }
        }
    }
    cout<<"2"<<endl;

    int max = 0;
    int x,y;
    for(int i = 0; i < dp.size(); i++)
    {
        for(int j = 0; j < dp.size(); j++)
        {
            if(dp[i][j] > max)
            {
                max = dp[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout<<max<<" i:"<<x<<" j:"<<y<<endl;

    return s.substr(x, y-x+1);
}

int main()
{
    string s("babad");
    cout<<longestPalindrome(s)<<endl;

    return 0;
}