/*
 *说明：本题是leetcode中的第27题
 *      Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 *      Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *      The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    int removeElement(vector<int> & nums, int val) 
    {
        if (nums.size() <= 0)
        {
            return nums.size();
        }

        int i = 0;
        for (; i < nums.size(); ++i)        //这里是为了找到第一个不等于val的值，便于后面的比较
            if (nums[i] != val)
                break;
        if (i == nums.size())
        {
            return 0;
        }   

        nums[0] = nums[i];
        int j;
        for (j = i + 1, i = 0; j < nums.size(); ++j)
        {
            if (nums[j] != val)
            {
                nums[++i] = nums[j];
            }
            cout << "i = " << i << endl;
        }
        //cout << i + 1 << "=====" << endl;
        return i + 1;
    }
};

int main(void)
{
    vector<int> val{0,1,2,2,3,0,4,2};
    Solution so;

    int length = so.removeElement(val, 2);
    for (auto elem : val)
    {
        cout << elem << " ";
    }
    cout << endl << "length is " << length << endl;

    return 0;
}