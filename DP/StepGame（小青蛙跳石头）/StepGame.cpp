/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。（小青蛙跳石头问题）

示例 1：

输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
示例 2：

输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 */

#include <iostream>
#include <vector>
using namespace std;

/* 
    dp[i]：表示能否到达下标i处。
    状态转移方程：
    (0<= j < i)
    dp[i] = 1   if(dp[j] > 0 && i - j <= nums[j])下标j处可以到达，并且下标j处的数字大于j到i之间的距离。
            0   
 */

int main()
{
    // vector<int> nums{2,3,1,1,4};
    // vector<int> nums{3,2,1,0,4};
    // vector<int> nums{1};
    // vector<int> nums{1,0,1,0};
    // vector<int> nums{1,2,3};
    // vector<int> nums{3,0,8,2,0,0,1};
    vector<int> nums{5,1,4,5,2,2,4,4,6,8,8,6,3,5,8,4,6,5,3,4,7,2,4,2,6,7,2,8,3,7,5,6,3,6,6,1,5,2,5,7,8,5,7,7,8,6,1,3,3,5,8,3,2,6,1,5,6,2,8,4,3,4,7,5,5,5,1,8,5,1,6,2,1,2,4,2,3,4,4,7,6,5,6,6,3,3,7,2,5,3,3,4,8,5,7,3,3,7,1,6,3,1,1,8,4,7,5,6,4,1,5,5,5,8,3,1,5,2,2,1,1,7,2,2,5,1,8,2,1,2,1,4,6,7,7,1,2,7,4,3,8,7,2,1,3,7,6,2,4,2,6,6,7,1,1,6,5,1,2,2,4,5,3,6,1,4,7,6,2,6,8,2,8,4,6,5,1,8,2,7,2,5,8,2,5,4,1,8,8,8,7,3,2,6,1,2,7,5,6,4,7,6,2,8,5,1,1,7,6,6,2,1,5,8,2,3,3,2,2,3,6,8,4,5,3,8,6,6,6,8,6,6,6,1,6,1,8,3,1,4,2,6,1,5,5,3,2,3,2,2,4,2,5,8,4,3,4,7,4,2,3,6,7,7,3,3,8,1,4,5,7,6,3,5,4,2,1,6,3,2,1,3,3,7,4,2,7,7,8,6,3,1,3,5,7,2,7,6,8,3,7,1,3,1,8,8,8,1,6,5,3,3,6,2,3,5,8,6,3,5,4,3,6,3,2,6,3,7,3,4,2,5,7,4,8,3,1,5,7,2,3,5,3,4,7,5,4,4,6,1,8,6,6,4,4,7,8,3,6,8,2,5,8,8,1,2,4,5,3,6,6,2,3,2,7,4,5,3,6,2,7,6,3,1,2,3,7,4,1,4,1,5,4,2,2,1,7,3,1,1,3,8,7,7,4,4,2,5,6,5,8,5,7,1,1,3,5,4,4,3,4,1,4,2,1,1,4,8,2,8,3,1,6,5,8,3,3,2,3,6,1,5,4,4,3,5,5,2,1,7,2,5,4,1,2,1,3,8,8,2,1,2,8,2,3,8,2,7,1,4,7,3,4,8,4,8,4,2,7,3,8,8,1,8,5,7,2,7,8,3,6,6,1,1,8,7,3,4,7,1,5,4,5,5,2,3,6,1,8,6,6,3,1,7,2,4,4,4,7,4,7,1,4,1,1,5,2,2,3,2,4,6,2,1,2,8,6,3,1,1,8,3,5,1,3,1,3,8,4,1,6,1,6,4,5,3,2,2,4,4,7,2,1,2,4,6,8,8,3,1,6,2,5,1,7,5,8,1,5,1,3,5,4,8,6,2,1,3,1,2,6,5,5,1,1,6,7,1,5,5,7,3,2,8,8,1,8,2,8,8,5,5,1,4,8,4,7,7,4,8,7,2,8,3,7,5,4,1,2,7,3,6,8,7,4,5,5,8,2,6,3,3,8,7,7,8,3,4,1,3,1,8,1,4,1,2,1,4,4,7,1,4,7,8,3,1,8,6,2,8,8,1,8,6,7,4,7,3,2,6,3,2,3,1,6,3,1,4,1,1,4,2,8,8,2,6,4,4,3,2,2,5,6,5,4,4,2,3,6,1,2,5,5,8,5,1,7,7,3,3,4,6,6,1,8,8,2,7,2,8,2,2,6,7,7,8,6,2,5,2,4,1,7,5,6,3,1,5,7,4,2,5,8,5,1,7,1,2,4,7,2,8,8,1,6,4,6,7,3,1,1,1,1,8,6,5,1,1,5,5,2,4,6,2,1,4,5,5,2,8,6,6,4,8,7,5,1,5,5,6,5,1,8,1,3,7,7,4,8,5,7,1,6,2,4,8,7,3,8,3,8,7,8,3,2,5,5,7,3,5,6,1,8,2,6,5,1,2,2,8,7,4,7,4,6,5,4,5,4,2,2,7,1,8,5,6,6,1,3,1,4,4,7,1,5,6,4,2,4,1,6,1,2,7,5,1,2,4,6,5,3,5,8,5,2,5,2,6,8,3,1,6,8,2,2,5,2,7,6,7,2,4,8,6,4,3,6,6,6,7,2,4,2,4,5,8,7,6,8,6,7,2,2,1,4,6,4,1,7,2,4,2,7,6,8,5,3,5,5,1,5,1,2,5,7,5,5,4,3,6,4,3,6,4,4,2,4,3,7,8,6,4,3,5,4,7,7,5,3,8,3,1,7,1,8,1,8,4,4,2,1,8,4,8,8,2,6,8,8,6,3,7,8,8,5,5,4,3,2,3,2,3,5,3,3,4,4,7,8,4,8,4,1,2,2,3,5,6,6,1,7,5,4,7,5,7,6,6,2,6,2,5,8,1,2,6,1,4,2,5,3,3,2,5,2,7,6,4,7,2,3,8,7,7,4,5,8,5,1,7,5,7,4,7,4,7,8,4,4,6,5,2,6,4,2,6,8,1,8,7,7,8,1,1,8,6,8,4,1,7,5,8,1,2,6,8,6,7,6,5,4,3,1,5,3,6,5,1,7,5,6,3,7,4,1,5,1,4,8,3,5,2,2,3,5,8,2,7,6,4,1,1,4,3,8,1,4,2,7,1,5,4,1,2,2,7,4,6,3,6,5,1,7,6,1,5,3,6,1,7,6,3,8,6,3,8,8,7,6,2,6,5,4,4,4,5,7,5,5,7,5,8,7,3,3,1,4,8,4,5,5,8,4,3,2,7,4,1,3,2,5,5,5,2,7,8,8,7,2,1,2,5,8,1,3,1,4,8,2,4,3,8,5,5,3,7,4,8,7,6,4,8,5,2,7,7,5,3,6,8,5,8,6,8,1,1,6,7,2,4,8,1,4,3,1,4,1,4,2,8,6,6,2,4,8,8,3,7,1,2,6,5,5,5,1,5,2,5,5,4,4,4,8,8,8,7,2,6,4,2,1,2,3,7,5,6,3,6,1,6,7,8,7,1,2,3,6,6,1,4,1,7,4,1,4,7,4,8,8,3,3,7,2,2,6,5,6,2,3,3,2,5,5,2,1,8,2,5,7,8,5,2,2,4,5,8,8,5,2,7,5,7,4,3,5,2,7,7,1,2,3,3,7,5,4,1,2,2,2,7,5,1,5,1,3,6,3,5,7,5,5,3,2,8,8,7,6,6,1,2,1,5,5,4,4,4,6,3,5,4,4,8,8,3,4,3,1,3,7,1,3,7,1,6,2,7,6,5,4,3,4,3,2,7,2,1,6,3,5,7,8,4,6,6,3,5,8,8,3,3,6,5,2,6,4,5,4,6,1,3,4,2,8,4,6,1,2,2,1,6,1,5,5,8,8,6,1,3,7,6,6,6,8,8,2,8,1,4,8,8,4,8,7,6,2,6,4,3,6,1,5,2,8,5,7,7,3,3,5,6,2,6,6,1,3,7,1,5,8,6,6,4,2,2,1,1,8,6,6,6,6,1,5,7,7,8,3,7,4,7,1,1,4,3,6,7,3,5,1,1,2,6,6,7,2,5,1,4,2,3,1,6,4,2,3,6,5,1,7,3,1,2,8,6,1,6,3,2,1,8,2,8,2,2,3,7,6,2,3,7,2,1,7,6,6,5,7,5,8,3,5,1,5,5,7,2,4,6,3,4,4,3,2,6,3,8,4,4,7,6,3,8,3,6,6,4,3,4,2,2,4,6,8,7,1,4,5,1,6,1,5,4,4,5,8,7,8,5,6,7,1,3,3,4,2,4,8,5,5,7,8,7,2,4,8,4,3,8,7,1,2,5,7,4,4,8,1,4,1,4,1,7,4,5,8,8,3,4,6,1,4,3,1,2,5,1,5,5,5,2,8,5,6,2,5,7,1,8,4,3,6,3,1,2,4,1,6,4,7,8,2,4,2,1,5,2,8,4,3,4,1,5,8,4,8,8,8,5,4,2,3,2,2,1,3,4,1,6,1,1,2,1,1,1,2,3,2,7,7,4,4,6,1,5,6,1,5,1,7,5,6,5,8,7,7,2,4,8,2,3,1,5,7,7,2,5,8,2,1,7,6,5,5,1,4,7,7,3,4,2,8,1,7,8,6,5,2,7,5,4,6,5,7,4,1,2,5,7,6,5,8,1,2,1,3,1,5,6,8,5,5,6,7,6,2,6,7,3,4,5,3,3,8,3,1,7,4,7,5,1,6,4,2,8,5,8,2,3,1,2,5,2,5,3,3,1,8,8,5,6,1,3,2,1,6,5,4,3,5,1,5,3,6,3,6,2,5,4,7,6,8,8,8,2,2,3,5,7,2,7,1,6,5,8,7,8,8,2,5,6,4,6,3,5,1,2,2,2,5,5,6,4,8,6,7,1,2,4,3,4,2,3,3,4,5,3,7,1,7,7,5,4,2,5,8,3,5,2,6,7,1,1,5,8,4,3,6,1,6,3,7,2,4,2,4,1,5,5,2,2,7,4,5,1,5,7,4,3,5,6,6,7,1,3,8,2,8,7,3,6,3,6,7,2,2,3,1,5,7,6,5,3,6,6,2,4,6,5,2,8,2,2,6,7,8,1,7,7,3,7,1,4,8,7,4,8,5,6,5,8,4,8,7,6,1,4,6,4,7,6,3,6,3,4,3,3,2,7,5,2,2,2,8,3,7,5,2,8,5,2,1,5,6,4,1,8,6,3,6,1,7,1,7,5,3,1,6,4,3,6,3,2,5,5,8,6,5,8,1,6,7,4,5,4,3,2,5,1,8,1,8,5,7,6,7,4,6,5,2,1,8,4,1,3,3,8,3,8,8,3,5,2,8,1,5,1,1,8,1,2,1,4,2,2,2,8,7,1,5,1,5,6,2,4,2,7,6,2,4,7,8,8,4,2,7,3,7,6,8,6,8,6,5,1,1,2,1,4,2,3,8,3,6,4,5,7,6,4,3,4,8,4,1,1,1,6,8,5,2,5,4,3,7,7,2,2,1,4,3,8,3,4,8,3,3,4,7,3,3,7,4,2,6,7,4,8,4,6,3,2,7,4,3,1,7,8,4,1,5,8,3,2,3,5,2,8,3,7,6,6,8,6,4,1,7,4,4,4,5,8,4,7,5,8,2,6,8,6,4,8,7,6,8,8,5,7,4,5,7,2,1,4,8,1,2,2,1,7,3,6,2,6,2,5,3,7,7,4,3,6,2,5,6,3,1,3,1,6,4,3,2,4,5,7,5,5,4,8,3,1,2,7,7,1,3,3,3,2,4,5,6,2,5,1,1,1,7,6,5,2,2,6,6,4,5,6,8,3,5,8,3,8,8,5,1,2,7,6,5,1,8,5,2,5,5,3,5,4,2,8,1,4,6,1,5,1,8,5,7,2,7,7,7,1,7,1,8,8,6,4,2,4,8,8,4,6,4,7,5,3,5,6,3,8,4,4,6,2,7,6,1,4,3,4,8,2,2,4,6,8,7,7,3,3,3,4,8,5,4,4,1,1,7,1,2,1,1,4,5,1,4,8,1,4,4,6,5,5,1,7,2,8,6,1,3,5,4,4,2,3,7,3,4,6,2,4,7,5,5,2,6,1,6,5,1,1,3,6,4,1,3,7,8,3,7,2,1,2,7,6,8,4,2,3,1,4,4,4,6,4,2,5,4,8,2,6,1,5,2,3,2,7,7,7,4,7,7,5,6,8,3,7,4,5,6,2,4,5,4,7,6,3,7,6,8,5,2,7,6,3,7,2,4,5,3,6,8,3,2,1,2,8,5,2,7,4,2,7,2,4,6,4,7,6,2,4,6,1,1,2,2,4,6,4,4,6,5,7,7,5,5,2,6,3,1,5,1,7,7,5,3,1,1,8,1,6,6,3,3,6,5,4,4,3,4,3,2,3,7,5,4,3,7,2,7,2,7,6,7,6,4,5,3,1,7,3,6,2,6,2,1,8,7,4,8,5,7,7,1,6,4,3,8,5,1,1,4,8,3,4,6,8,8,4,4,2,2,3,5,3,4,1,5,4,4,1,5,3,3,2,1,5,7,2,4,8,8,4,2,5,1,6,6,1,3,2,3,4,1,6,7,8,8,2,4,5,7,5,5,1,3,3,1,6,2,6,3,4,4,8,3,1,5,8,4,4,1,4,6,5,6,3,5,1,8,8,3,5,2,1,6,4,6,1,5,4,3,4,4,1,8,6,4,3,8,4,8,3,5,7,1,8,4,7,1,4,4,3,2,3,8,7,3,8,2,4,8,2,8,8,2,1,7,7,1,2,7,8,1,4,7,4,7,2,8,3,2,3,2,2,4,2,4,5,8,5,2,1,5,6,8,2,8,2,6,1,7,1,8,4,1,2,2,8,8,6,3,7,1,6,1,1,4,2,4,3,3,5,6,8,7,3,1,5,8,8,6,4,5,8,1,4,5,5,8,6,7,2,5,6,6,3,6,5,7,7,6,2,1,6,7,8,3,6,1,6,6,7,8,1,7,7,4,7,5,3,4,5,8,3,5,8,8,2,1,3,4,7,3,4,5,3,1,7,6,1,2,2,5,4,3,7,5,7,4,2,7,3,3,5,5,6,7,7,3,6,2,3,7,2,8,4,7,3,6,2,7,4,4,6,4,2,1,2,6,3,2,6,3,7,7,5,8,8,4,8,8,1,8,1,8,5,4,4,2,6,3,7,4,6,1,8,8,3,4,5,2,8,7,1,1,8,5,5,2,7,4,6,4,2,5,5,4,8,4,4,8,4,8,7,1,8,2,4,6,7,4,6,8,6,3,4,6,8,1,1,2,4,8,7,4,5,4,3,5,7,5,5,8,7,6,6,3,3,1,8,5,3,8,8,3,2,4,3,3,2,2,7,2,3,5,5,2,5,7,4,2,1,5,1,5,6,7,7,8,5,8,1,8,3,3,2,1,6,3,6,4,5,2,8,7,2,5,8,3,1,8,1,1,3,3,5,3,5,1,1,7,2,5,4,8,8,2,2,5,3,2,3,6,2,3,2,5,4,5,5,2,2,7,7,5,1,4,6,7,8,1,6,2,6,1,4,2,5,8,3,8,6,4,6,8,1,5,6,7,7,1,8,6,2,5,3,4,3,6,7,4,4,1,4,5,2,8,2,8,6,7,7,5,8,4,6,1,4,3,7,7,6,7,1,8,5,2,6,5,2,3,8,2,7,2,8,6,2,7,7,8,7,2,6,2,8,8,2,2,8,1,2,5,6,1,2,1,7,1,1,4,6,1,6,4,3,7,1,1,4,4,5,7,4,2,4,6,8,8,3,7,3,3,6,6,1,2,5,6,5,1,8,6,1,2,7,8,2,6,4,5,1,2,4,7,5,8,2,4,7,2,4,5,3,1,4,4,4,1,2,4,3,4,6,4,8,2,5,5,4,3,7,1,8,4,6,3,7,7,7,7,2,2,2,5,3,8,4,7,8,6,8,1,4,5,3,6,2,6,1,8,3,8,1,6,5,3,7,6,4,6,7,2,3,5,5,4,4,4,6,4,6,2,1,1,2,7,2,2,3,1,1,2,5,1,5,7,7,3,5,6,3,5,7,1,4,2,6,5,2,3,7,1,5,1,5,4,8,2,5,5,3,1,6,8,7,7,5,2,4,1,8,2,4,4,7,1,8,5,1,7,2,4,2,5,6,5,7,3,1,7,4,2,1,1,7,1,8,1,4,7,6,4,8,5,6,1,8,1,2,4,4,2,4,1,5,4,5,3,7,3,6,6,4,4,1,2,1,5,2,7,6,3,1,1,7,5,8,4,6,4,2,4,3,6,5,5,1,3,5,7,6,6,2,2,2,6,4,7,8,5,3,8,6,5,1,8,1,8,7,3,2,5,7,1,6,7,4,7,1,1,1,4,7,5,5,7,2,7,5,5,2,2,7,8,7,5,5,1,4,8,5,6,4,7,1,5,8,1,5,3,1,7,1,4,1,6,7,3,4,6,7,3,8,3,1,7,8,5,1,3,6,4,1,2,1,8,5,8,1,5,5,7,3,1,8,1,3,7,6,2,3,3,1,1,3,3,8,2,4,3,8,5,4,4,7,7,6,3,7,6,5,2,1,3,6,5,6,4,1,6,5,4,1,4,1,3,4,6,8,6,6,5,8,8,7,4,5,1,4,6,3,4,8,1,6,2,8,7,4,7,2,1,2,1,2,3,6,5,5,7,1,5,5,5,2,2,4,1,1,8,8,4,1,6,7,3,3,7,8,3,3,8,2,7,8,2,5,5,2,1,2,7,1,2,7,7,8,8,2,1,5,1,7,3,6,7,2,4,4,3,7,4,2,6,5,1,3,7,8,8,1,4,3,5,3,6,1,6,5,4,6,3,3,2,2,1,1,7,6,7,7,6,1,8,1,8,1,2,5,5,3,3,2,7,5,4,2,4,7,8,3,6,2,3,4,7,2,6,6,2,2,8,4,5,1,3,3,6,4,2,3,7,4,1,7,7,8,1,3,1,2,4,6,6,8,7,4,1,1,5,6,8,6,5,8,8,4,3,8,5,6,1,5,1,3,8,8,5,8,2,3,4,3,5,2,1,1,1,8,8,7,8,3,4,6,3,6,1,5,8,1,6,7,6,8,1,3,5,5,5,7,5,7,3,5,7,7,8,1,2,5,8,4,3,5,6,8,3,6,8,7,8,3,2,2,5,5,3,5,7,1,5,3,7,7,6,2,1,6,5,4,2,2,6,3,4,7,6,5,5,5,5,6,2,1,7,6,2,8,1,7,7,7,3,1,6,4,1,3,2,2,5,8,6,2,6,4,5,6,8,1,8,1,6,2,5,2,8,5,1,4,5,3,5,7,7,5,4,1,8,7,8,4,1,5,6,6,1,2,1,7,5,1,6,5,4,7,8,2,8,7,1,7,6,2,2,7,7,4,2,8,5,8,7,7,2,1,3,8,6,7,4,1,8,2,6,8,3,1,4,4,8,3,7,5,6,7,7,3,7,2,1,6,3,5,1,7,2,4,7,2,7,4,7,1,7,3,6,8,4,3,3,5,6,3,1,3,5,5,7,4,7,5,2,4,1,5,6,1,7,8,2,3,8,1,6,4,6,5,4,2,7,4,1,4,7,5,5,3,4,6,4,2,5,6,7,1,1,3,7,2,6,3,8,7,7,6,7,2,4,6,4,2,7,8,7,6,7,3,4,5,3,3,4,7,4,6,7,7,3,7,3,4,2,7,5,3,6,8,1,5,3,6,3,6,2,4,2,6,4,4,2,1,3,5,5,5,6,8,7,3,8,4,5,8,8,3,5,1,5,7,5,4,1,6,5,2,4,7,3,7,7,2,7,1,5,2,4,7,3,5,2,2,3,4,1,2,5,1,1,1,7,7,3,7,3,7,6,2,3,6,1,1,6,7,4,7,7,7,3,1,2,4,1,1,7,2,1,6,1,2,2,3,5,8,3,2,6,5,2,5,6,3,5,7,8,8,1,7,7,3,4,7,8,7,6,2,2,7,4,1,6,7,3,2,3,1,4,7,1,8,1,7,1,6,5,6,1,3,2,6,5,6,4,7,3,5,4,4,3,8,5,4,2,1,3,4,6,1,4,6,3,1,5,7,6,4,1,4,3,4,6,7,7,2,3,6,1,2,4,8,7,4,8,2,5,1,6,6,5,5,6,2,5,8,5,6,1,7,3,2,8,8,7,3,7,7,1,1,2,6,1,7,6,6,6,5,8,7,8,5,4,1,7,3,6,6,5,8,7,8,1,7,1,2,8,2,3,7,5,4,3,2,5,2,6,6,5,4,6,8,5,6,4,2,5,3,1,2,6,4,3,5,1,7,7,1,2,6,8,3,6,1,8,5,8,7,6,7,7,3,1,7,4,8,7,6,8,2,1,3,5,7,2,3,2,8,5,7,6,4,6,7,5,8,2,4,6,1,8,1,5,7,2,2,6,7,2,7,5,3,6,6,4,8,5,6,4,1,1,2,3,7,5,8,7,5,1,2,6,8,3,1,8,5,6,8,6,1,7,1,8,2,2,5,3,8,4,2,4,6,6,3,8,6,6,4,6,2,8,6,5,7,6,3,5,4,7,5,2,7,8,1,8,5,2,5,4,7,4,4,4,3,8,4,6,7,1,4,6,3,2,1,7,6,1,5,5,1,1,7,2,1,2,3,5,8,5,8,2,8,5,7,5,8,6,5,3,4,6,2,4,5,2,8,3,8,7,8,4,6,3,1,6,3,6,3,5,5,3,6,3,8,4,6,6,2,5,3,4,6,1,8,6,1,1,7,2,1,7,3,5,4,7,4,2,5,3,6,6,2,4,1,4,7,2,3,4,5,1,6,4,8,4,4,6,3,3,7,1,3,4,8,8,2,5,5,6,8,5,7,5,4,8,7,4,4,7,3,4,1,3,8,6,8,4,7,4,1,7,8,8,7,3,4,3,3,6,1,6,4,5,1,5,5,6,6,2,6,4,5,3,7,5,6,7,3,2,7,2,4,5,8,8,6,2,8,4,3,5,6,2,2,5,3,5,5,3,3,3,4,8,6,3,3,2,2,4,2,8,6,7,3,6,7,3,5,1,7,1,2,5,7,3,7,7,7,8,3,1,5,7,6,0,0,0,0,0,0,0,0};
    vector<int> dp(nums.size(),0);//用nums.size()个0初始化vector<int> dp;
    int length = nums.size();
    dp[0] = 1;

    for(int i = 1; i < length; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(dp[j] > 0 && i - j <= nums[j])
            {
                dp[i] = 1;
            }
        }
    }

    cout<<"nums: ";
    for(auto a: nums)
    {
        cout<<a<<" ";
    }
    cout<<endl<< "res is: "<<dp[length - 1]<<endl;
}
