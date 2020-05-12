/*
 *说明：本题目是leetcode中的第35题
 *描述： Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *      You may assume no duplicates in the array.
 */

/*
 *思路：本题非常简单，没有什么特别的算法，遍历数组即可
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


// class Solution 
// {
// public:
//     int searchInsert(vector<int>& nums, int target) 
//     {
//         int i = 0;
//         for (; i < nums.size(); ++i)
//         {
//             if (nums[i] == target || nums[i] > target)
//             {
//                 return i;
//             }
//         }
//         return i;
//     }
// };


//二分查找一个元素
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (target > nums[nums.size() - 1])
            return nums.size();
        if (nums.size() < 0)
            return -1;
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else 
                high =  mid;
        }
        return low;
    }
};

int main(void)
{
    Solution so;
    vector<int> val{1, 2, 3, 4, 7};

    int position = so.searchInsert(val, 4);
    cout << position << endl;

    return 0;
}