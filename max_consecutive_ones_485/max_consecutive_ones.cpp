#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//解法一：直接遍历数组，就可以得出解，非常简单
// class Solution 
// {
// public:
//     int findMaxConsecutiveOnes(vector<int> & nums) 
//     {
//         int max_cnt = 0, cnt = 0;
//         for (auto elem : nums)
//         {
//             if (elem == 1)
//             {
//                 cnt++;
//                 max_cnt = cnt > max_cnt ? cnt : max_cnt;
//             }
//             else
//                 cnt = 0;
//         }
        
//         return max_cnt;
//     }
// };

//动态规划的思想
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> nums)
    {
        vector<int> dp;
        dp.reserve(nums.size());
        if (nums[0] == 1)
            dp.push_back(1);
        else
            dp.push_back(0);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                dp.push_back(dp[i - 1] + 1);
            else
                dp.push_back(0);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main(void)
{
    Solution so;
    vector<int> nums{1,1,0,1,1,1};
    cout << so.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}