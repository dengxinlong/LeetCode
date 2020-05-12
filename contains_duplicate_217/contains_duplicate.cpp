/*
 *描述：这题是leetcode中的第217题，仍然是关于数组的一道题目
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

//暴力破解，直接判断数组中每个元素在数组中是否存在重复元素
// class Solution 
// {
// public:
//     bool containsDuplicate(vector<int> & nums) 
//     {
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             for (int j = i + 1; j < nums.size(); ++j)
//             {
//                 if (nums[i] == nums[j])
//                     return true;
//             }
//         }
//         return false;
//     }
// };


//解法二：利用hash_map来进行求解，在上一个解法中，没有对中间的结果进行保存，导致需要多次遍历数组
//      时间复杂度为O(n), 空间复杂度为O(n)
// class Solution
// {
// public:
//     bool containsDuplicate(vector<int> & nums)
//     {
//         unordered_map<int, int> elem_cnt;
//         for (const auto & elem : nums)
//         {
//             elem_cnt[elem]++;
//             if (elem_cnt[elem] == 2)
//                 return true;
//         }
//         return false;
//     }
// };

//解法三：先排序，我们知道，相同的数据一定是相邻的，这时只需要遍历数组就可以了
// class Solution
// {
// public:
//     bool containsDuplicate(vector<int> & nums)
//     {
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size() - 1; ++i)
//         {
//             if (nums[i] == nums[i + 1])
//                 return true;
//         }
//         return false;
//     }
// };






int main(void)
{
    Solution so;
    vector<int> vec{1,2,3,1};
    cout << so.containsDuplicate(vec) << endl;

    return 0;
}