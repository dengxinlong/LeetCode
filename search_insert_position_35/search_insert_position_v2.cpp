/*
 *说明：本题目是leetcode中的第35题
 *描述： Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *      You may assume no duplicates in the array.
 */

/*
 *思路：这里想到了一种思路，因为数组是有序的，所以可以采用二分查找法来完成，时间复杂度是o(logN)
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


class Solution 
{
public:
    int searchInsert(vector<int> & nums, int target) 
    {
        return search_position(nums, 0, nums.size() - 1, target);
    }
private:
    int search_position(vector<int> & nums, int low, int high, int target)
    {
        int position;
        if (high <= low)
        { 
            if (nums[low] < target)
                return low + 1;
            else 
                return low;
        }
        int mid = (low + high) >> 1;        //这里用右移 1 位来代替除 2 操作，效率更高
        //int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            position = mid;
        }
        else if (nums[mid] > target)
        {
            position = search_position(nums, low, mid - 1, target);
        }
        else if (nums[mid] < target)
        {
            position = search_position(nums, mid + 1, high, target);
        }
        return position;
    }
};

int main(void)
{
    Solution so;
    vector<int> val{1,3, 5, 6};

    int position = so.searchInsert(val, 2);
    cout << position << endl;

    return 0;
}