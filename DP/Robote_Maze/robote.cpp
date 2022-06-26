/* 
设想有个机器人坐在一个网格的左上角，网格 r 行 c 列。
机器人只能向下或向右移动，但不能走到一些被禁止的网格（有障碍物）。
设计一种算法，寻找机器人从左上角移动到右下角的路径。

网格中的障碍物和空位置分别用 1 和 0 来表示。
返回一条可行的路径，路径由经过的网格的行号和列号组成。左上角为 0 行 0 列。如果没有可行的路径，返回空数组。

图例见robote_maze.png

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/robot-in-a-grid-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> ret;
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        int dp[r][c];
        bool b1 = false;
        bool b2 = false;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[r-1][c-1] == 1){
            return ret;
        }

        dp[0][0] = 1;
        
        for(int i = 1; i < r; i++){
            if( b1 ){
                dp[i][0] = 0;
            }
            else if(obstacleGrid[i][0] == 1){
                dp[i][0] = 0;
                b1 = true;
            }
            else{
                dp[i][0] = 1;
            }
        }
        for(int j = 1; j < c; j++){
            if( b2 ){
                dp[0][j] = 0;
            }
            else if(obstacleGrid[0][j] == 1){
                dp[0][j] = 0;
                b2 = true;
            }
            else{
                dp[0][j] = 1;
            }
        }

        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                dp[i][j] = 0;
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        if(dp[r-1][c-1] != 1){
            return ret;
        }

        int i = r-1;
        int j = c-1;

        while(i >= 0 && j >= 0){
            ret.push_back(vector<int>{i,j});

            if(i > 0 && dp[i-1][j]){
                i--;
            }
            else {
                j--;
            }
        }

        reverse(ret.begin(), ret.end());


        return ret;
    }
};