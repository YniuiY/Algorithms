/**
 * 给定M行N列的网格，有一个机器人从左上角（0，0）出发，
 * 每一步可以向下或者向右一步走
 * 
 * 问有多少种不同的方式走到右下角
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    const int M = 4;
    const int N = 8;

    //dp数组元素表示，最多有dp[i][j]中方法到达（i，j）
    unsigned int dp[M][N];

    //计算顺序从0开始
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == 0 || j == 0) 
            {
                //初始条件,第0行/0列都是1，因为只能走一条线，一直向下或者向右
                dp[i][j] = 1;
            }
            else
            {
                //转移方程
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            
        }
    }

    if(dp[M-1][N-1] == 0)
    {
        cout<<"不存在到达右下角的路径"<<endl;
    }
    else
    {
        cout<<"最多存在"<<dp[M-1][N-1]<<"种路径可以到达右下角"<<endl;
    }
    return 0;
}