/*
 *说明：本题是leetcode中第53题
 *描述：Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 */
/*
 *解题思路：本题的解题思路参考网上的解题思路
 *          使用的是动态规划的思想
 *          sum表示的是当前已经遍历到的元素的和，不包括当前元素，ans表示的是历史上的连续子序列的最大和
 *          根据题意，若sum > 0，表示的sum是有增益的，只不过不一定比ans大，但未来就可能比ans大；这时加上当前遍历到的元素，
 *          若sum < 0; 表示sum没有增益，直接舍弃，同时让 sum = 当前元素。最大值始终由 ans 来保证，sum负责往后面加就是
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    int maxSubArray(vector<int> & nums) 
    {
        int sum = 0, ans = nums[0];
        
        for (auto elem : nums)
        {
            if (sum > 0)
                sum += elem;
            else 
                sum = elem;
            
            ans = ans > sum ? ans : sum;
        }
        
        return ans;
    }
};


int main(void)
{
    vector<int> val{-2,1,-3,4,-1,2,1,-5,4};
    Solution so;
    
    int ret = so.maxSubArray(val);
    cout << ret << endl;

    return 0;
}