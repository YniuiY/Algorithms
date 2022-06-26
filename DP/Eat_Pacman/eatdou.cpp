/* 
一个简易吃豆人游戏，假设有一个m*n的棋盘（0<m, n<1000），棋盘格的坐标轴左上角是（0, 0），右下角是（m-1, n-1）。
除了(0, 0)外，每个棋盘格上都放有一些豆子，格子（i, j）上豆子的数量记为Sij。
吃豆人初始位置在(0, 0)，每次只能向右或向下行动一格，并吃掉该格上的豆子，现在需要求一条路线，使吃掉的豆子的总数最大（即∑Si,j，包含所有路线上的格子(i, j)）。
请写一个函数计算这条路线以及吃掉的豆子数量，要求计算速度尽可能快，并且给出算法的时间复杂度。如果有多条等价路线，任意给出一条即可。
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    const int M = 4;
    const int N = 4;
    const int s[M][N] = {{0,1,1,1},
                        {1,2,1,1},
                        {1,1,3,1},
                        {1,1,1,4}};


    //dp数组元素表示，到达i,j的时候吃到的豆子最多为dp[i][j]个
    unsigned int dp[M][N];
    dp[0][0] = 0;

    for(int i = 1; i < M; i++)
    {
        dp[i][0] = dp[i-1][0] + s[i][0];
    }
    for(int j = 1; j < N; j++)
    {
        dp[0][j] = dp[0][j-1] + s[0][j];
    }

    //计算顺序从0开始
    for(int i = 1; i < M; i++)
    {
        for(int j = 1; j < N; j++)
        {
            //转移方程
            // dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + s[i][j];
            if(dp[i-1][j] >= dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j] + s[i][j];
            }
            else
            {
                dp[i][j] = dp[i][j-1] + s[i][j];
            }
        }
    }
    
    vector<pair<int, int>> path;

    int i = M-1;
    int j = N-1;
    while(i >= 0 && j >= 0)
    {
        path.push_back(pair<int, int>{i,j});
        if(i > 0 && dp[i-1][j] >= dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(path.begin(), path.end());

    
    cout<<"最多吃掉"<<dp[M-1][N-1]<<"个豆子"<<endl;
    // Path;
    for(auto a: path)
    {
        cout<<a.first<<","<<a.second<<"\t";
    }

    
    return 0;
}