/**
 * @Title: 寻找峰值
 * @Author: C1ay
 * @Date: 2025-12-09 16:30
 * @Link: https://leetcode.cn/problems/find-peak-element/
 * @Tag: 二分查找
 */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class Solution
{
public:
    // 找到峰值元素并返回其索引
    int findPeakElement(const vector<int> &nums)
    {
        int n = nums.size();

        // 处理边界情况：如果数组只有一个元素，那么它就是峰值
        if (n == 1)
        {
            return 0;
        }

        // 处理边界情况：如果第一个元素大于第二个元素，则第一个元素是一个峰值
        if (nums[0] > nums[1])
        {
            return 0;
        }

        // 处理边界情况：如果最后一个元素大于倒数第二个元素，则最后一个元素是一个峰值
        if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }

        // 定义搜索范围为第二个元素到倒数第二个元素
        int l = 1, r = n - 2;
        // 中间索引和返回答案的变量
        int m = 0;

        // 使用二分查找寻找峰值
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1])
            {
                l = m+ 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};
