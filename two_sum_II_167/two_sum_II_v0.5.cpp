/*
 *描述：本题是leetcode中的第167题，是第一题的变种，也是关于两数之和的问题
 *问题：给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 *      函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 *说明:
 *      返回的下标值（index1 和 index2）不是从零开始的。
 *      你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 */

/*
 *解题思路：利用和第一题相同的思路，利用hash map将数组中的元素重新存储一遍，再在该map中查找符合条件的元素及下标
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;           //此数据结构利用的是hash来存储元素的，查找一个元素的时间复杂度为O(1)

class Solution 
{
public:
    vector<int> twoSum(vector<int> & numbers, int target) 
    {
        //建立hash map
        unordered_map<int, int> index_numbers;
        for (int i = 0; i < numbers.size(); ++i)
        {
            index_numbers[numbers[i]] = i;
        }

        for (int i = 0; i < numbers.size(); ++i)
        {
            auto iter = index_numbers.find(target - numbers[i]);
            if (iter != index_numbers.end() && iter->second != i)
                return vector<int>{i + 1, iter->second + 1};
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