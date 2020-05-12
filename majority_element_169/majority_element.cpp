/*
 *说明：本题是leetcode中的第169题，仍然是数组相关的题目，这道题目是求众数
 *描述：给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 *      你可以假设数组是非空的，并且给定的数组总是存在众数。
 */



#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

/*
 *解法一： 暴力破解，直接排序，然后排序后的数组中的中间位置就是众数
 */
// class Solution 
// {
// public:
//     int majorityElement(vector<int> & nums) 
//     {
//         std::sort(nums.begin(), nums.end());
//         return nums[nums.size() / 2];
//     }
// };

//解法二：暴力破解，统计各个元素出现的次数，找出出现次数最大的元素，就是所求的众数

// class Solution
// {
// public:
//     int majorityElement(vector<int> & nums)
//     {
//         int max_cnt = 0, index = -1;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             int cnt = 1;
//             for (int j = 0; j < nums.size(); ++j)
//             {
//                 if (i != j && nums[i] == nums[j])
//                     cnt++;
//             }
//             if (cnt > max_cnt)
//             {
//                 max_cnt = cnt;
//                 index = i;
//             }   
//         }
//         return nums[index];
//     } 
// };

//解法三：通过一个hash_map来存储每个不同元素中出现的次数，这时利用了空间来降低前面统计出现次数的时间复杂度，
// class Solution
// {
// public:
//     int majorityElement(vector<int> & nums)
//     {
//         unordered_map<int, int> elem_cnt;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             elem_cnt[nums[i]]++;       //构建一个hash_map的时间复杂度为O(1)
//             if (elem_cnt[nums[i]] > nums.size() / 2)
//                 return nums[i];
//         }
//     }
// };

//解法四：解法四比较巧妙，利用了题目中的众数所出现的次数必须超过数组中总个数的一半，也就是众数出现的次数比所有其他元素出现的次数加起来还要多，我们可以利用这一点
//  `   我们直接遍历整个数组，如果假设我们要求的众数是val，则遇到val值，cnt++， 否则cnt--，则到我们遍历完整个数组，众数的cnt值必定大于0；直接看代码
class Solution
{
public:
    int majorityElement(vector<int> & nums)
    {
        int cnt = 1; 
        int max_cnt = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == max_cnt)
                cnt++;
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    max_cnt = nums[i];
                    cnt = 1;
                }    
            }
        }
        
        return max_cnt;
    }
};

int main(void)
{
    vector<int> vec{3, 2, 3};
    Solution so;
    int ret = so.majorityElement(vec);
    cout << ret << endl;

    return 0;
}