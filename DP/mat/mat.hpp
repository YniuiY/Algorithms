/**
 * 给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
 * 两个相邻元素间的距离为 1 。
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col = mat[0].size();
        //dp[i][j]表示（i，j）到最近的0的距离
        vector<vector<int>> dp(row, vector<int>(col, INT32_MAX/2));
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0)
                    dp[i][j] = 0;
            }
        }

        /**
         * 要从四个角开始分别计算一遍
         * 因为要保证转移方程右边的数据计算先于左边
         */

        //从左上角开始 计算一遍
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i-1 >= 0){
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                }
                if(j-1 >= 0){
                    dp[i][j] = min(dp[i][j-1] + 1, dp[i][j]);
                }
            }
        }

        //从右上角开始 计算一遍，注意计算方向
        for(int i = 0; i < row; i++){
            for(int j = col-1; j >= 0; j--){
                if(i-1 >= 0){
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                }
                if(j + 1 < col){
                    dp[i][j] = min(dp[i][j+1] + 1, dp[i][j]);
                }
            }
        }

        //从左下角开始 计算一遍，注意计算方向
        for(int i = row-1; i >= 0; i--){
            for(int j = 0; j < col; j++){
                if(i + 1 < row){
                    dp[i][j] = min(dp[i+1][j] + 1, dp[i][j]);
                }
                if(j-1 >= 0){
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }

        //从右下角开始 计算一遍，注意计算方向
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                if(i+1 < row){
                    dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                }
                if(j + 1 < col){
                    dp[i][j] = min(dp[i][j+1] + 1, dp[i][j]);
                }
            }
        }

        return dp;
    }

};