/**
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。


来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/**
 * 使用双指针的方法，从两头开始计算最大容积。
 * 将高度较小的一侧指针向内移动，再次计算容积，直到双指针交汇。
 * 过程中不断更新最大容积，最终返回。
 * area = min(height[right], height[left]) * (right - left);
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int area = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left < right)
        {
            // area = min(height[right], height[left]) * (right - left);
            if(height[right] < height[left])
            {
                area = height[right] * (right - left);
                right--;
            }
            else
            {
                area = height[left] * (right - left);
                left++;
            }

            if(area > max)
            {
                max = area;
            }
            
        }

        return max;
    }
};