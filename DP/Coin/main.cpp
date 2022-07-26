/**
 * 问题：有三种硬币，分别是2，5，7元，每种硬币足够多
 * 买一本书需要27元
 * 如何用最少的硬币数组合好付清，并且不需要对方找钱
 */
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    //硬币面额
    int coin[3] = {2,5,7};

    //DP数组，dp[i]表示最少用dp[i]个硬币就可以组合成i元
    unsigned int dp[27+1];
    //确定初始条件
    dp[0] = 0;

    //计算顺序从1开始计算
    for(int i = 1; i < 27+1; i++)
    {
        dp[i] = INT32_MAX;
        for(int j = 0; j < 3; j++)
        {
            //确保dp数组计算过程中数组下标不越界
            if(i >= coin[j] && dp[i - coin[j]] != INT32_MA)
            {
                //转移方程
                dp[i] = min(dp[i - coin[j]]+1, dp[i]);
            }
        }
    }
    if(dp[27] == INT32_MAX)
    {
        cout<<"不存在最少硬币数组合成27的方法"<<endl;
    }
    else
    {
        cout<<"最少硬币数"<<dp[27]<<"可以组合成27元"<<endl;
    }
    return 0;
}