/*
 *说明：本题是leetcode中的第26题
 *      Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 *      Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */

#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    int removeDuplicates(vector<int> & nums) 
    {
        if (nums.size() == 0)
            return 0;

        int i = 0, j = 1;
        for (; j < nums.size(); ++j)
        {
            if (nums[j] != nums[i])
            {
                nums[++i] = nums[j];      //把nums中后面没有进行判断的数据前面移动
            }
        }
        return i + 1;
    }
};

int main(void)
{
    vector<int> val{1,1,2,2,3};
    Solution so;

    int length = so.removeDuplicates(val);

    for (auto elem : val)
    {
        cout << elem << " ";
    }
    cout << endl << "length is " << length << endl;

    return 0;
}