/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？

 

示例 1：


输入：m = 3, n = 7
输出：28

 
 */

 #include <iostream>
 #include <vector>
 using namespace std;

 int main()
 {
    int m = 3;
    int n = 7;
    //dp[i][j]表示，到达(i,j)点存在dp[i][j]条路径
    //转移方程为: dp[i][j] = dp[i-1][j] + dp[i][j-1]
    vector<vector<int>>dp(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for(int j = 0; j < n; j++)
    {
        dp[0][j] = 1;
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout<<"最多有: "<<dp[m-1][n-1]<<" 条路径可以到达终点"<<endl;
 }