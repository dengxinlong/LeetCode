/*
 *描述：本题是leetcode中的第167题，是第一题的变种，也是关于两数之和的问题
 *问题：给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 *      函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 *说明:
 *      返回的下标值（index1 和 index2）不是从零开始的。
 *      你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 */

/*
 *解题思路：本题相比较第一题，改变的就是本题中的输入数组是一个有序的数组，而第一题中的数组是一个无序的数组，因为是有序的数组，要使得时间复杂度比较低，
 *          就必须利用该数组的特性，从有序着手，
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution 
{
public:
    vector<int> twoSum(vector<int> & numbers, int target) 
    {
        for ( int i = 0, j = numbers.size() - 1; i < j; )
        {
            if (numbers[i] + numbers[j] == target)
                return vector<int>{i + 1, j + 1};
            else if (numbers[i] + numbers[j] > target)
                --j;
            else
                ++i;
        }
    }
};

int main(void)
{
    vector<int> vec{2, 7, 11, 15};
    Solution so;
    vector<int> ret = so.twoSum(vec, 9);
    for (auto elem : ret)
        cout << elem << " ";
    cout << endl;

    return 0;
}